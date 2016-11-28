/*
** game.c for  in /home/veyrie_f/rendu/CPE_2014_corewar
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat Mar 21 14:54:38 2015 fernand veyrier
** Last update Thu Apr 16 19:16:50 2015 Florian Saurs
*/

#include "types.h"

int		my_alive_champ(t_game *game, t_win *champ, int alive, int i)
{
  if (game->champ_alive[i][1] > 0)
    {
      while (champ->champion && champ->champion->player_id !=
	     game->champ_alive[i][0])
	champ->champion = champ->champion->next;
      print_champ(champ->champion, 1);
      ++alive;
      game->champ_alive[i][1] = 0;
    }
  else
    {
      game->champ_alive[i][1] = -1;
      while (champ->champion && champ->champion->player_id !=
	     game->champ_alive[i][0])
	champ->champion = champ->champion->next;
      champ->champion->dead = 1;
      print_champ(champ->champion, 2);
    }
  return (alive);
}

int		champion_alive(t_win *champ, int tmp, int nbr_live,
			       t_game *game)
{
  static int	total_cycle = 0;
  int		i;
  int		alive;

  i = -1;
  alive = 0;
  total_cycle = total_cycle + tmp;
  if (nbr_live >= 40)
    tmp -= CYCLE_DELTA;
  while (game->champ_alive[++i][0] != -2)
    {
      champ->champion = champ->first_champ;
      alive = my_alive_champ(game, champ, alive, i);
    }
  return (finito(game, champ, tmp, alive));
}

void		my_exec_funct(t_champ *champion, t_game *game, t_mem *arena)
{
  arena[champion->PC].head = 0;
  if (game->j == 0)
    champion->PC = (champion->PC + game->func[game->j]
					 (arena, champion,
					  &(game->nbr_live), game)) % MEM_SIZE;
  else
    champion->PC = (champion->PC + (game->func[game->j]
				    (arena, champion->PC,
				     champion)) % MEM_SIZE);
  arena[champion->PC].head = champion->player_id;
}

void		game_play(t_mem *arena, t_champ *champion, t_game *game)
{
  while (champion != NULL)
    {
      if (champion->dead == 0)
	{
	  game->j = 0;
	  if (champion->PC >= MEM_SIZE)
	    champion->PC = 0;
	  if (champion->PC < 0)
	    champion->PC = champion->PC % MEM_SIZE + MEM_SIZE;
	  while (game->j < 16 && arena[champion->PC].cmd != game->cmd[game->j])
	    ++game->j;
	  if (game->j != 16 && champion->cycles_to_next <= 0)
	    my_exec_funct(champion, game, arena);
	  if (game->j == 16 && champion->cycles_to_next <= 0)
	    champion->PC = (champion->PC + 1) % MEM_SIZE;
	  --champion->cycles_to_next;
	}
      champion = champion->next;
    }
  champion = game->first_champ;
  ++game->my_turn;
  ++game->nb_turn;
}

void		start_game(t_mem *arena, t_champ *champion, int rounds_left,
			   t_game game)
{
  t_win		champ;

  game.nb_turn = 0;
  game.i = 0;
  game.nbr_live = 0;
  game.first_champ = champion;
  init_cmd(game.cmd);
  init_func(game.func);
  champ.champion = champion;
  champ.first_champ = game.first_champ;
  game.cycle_todie = CYCLE_TO_DIE;
  while ((game.cycle_todie = champion_alive(&champ, game.cycle_todie,
					    game.nbr_live, &game)) > 0)
    {
      champion = game.first_champ;
      game.my_turn = 0;
      while (game.my_turn < game.cycle_todie)
	{
	  if (game.nb_turn == rounds_left)
	    print_memory(arena, "0123456789ABCDEF");
	  game_play(arena, champion, &game);
	}
      printf("game.cycle_todie %d\n", game.cycle_todie);
      ++game.i;
    }
}
