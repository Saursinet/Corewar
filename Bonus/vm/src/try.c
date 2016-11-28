/*
** try.c for corewar in /home/saursf/rendu/CPE_2014_corewar/corewar
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Mon Apr 13 17:20:31 2015 Florian Saurs
** Last update Thu Apr 16 13:45:00 2015 fernand veyrier
*/

#include "types.h"

int		my_decal_of_two(t_mem *arena, int i)
{
  int		jump;
  char		cmd[8];
  int		c;

  c = 0;
  jump = 0;
  while (jump < 8)
    {
      cmd[c] = (arena[i % MEM_SIZE].cmd >> jump++) % 2;
      ++c;
    }
  jump = 0;
  jump =
    ((arena[i % MEM_SIZE].cmd) << 8) + arena[(i + 1) % MEM_SIZE].cmd;
  if (cmd[7] == 1)
    return (-(65536 - jump));
  return (jump);
}

int		my_decal_of_four(t_mem *arena, int i)
{
  int		jump;
  char		cmd[8];
  int		c;

  c = -1;
  jump = 0;
  while (++c < 8)
    cmd[c] = (arena[(i) % MEM_SIZE].cmd >> c) % 2;
  jump = 0;
  jump = (arena[i % MEM_SIZE].cmd << 24)
    + (arena[(i + 1) % MEM_SIZE].cmd << 16)
    + (arena[(i + 2) % MEM_SIZE].cmd << 8)
    + arena[(i + 3) % MEM_SIZE].cmd;
  if (cmd[7] == 1)
    return (-(4294967295 - jump));
  return (jump);
}

int		my_decal_of_two_idx(t_mem *arena, int i)
{
  int		jump;
  char		cmd[8];
  int		c;

  c = 0;
  jump = 0;
  while (jump < 8)
    {
      cmd[c] = (arena[i % MEM_SIZE].cmd >> jump++) % 2;
      ++c;
    }
  jump = 0;
  jump =
    ((arena[i % MEM_SIZE].cmd) << 8) + arena[(i + 1) % MEM_SIZE].cmd;
  if (cmd[7] == 1)
    return (i + (-(65536 - jump)) % IDX_MOD);
  return (i + (jump % IDX_MOD));
}

int		my_decal_of_four_idx(t_mem *arena, int i)
{
  int		jump;
  char		cmd[8];
  int		c;

  c = -1;
  jump = 0;
  while (++c < 8)
    cmd[c] = (arena[(i) % MEM_SIZE].cmd >> c) % 2;
  jump = 0;
  jump = (arena[i % MEM_SIZE].cmd << 24)
    + (arena[(i + 1) % MEM_SIZE].cmd << 16)
    + (arena[(i + 2) % MEM_SIZE].cmd << 8)
    + arena[(i + 3) % MEM_SIZE].cmd;
  c = 0;
  jump = my_neg_value(jump);
  c = (arena[(jump + i - 2) % MEM_SIZE].cmd << 24)
    + (arena[(jump + i - 2 + 1) % MEM_SIZE].cmd << 16)
    + (arena[(jump + i - 2 + 2) % MEM_SIZE].cmd << 8)
    + arena[(jump + i - 2 + 3) % MEM_SIZE].cmd;
  if (cmd[7] == 1)
    return (-(4294967295 - c) % IDX_MOD);
  return (c % IDX_MOD);
}
