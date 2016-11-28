/*
** my_st_funct.c for corewar in /home/saursf/rendu/CPE_2014_corewar/vm/src
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Mon Mar 23 17:18:37 2015 Florian Saurs
** Last update Thu Apr 16 00:07:00 2015 Florian Saurs
*/

#include "types.h"

int		my_st(t_mem *arena, int i, t_champ *champion)
{
  int		c;
  int		pos;

  pos = my_decal_of_two(arena, i + 3) % MEM_SIZE;
  pos += i;
  while (pos < 0)
    pos = MEM_SIZE + pos;
  c = champion->registry[tern((int)arena[(i + 2) % MEM_SIZE].cmd)];
  arena[pos % MEM_SIZE].cmd = c >> 24;
  arena[pos % MEM_SIZE].player_id = champion->player_id;
  c = c << 8;
  c = c >> 8;
  arena[(pos + 1) % MEM_SIZE].cmd = c >> 16;
  arena[(pos + 1) %
	MEM_SIZE].player_id = champion->player_id;
  c = c << 16;
  c = c >> 16;
  arena[(pos + 2) % MEM_SIZE].cmd = c >> 8;
  arena[(pos + 2) %	MEM_SIZE].player_id = champion->player_id;
  c = c << 24;
  c = c >> 24;
  arena[(pos + 3) % MEM_SIZE].cmd = c;
  arena[(pos + 3) % MEM_SIZE].player_id = champion->player_id;
  return (5);
}

int		do_st(t_mem *arena, int i, t_champ *champion)
{
  int		ret;
  char		cmd[8];
  int		c;

  c = -1;
  while (++c < 8)
    cmd[c] = (arena[(i + 1) % MEM_SIZE].cmd >> c) % 2;
  ret = 0;
  if (cmd[7] == 0 && cmd[6] == 1)
    {
      if (cmd[5] == 0 && cmd[4] == 1)
	{
	  if (champion->player_id == 1)
	  champion->registry[tern((int)arena[(i + 3) % MEM_SIZE].cmd)] =
	    champion->registry[tern((int)arena[(i + 2) % MEM_SIZE].cmd)];
	  ret += 4;
	}
      else if (cmd[5] == 1 && cmd[4] == 1)
	ret = my_st(arena, i, champion);
    }
  champion->cycles_to_next = 5;
  return (ret);
}
