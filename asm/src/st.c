/*
** st.c for st in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Fri Mar 20 18:03:25 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 27 00:56:27 2015 Nyrandone Noboud-Inpeng
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

static int	second_argument(t_list *list, t_list *elem,
				int line, int i)
{
  int		register_val;
  int		indirect;

  register_val = 0;
  indirect = 0;
  if ((register_val = check_register(elem->args[i], line)) == -2)
    return (-1);
  if ((indirect = check_indirect(list, elem->args[i], line)) == -2)
    return (-1);
  if (register_val == -1 && indirect == -1)
    return (error_argument(line, elem->args[i]));
  return (0);
}

int	st(t_list *list, t_list *elem, int line)
{
  int	i;
  int	return_value;

  i = -1;
  while (elem->args[++i] != NULL)
    {
      if (i == 1)
	{
	  return_value = first_argument(elem, line, i);
	  if (return_value == -1)
	    return (-1);
	}
      if (i == 2)
	{
	  return_value = second_argument(list, elem, line, i);
	  if (return_value == -1)
	    return (-1);
	}
    }
  return (0);
}
