/*
** ld.c for ld in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Fri Mar 20 17:35:03 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 27 01:41:35 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

static int	first_argument(t_list *list, t_list *elem, int line, int i)
{
  int		direct;
  int		indirect;

  direct = 0;
  indirect = 0;
  if ((direct = check_direct(list, elem->args[i], line)) == -2)
    return (-1);
  if ((indirect = check_indirect(list, elem->args[i], line)) == -2)
    return (-1);
  if (direct == -1 && indirect == -1)
    return (error_argument(line, elem->args[i]));
  return (0);
}

int	ld(t_list *list, t_list *elem, int line)
{
  int	i;
  int	register_val;

  i = -1;
  while (elem->args[++i] != NULL)
    {
      register_val = 0;
      if (i == 1)
	if ((first_argument(list, elem, line, i)) == -1)
	  return (-1);
      if (i == 2)
	{
	  if ((register_val = check_register(elem->args[i], line)) == -2)
	    return (-1);
	  if (register_val == -1)
	    return (error_argument(line, elem->args[i]));
	}
    }
  return (0);
}
