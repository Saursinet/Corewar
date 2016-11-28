/*
** my_lld_funct.c for corewar in /home/saursf/rendu/CPE_2014_corewar/vm
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Sat Apr 11 20:08:39 2015 Florian Saurs
** Last update Thu Apr 16 23:37:23 2015 fernand veyrier
*/

#include "types.h"

void		other_param(t_mem *arena, int i, t_champ *champion,
			      t_decal *par)
{
  if (par->cmd[5] == 0 && par->cmd[4] == 1)
    {
      par->my_reg2 = champion->registry[tern((int)arena[(i + 2 + par->decal) %
							MEM_SIZE].cmd)];
      par->decal += 1;
      par->ret += 1;
    }
  else if (par->cmd[7] == 1 && (par->cmd[6] == 1 || par->cmd[6] == 0))
    {
      par->my_reg2 = my_decal_of_two(arena, i + 2 + par->decal);
      par->decal += 2;
      par->ret += 2;
    }
}

void		my_parameters(t_mem *arena, int i, t_champ *champion,
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
	par->my_reg = i + (my_decal_of_two(arena, i + 2) % IDX_MOD);
      else
	par->my_reg = my_decal_of_two(arena, i + 2);
      par->decal = 2;
      par->ret += 2;
    }
  other_param(arena, i, champion, par);
}

int		my_ld(t_mem *arena, int i, t_champ *champion, char cmd[8])
{
  int		ret;

  ret = 0;
  if (cmd[7] == 1 && cmd[6] == 0)
    {
      champion->registry[tern((int)arena[(i + 6) % MEM_SIZE].cmd)] =
	my_decal_of_four_idx(arena, i + 2);
      (champion->registry[tern((int)arena[(i + 6) % MEM_SIZE].cmd)] == 0 ?
       (champion->carry = 1) : (champion->carry = 0));
      ret += 4;
    }
  else if (cmd[7] == 1 && cmd[6] == 1)
    {
      champion->registry[tern((int)arena[(i + 4) % MEM_SIZE].cmd)] =
	(my_decal_of_two(arena, i + 2) % IDX_MOD);
      (champion->registry[tern((int)arena[(i + 4) % MEM_SIZE].cmd)] == 0 ?
       (champion->carry = 1) : (champion->carry = 0));
      ret += 2;
    }
  return (ret);
}

int		do_ld(t_mem *arena, int i, t_champ *champion)
{
  int		ret;
  char		cmd[8];
  int		c;

  c = 0;
  ret = 0;
  while (c < 8)
    {
      cmd[c] = (arena[(i + 1) % MEM_SIZE].cmd >> c) % 2;
      ++c;
    }
  if (cmd[5] == 0 && cmd[4] == 1)
    ret = my_ld(arena, i, champion, cmd);
  champion->cycles_to_next = 5;
  return (ret + 3);
}
