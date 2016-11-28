/*
** operate_funct.c for corewar in /home/saursf/rendu/CPE_2014_corewar/vm/src
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Mon Mar 23 17:30:38 2015 Florian Saurs
** Last update Tue Apr 14 16:31:07 2015 Florian Saurs
*/

#include "types.h"

int		do_add(t_mem *arena, int i, t_champ *champion)
{
  char		cmd[8];
  int		c;

  c = 0;
  while (c < 8)
    {
      cmd[c] = (arena[(i + 1) % MEM_SIZE].cmd >> c) % 2;
      ++c;
    }
  if  (cmd[7] == 0 && cmd[6] == 1 &&
       cmd[5] == 0 && cmd[4] == 1 &&
       cmd[3] == 0 && cmd[2] == 1)
    {
      champion->registry[tern(((int)arena[(i + 4) % MEM_SIZE].cmd))] =
	champion->registry[tern((int)arena[(i + 2) % MEM_SIZE].cmd)]
	+ champion->registry[tern((int)arena[(i + 3) % MEM_SIZE].cmd)];
      ((champion->registry[tern((int)arena[(i + 4) % MEM_SIZE].cmd)]) == 0 ?
       (champion->carry = 1) : (champion->carry = 0));
    }
  champion->cycles_to_next = 10;
  return (5);
}

int		do_sub(t_mem *arena, int i, t_champ *champion)
{
  char		cmd[8];
  int		c;

  c = 0;
  while (c < 8)
    {
      cmd[c] = (arena[(i + 1) % MEM_SIZE].cmd >> c) % 2;
      ++c;
    }
  if  (cmd[7] == 0 && cmd[6] == 1 &&
       cmd[5] == 0 && cmd[4] == 1 &&
       cmd[3] == 0 && cmd[2] == 1)
    {
      champion->registry[tern((int)arena[(i + 4) % MEM_SIZE].cmd)] =
	champion->registry[tern((int)arena[(i + 2) % MEM_SIZE].cmd)] -
	champion->registry[tern((int)arena[(i + 3) % MEM_SIZE].cmd)];
      ((champion->registry[tern((int)arena[(i + 4) % MEM_SIZE].cmd)]) == 0 ?
       (champion->carry = 1) : (champion->carry = 0));
    }
  champion->cycles_to_next = 10;
  return (5);
}

int		do_and(t_mem *arena, int i, t_champ *champion)
{
  t_decal	par;
  int		c;

  c = 0;
  init_my_decal(&par);
  while (c < 8)
    {
      par.cmd[c] = (arena[(i + 1) % MEM_SIZE].cmd >> c) % 2;
      ++c;
    }
  par.ret = 0;
  if (par.cmd[3] == 0 && par.cmd[2] == 1)
    {
      my_param(arena, i, champion, &par);
      champion->registry[tern((int)arena[(i + 2 + par.ret) % MEM_SIZE].cmd)] =
	par.my_reg & par.my_reg2;
      (champion->registry[tern((int)arena[(i + 2 + par.ret) % MEM_SIZE].cmd)]
       == 0 ? (champion->carry = 1) : (champion->carry = 0));
    }
  champion->cycles_to_next = 6;
  return (par.ret + 3);
}

int		do_or(t_mem *arena, int i, t_champ *champion)
{
  t_decal	par;
  int		c;

  c = 0;
  init_my_decal(&par);
  while (c < 8)
    {
      par.cmd[c] = (arena[(i + 1) % MEM_SIZE].cmd >> c) % 2;
      ++c;
    }
  par.ret = 0;
  if (par.cmd[3] == 0 && par.cmd[2] == 1)
    {
      my_param(arena, i, champion, &par);
      champion->registry[tern((int)arena[(i + 2 + par.ret) % MEM_SIZE].cmd)] =
	par.my_reg | par.my_reg2;
      (champion->registry[tern((int)arena[(i + 2 + par.ret) % MEM_SIZE].cmd)]
       == 0 ? (champion->carry = 1) : (champion->carry = 0));
    }
  champion->cycles_to_next = 6;
  return (par.ret + 3);
}

int		do_xor(t_mem *arena, int i, t_champ *champion)
{
  t_decal	par;
  int		c;

  c = 0;
  init_my_decal(&par);
  while (c < 8)
    {
      par.cmd[c] = (arena[(i + 1) % MEM_SIZE].cmd >> c) % 2;
      ++c;
    }
  par.ret = 0;
  if (par.cmd[3] == 0 && par.cmd[2] == 1)
    {
      my_param(arena, i, champion, &par);
      champion->registry[tern((int)arena[(i + 2 + par.ret) % MEM_SIZE].cmd)] =
	par.my_reg ^ par.my_reg2;
      (champion->registry[tern((int)arena[(i + 2 + par.ret) % MEM_SIZE].cmd)]
       == 0 ? (champion->carry = 1) : (champion->carry = 0));
    }
  champion->cycles_to_next = 6;
  return (par.ret + 3);
}
