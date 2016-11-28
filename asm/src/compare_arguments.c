/*
** compare_arguments.c for compare_arguments in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Tue Mar 17 23:43:36 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 27 13:28:13 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

void	initialize_arg_values(t_args *arg, t_list *list)
{
  arg->x = 0;
  arg->k = -1;
  arg->check = 0;
  arg->lab_true = 0;
  arg->dict_true = 0;
  arg->tmp = list->next;
}

void	check_if_label(t_list *elem, t_args *arg)
{
  while ((elem->args[arg->y][arg->x] == '%'
	  || elem->args[arg->y][arg->x] == ':')
	 && elem->args[arg->y][arg->x] != '\0'
	 && elem->args[arg->y][arg->x] != COMMENT_CHAR
	 && elem->args[arg->y][arg->x] != ';')
    {
      if (elem->args[arg->y][arg->x] == ':')
	++arg->check;
      ++arg->x;
    }
  arg->save = arg->x;
}

int		check_good_argument(t_list *list, t_list *elem,
				    t_args *arg, char *dict[17])
{
  while (arg->tmp != list)
    {
      arg->x = arg->save;
      arg->error_lab = 0;
      if ((arg->tmp)->lab != -1)
	{
	  ((strncmp_b((arg->tmp)->label, elem->args[arg->y], arg->x, 1)) == -1 ?
	   ++arg->error_lab : (arg->error_lab = arg->error_lab));
	  (arg->error_lab == 0 ? (arg->lab_true = 1) : (arg->error_lab = 1));
	}
      arg->tmp = arg->tmp->next;
    }
  while (dict[++arg->k] != NULL)
    {
      arg->x = arg->save;
      arg->error_dict = 0;
      if ((strncmp_b(dict[arg->k], elem->args[arg->y], arg->x, 0)) == -1)
	++arg->error_dict;
      (arg->error_dict == 0 ? (arg->dict_true = 1) : (arg->error_dict = 1));
    }
  if (arg->dict_true != 1 && arg->lab_true != 1)
    return (wrong_arguments(arg->line, list));
  return (0);
}

int		compare_arguments(t_list *list, t_list *elem,
				  int line, char *dict[17])
{
  t_args	arg;

  arg.y = -1;
  arg.line = line;
  while (elem->args[++arg.y] != NULL)
    {
      initialize_arg_values(&arg, list);
      if (elem->args[arg.y][arg.x] == ':'
	  || elem->args[arg.y][arg.x] == '%')
	{
	  check_if_label(elem, &arg);
	  if (arg.check != 0)
	    if ((check_good_argument(list, elem, &arg, dict)) == -1)
	      return (-1);
	}
    }
  return (0);
}
