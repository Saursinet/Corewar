/*
** my_ldi_funct.c for corewar in /home/saursf/rendu/CPE_2014_corewar/vm
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Sat Apr 11 18:59:05 2015 Florian Saurs
** Last update Thu Apr 16 23:36:42 2015 fernand veyrier
*/

#include "types.h"

void		init_my_decal(t_decal *par)
{
  int		i;

  i = -1;
  par->ret = 0;
  par->my_reg = 0;
  par->my_reg2 = 0;
  while (++i < 8)
    par->cmd[i] = 0;
  par->decal = 0;
}

int		do_ldi(t_mem *arena, int i, t_champ *champion)
{
  t_decal	pa;
  int		S;
  int		c;

  init_my_decal(&pa);
  c = 0;
  while (c < 8)
    {
      pa.cmd[c] = (arena[(i + 1) % MEM_SIZE].cmd >> c) % 2;
      ++c;
    }
  pa.ret = 0;
  S = 0;
  if (pa.cmd[3] == 0 && pa.cmd[2] == 1)
    {
      my_parameters(arena, i, champion, &pa);
      S = pa.my_reg + pa.my_reg2;
      champion->registry[tern((int)arena[(i + 2 + pa.decal) % MEM_SIZE].cmd)] =
	i + (S % IDX_MOD);
    }
  (champion->registry[tern((int)arena[(i + 2 + pa.decal) % MEM_SIZE].cmd)] ==
   0 ? (champion->carry = 1) : (champion->carry = 0));
  champion->cycles_to_next = 25;
  return (pa.ret + 3);
}

void		my_param_ld(t_mem *arena, int i, t_champ *champion,
			    t_decal *par)
{
  if (par->cmd[7] == 0 && par->cmd[6] == 1)
    {
      par->my_reg = champion->registry[tern((int)arena[(i + 2) %
						       MEM_SIZE].cmd)];
      par->decal = 1;
      par->ret += 1;
    }
  else if (par->cmd[7] == 1 && (par->cmd[6] == 1 || par->cmd[6] == 0))
    {
      if (par->cmd[7] == 1 && par->cmd[6] == 0)
	par->my_reg = i + my_decal_of_two(arena, i + 2);
      else
	par->my_reg = my_decal_of_two(arena, i + 2);
      par->decal = 2;
      par->ret += 2;
    }
  else if (par->cmd[7] == 1 && par->cmd[6] == 0)
    {
      par->my_reg = my_decal_of_four(arena, i + 2);
      par->decal = 4;
      par->ret += 4;
    }
  my_param_next(arena, i, champion, par);
}

int		do_lldi(t_mem *arena, int i, t_champ *champion)
{
  t_decal	par;
  int		S;
  int		c;

  init_my_decal(&par);
  c = 0;
  while (c < 8)
    {
      par.cmd[c] = (arena[(i + 1) % MEM_SIZE].cmd >> c) % 2;
      ++c;
    }
  par.ret = 0;
  if (par.cmd[3] == 0 && par.cmd[2] == 1)
    {
      my_param_ld(arena, i, champion, &par);
      S = i + par.my_reg + par.my_reg2;
      champion->registry[tern((int)arena[(i + 2 + par.decal) % MEM_SIZE].cmd)]
	= i + S;
    }
  (champion->registry[tern((int)arena[(i + 2 + par.decal) % MEM_SIZE].cmd)] ==
   0 ? (champion->carry = 1) : (champion->carry = 0));
  champion->cycles_to_next = 50;
  return (par.ret + 2);
}
