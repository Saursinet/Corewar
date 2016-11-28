/*
** delegate.c for  in /home/veyrie_f/rendu/CPE_2014_corewar/Bonus
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Thu Apr 16 22:52:41 2015 fernand veyrier
** Last update Thu Apr 16 22:55:02 2015 fernand veyrier
*/

#include "corewar_GL.h"

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

void		game_begins(t_game *game, t_champ *champion,
			    t_win *champ, t_sound sound)
{
  game->nb_turn = 0;
  game->i = 0;
  game->nbr_live = 0;
  game->first_champ = champion;
  init_cmd(game->cmd);
  init_func(game->func);
  champ->champion = champion;
  champ->first_champ = game->first_champ;
  game->cycle_todie = CYCLE_TO_DIE;
  play_sound(sound.play);
}

void		refresh_buffer(int option, t_aff *aff)
{
  if (option == 1)
    {
      (aff->game_over == 0) ? aff->game_over = 1 : 0;
    }
  glFlush();
  SDL_GL_SwapBuffers();
}
