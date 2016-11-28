/*
** ldi.c for ldi in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Sat Mar 21 12:35:21 2015 Nyrandone Noboud-Inpeng
** Last update Sat Mar 21 17:32:08 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

static int	first_argument(t_list *list, t_list *elem, int line, int i)
{
  int		register_val;
  int		direct;
  int		indirect;

  register_val = 0;
  direct = 0;
  indirect = 0;
  if ((register_val = check_register(elem->args[i], line)) == -2)
    return (-1);
  if ((direct = check_direct(list, elem->args[i], line)) == -2)
    return (-1);
  if ((indirect = check_indirect(list, elem->args[i], line)) == -2)
    return (-1);
  if (register_val == -1 && direct == -1 && indirect == -1)
    return (error_argument(line, elem->args[i]));
  return (0);
}

static int	second_argument(t_list *list, t_list *elem,
				int line, int i)
{
  int		direct;
  int		register_val;

  direct = 0;
  register_val = 0;
  if ((register_val = check_register(elem->args[i], line)) == -2)
    return (-1);
  if ((direct = check_direct(list, elem->args[i], line)) == -2)
    return (-1);
  if (register_val == -1 && direct == -1)
    return (error_argument(line, elem->args[i]));
  return (0);
}

static int	third_argument(t_list *elem, int line, int i)
{
  int		register_val;

  register_val = 0;
  if ((register_val = check_register(elem->args[i], line)) == -2)
    return (-1);
  if (register_val == -1)
    return (error_argument(line, elem->args[i]));
  return (0);
}

int	ldi(t_list *list, t_list *elem, int line)
{
  int	i;
  int	return_value;

  i = -1;
  while (elem->args[++i] != NULL)
    {
      if (i == 1)
	{
	  if ((return_value = first_argument(list, elem, line, i)) == -1)
	    return (-1);
	}
      else if (i == 2)
	{
	  if ((return_value = second_argument(list, elem, line, i)) == -1)
	    return (-1);
	}
      else if (i == 3)
	if ((return_value = third_argument(elem, line, i)) == -1)
	  return (-1);
    }
  return (0);
}
