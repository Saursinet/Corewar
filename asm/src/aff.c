/*
** aff.c for aff.c in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Sat Mar 21 17:18:29 2015 Nyrandone Noboud-Inpeng
** Last update Sat Mar 21 17:30:33 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	aff(t_list *list, t_list *elem, int line)
{
  int	i;
  int	register_val;

  i = -1;
  register_val = 0;
  (void)list;
  while (elem->args[++i] != NULL)
    {
      if (i == 1)
	{
	  if ((register_val = check_register(elem->args[i], line)) == -2)
	    return (-1);
	  if (register_val == -1)
	    return (error_argument(line, elem->args[i]));
	}
    }
  return (0);
}
