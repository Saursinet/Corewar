/*
** my_ld_funct.c for corewar in /home/saursf/rendu/CPE_2014_corewar/vm/src
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Mon Mar 23 17:34:48 2015 Florian Saurs
** Last update Thu Apr 16 23:32:57 2015 fernand veyrier
*/

#include "types.h"

int		my_lld(t_mem *arena, int i, t_champ *champion, char cmd[8])
{
  int		ret;

  ret = 0;
  if (cmd[7] == 1 && cmd[6] == 0)
    {
      champion->registry[tern((int)arena[(i + 6) % MEM_SIZE].cmd)] =
	my_decal_of_four(arena, i + 2);
      (champion->registry[tern((int)arena[(i + 6) % MEM_SIZE].cmd)] == 0 ?
       (champion->carry = 1) : (champion->carry = 0));
      ret += 4;
    }
  else if (cmd[7] == 1 && cmd[6] == 1)
    {
      champion->registry[tern((int)arena[(i + 4) % MEM_SIZE].cmd)] =
	my_decal_of_two(arena, i + 2);
      (champion->registry[tern((int)arena[(i + 4) % MEM_SIZE].cmd)]  == 0 ?
       (champion->carry = 1) : (champion->carry = 0));
      ret += 2;
    }
  return (ret);
}

int		do_lld(t_mem *arena, int i, t_champ *champion)
{
  int		ret;
  char		cmd[8];
  int		c;

  c = 0;
  while (c < 8)
    {
      cmd[c] = (arena[(i + 1) % MEM_SIZE].cmd >> c) % 2;
      ++c;
    }
  ret = 0;
  if (cmd[5] == 0 && cmd[4] == 1)
    ret = my_lld(arena, i, champion, cmd);
  champion->cycles_to_next = 5;
  return (ret + 2);
}
