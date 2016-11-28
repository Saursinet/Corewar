/*
** hadle_champs.c for  in /home/veyrie_f/rendu/CPE_2014_corewar/src
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Wed Mar 18 19:08:04 2015 fernand veyrier
** Last update Thu Apr 16 23:02:44 2015 fernand veyrier
*/

#include "corewar_GL.h"

int		get_champ_size(t_list *list, int champ_count)
{
  int		size;
  int		sum_size;

  sum_size = 0;
  sum_size += list->prog_size;
  list = list->next;
  while (list->cmpt != 0)
    {
      sum_size += list->prog_size;
      list = list->next;
    }
  size = (MEM_SIZE - sum_size) / champ_count;
  return (size);
}

void		take_champ(t_list *list, t_init *init)
{
  if (init->c == 0)
    {
      init->champion =
	prepare_first_champion((list->num_prog < 0 ? init->count :
				list->num_prog),
			       init->i, list->prog_name);
      init->arena[init->i].head = 1;
      init->first_champ = init->champion;
      ++init->c;
    }
  else
    {
      init->champion =
	prepare_champion((list->num_prog < 0 ? init->count : list->num_prog),
			 init->i, list->prog_name, init->champion);
      init->arena[init->i].head = 1;
    }
}

void		take_in_arena(t_list *list, t_init *init)
{
  take_champ(list, init);
  while (++init->j < list->prog_size)
    {
      if (init->arena[init->i].player_id != 0)
	exit(my_puterror("Invalid -a value.\n"));
      init->i %= MEM_SIZE;
      init->arena[init->i].player_id = init->count;
      init->arena[init->i++].cmd = list->prog_data[init->j];
    }
  init->j = -1;
  while (++init->j < init->gap)
    ++init->i;
  init->i %= MEM_SIZE;
}

void		init_struct(t_init *init, t_game *game)
{
  init->champion = init->first_champ;
  (game->champ_alive = malloc((init->end + 1) * sizeof(int *))) == NULL ?
    exit(ERROR_MALLOC) : (void)0;
  init->i = 0;
  while (init->champion)
    {
      (game->champ_alive[init->i] = malloc(2 * sizeof(int))) == NULL ?
	exit(ERROR_MALLOC) : (void)0;
      game->champ_alive[init->i][0] = init->champion->player_id;
      game->champ_alive[init->i][1] = 1;
      init->champion = init->champion->next;
      ++init->i;
    }
  (game->champ_alive[init->i] = malloc(sizeof(int))) == NULL ?
    exit(ERROR_MALLOC) : (void)0;
  game->champ_alive[init->i][0] = -2;

}

void		create_arena(t_list *list, unused int nbr_cycle, t_sound sounds)
{
  t_init	init;
  t_game	game;

  init.i = (list->num_addr <= 0) ? 0 : list->num_addr % MEM_SIZE;
  init.c = 0;
  init.j = -1;
  init.count = 0;
  init.end = list->prev->cmpt + 1;
  init.first_champ = NULL;
  ((init.arena = malloc(sizeof(t_mem) * MEM_SIZE)) == NULL) ?
    exit(ERROR_MALLOC) : (void)0;
  init.champion = NULL;
  clear_arena(init.arena);
  init.gap = get_champ_size(list, init.end);
  while (++init.count <= init.end)
    {
      take_in_arena(list, &init);
      list = list->next;
      init.i = (list->num_addr <= 0) ? init.i : list->num_addr % MEM_SIZE;
      init.j = -1;
    }
  init_struct(&init, &game);
  start_game(init.arena, init.first_champ, game, sounds);
}
