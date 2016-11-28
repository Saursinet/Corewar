/*
** check_values.c for check_values in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Mon Mar 16 20:13:24 2015 Nyrandone Noboud-Inpeng
** Last update Wed Apr  8 16:38:44 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int		check_functions(t_list *list,
				int (*func[])(t_list *, t_list *, int))
{
  int		i;
  t_list	*elem;
  char		*dict[17];
  int		line;

  dictionnary_order(dict);
  elem = list->next;
  line = 1;
  while (elem != list)
    {
      i = -1;
      if (elem->nbr_arg != 0)
	while (dict[++i] != NULL)
	  if ((true_strcmp(dict[i], elem->args[0])) == 0)
	    if ((func[i](list, elem, line)) == -1)
	      {
		free_list(list);
		return (-1);
	      }
      ++line;
      elem = elem->next;
    }
  return (0);
}

int		check_values(t_list *list)
{
  static int	(*func[])(t_list *, t_list *, int) =
    {
      &live,
      &ld,
      &st,
      &add,
      &add,
      &andorxor,
      &andorxor,
      &andorxor,
      &live,
      &ldi,
      &sti,
      &live,
      &ld,
      &lldi,
      &live,
      &aff,
      NULL
    };

  if ((check_functions(list, func)) == -1)
    return (-1);
  arguments_ok();
  return (0);
}
