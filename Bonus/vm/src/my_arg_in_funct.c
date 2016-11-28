/*
** my_arg_in_funct.c for corewar in /home/saursf/rendu/CPE_2014_corewar/vm
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Tue Mar 31 14:23:35 2015 Florian Saurs
** Last update Tue Apr 14 16:42:32 2015 Florian Saurs
*/

#include "types.h"

void		my_param_next(t_mem *arena, int i, t_champ *champion,
			      t_decal *par)
{
  if (par->cmd[5] == 0 && par->cmd[4] == 1)
    {
      par->my_reg2 = champion->registry[tern((int)arena[(i + 2 + par->decal) %
							MEM_SIZE].cmd)];
      par->decal += 1;
      par->ret += 1;
    }
  else if (par->cmd[5] == 1 && par->cmd[4] == 0)
    {
      par->my_reg2 = my_decal_of_four(arena, i + 2 + par->decal);
      par->decal += 4;
      par->ret += 4;
    }
  else if (par->cmd[5] == 1 && par->cmd[4] == 1)
    {
      par->my_reg2 = my_decal_of_two(arena, i + 2 + par->decal);
      par->decal += 2;
      par->ret += 2;
    }
}

void		my_param(t_mem *arena, int i, t_champ *champion, t_decal *par)
{
  if (par->cmd[7] == 0 && par->cmd[6] == 1)
    {
      par->my_reg = champion->registry[tern((int)arena[(i + 2) %
						       MEM_SIZE].cmd)];
      par->decal = 1;
      par->ret += 1;
    }
  else if (par->cmd[7] == 1 && par->cmd[6] == 1)
    {
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
