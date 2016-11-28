/*
** init_all.c for corewar in /home/saursf/rendu/CPE_2014_corewar/vm/src
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Wed Apr  8 11:21:32 2015 Florian Saurs
** Last update Thu Apr 16 01:07:42 2015 Florian Saurs
*/

#include "types.h"

void		clear_arena(t_mem *arena)
{
  int		i;

  i = -1;
  while (++i < MEM_SIZE)
    {
      arena[i].player_id = 0;
      arena[i].cmd = 0;
      arena[i].head = 0;
    }
}

void		fill_champ_registry(t_champ *champion)
{
  champion->registry[0] = champion->player_id;
  champion->registry[1] = 0;
  champion->registry[2] = 0;
  champion->registry[3] = 0;
  champion->registry[4] = 0;
  champion->registry[5] = 0;
  champion->registry[6] = 0;
  champion->registry[7] = 0;
  champion->registry[8] = 0;
  champion->registry[9] = 0;
  champion->registry[10] = 0;
  champion->registry[11] = 0;
  champion->registry[12] = 0;
  champion->registry[13] = 0;
  champion->registry[14] = 0;
  champion->registry[15] = 0;
}

t_champ		*prepare_first_champion(int id, int pc, char *name)
{
  t_champ	*champion;

  ((champion = malloc(sizeof(*champion))) == NULL) ?
    exit(ERROR_MALLOC) : (void)0;
  champion->player_id = id;
  champion->name = name;
  champion->PC = pc;
  champion->carry = 1;
  champion->alive = 1;
  champion->dead = 0;
  champion->has_lived = 1;
  champion->last_result = -1;
  champion->cycles_to_next = 0;
  fill_champ_registry(champion);
  champion->next = NULL;
  champion->prev = NULL;
  return (champion);
}

t_champ		*prepare_champion(int id, int pc, char *name, t_champ *champ)
{
  t_champ	*champion;

  ((champion = malloc(sizeof(*champion))) == NULL) ?
    exit(ERROR_MALLOC) : (void)0;
  champion->player_id = id;
  champion->name = name;
  champion->PC = pc;
  champion->carry = 1;
  champion->alive = 1;
  champion->dead = 0;
  champion->has_lived = 1;
  champion->last_result = -1;
  champion->cycles_to_next = 0;
  fill_champ_registry(champion);
  champion->next = NULL;
  champion->prev = champ;
  champ->next = champion;
  return (champ->next);
}
