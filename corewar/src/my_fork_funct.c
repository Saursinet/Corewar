/*
** my_fork_funct.c for corewar in /home/saursf/rendu/CPE_2014_corewar/vm/src
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Wed Apr  8 11:02:57 2015 Florian Saurs
** Last update Thu Apr 16 02:13:50 2015 Florian Saurs
*/

#include "types.h"

int		my_neg_value(int i)
{
  while (i < 0)
    i += MEM_SIZE;
  if (i > 0)
    i %= MEM_SIZE;
  return (i);
}

void		my_cpy_registry(t_champ *champion, int registry[16])
{
  int		i;

  i = 0;
  while (i < 16)
    {
      champion->registry[i] = registry[i];
      ++i;
    }
}

int		do_fork(t_mem *arena, int i, t_champ *champion)
{
  t_champ	*new_champ;
  static	int fork = -1;

  if (++fork < 1000)
    {
      champion->cycles_to_next = 800;
      ((new_champ = malloc(sizeof(*champion))) == NULL) ?
	exit(ERROR_MALLOC) : (void)0;
      new_champ->player_id = champion->player_id;
      new_champ->name = champion->name;
      new_champ->PC = champion->PC + (my_decal_of_two(arena, i + 1) % IDX_MOD);
      new_champ->PC = my_neg_value(new_champ->PC);
      arena[new_champ->PC].head = 1;
      new_champ->carry = champion->carry;
      new_champ->alive = champion->alive;
      new_champ->dead = champion->dead;
      new_champ->has_lived = champion->has_lived;
      new_champ->last_result = champion->last_result;
      new_champ->cycles_to_next = champion->cycles_to_next;
      my_cpy_registry(new_champ, champion->registry);
      new_champ->next = champion->next;
      new_champ->prev = champion;
      champion->next = new_champ;
    }
  return (3);
}

int		do_lfork(t_mem *arena, int i, t_champ *champion)
{
  t_champ	*new_champ;
  static	int fork = -1;

  if (++fork < 1000)
    {
      champion->cycles_to_next = 1000;
      ((new_champ = malloc(sizeof(*champion))) == NULL) ?
	exit(ERROR_MALLOC) : (void)0;
      new_champ->player_id = champion->player_id;
      new_champ->name = champion->name;
      new_champ->PC = champion->PC + my_decal_of_two(arena, i + 1);
      new_champ->PC = my_neg_value(new_champ->PC);
      arena[new_champ->PC].head = 1;
      new_champ->carry = champion->carry;
      new_champ->alive = champion->alive;
      new_champ->dead = champion->dead;
      new_champ->has_lived = champion->has_lived;
      new_champ->last_result = champion->last_result;
      new_champ->cycles_to_next = champion->cycles_to_next;
      my_cpy_registry(new_champ, champion->registry);
      new_champ->next = champion->next;
      new_champ->prev = champion;
      champion->next = new_champ;
    }
  return (3);
}
