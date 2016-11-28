/*
** add.c for add in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Fri Mar 20 18:26:47 2015 Nyrandone Noboud-Inpeng
** Last update Sat Mar 21 15:36:27 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

static int	first_argument(t_list *elem, int line, int i)
{
  int		register_val;

  register_val = 0;
  if ((register_val = check_register(elem->args[i], line)) == -2)
    return (-1);
  if (register_val == -1)
    return (error_argument(line, elem->args[i]));
  return (0);
}

int	add(t_list *list, t_list *elem, int line)
{
  int	i;
  int	return_value;

  i = 0;
  (void)list;
  while (elem->args[++i] != NULL)
    {
      return_value = first_argument(elem, line, i);
      if (return_value == -2 || return_value == -1)
	return (-1);
    }
  return (0);
}
