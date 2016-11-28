/*
** arguments.c for arguments in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Sun Mar 15 11:56:19 2015 Nyrandone Noboud-Inpeng
** Last update Mon Mar 30 13:34:12 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	strcmp_extend(char *pattern, char *compare_with, int begin)
{
  int	i;

  i = 0;
  while (pattern[i] != '\0')
    {
      if (pattern[i] != compare_with[begin])
	return (-1);
      ++i;
      ++begin;
    }
  return (0);
}

int		attribute_nbr_arg(t_list *elem, int x)
{
  static int	check = 0;
  static t_list	*tmp = NULL;

  (tmp == NULL ? (tmp = elem) : (tmp = tmp));
  if (tmp != elem)
    {
      check = 0;
      tmp = elem;
    }
  if (check++ == 0)
    {
      if (x == 0 || x == 8 || x == 11 || x == 14 || x == 15)
	elem->nbr_arg = 1;
      else if (x == 9 || x == 10 || x == 13)
	elem->nbr_arg = 2;
      else
	elem->nbr_arg = 3;
    }
  return (0);
}

int	count_separator(t_list *elem, int line)
{
  int	i;
  int	separator;
  int	check;

  separator = 0;
  (elem->lab != -1 ? (i = elem->lab) : (i = 0));
  while (elem->data[i] != '\0' && elem->data[i] != COMMENT_CHAR
	 && elem->data[i] != ';')
    {
      check = 0;
      if (elem->data[i] == SEPARATOR_CHAR)
	{
	  ++check;
	  ++separator;
	}
      ++i;
      if (elem->data[i] == SEPARATOR_CHAR && check != 0)
	return (row_separator(line));
      else if (check != 0)
	if ((no_arg_after_separator(elem, line, i)) == -1)
	  return (-1);
    }
  return (separator);
}

int	count_arguments(t_list *list, t_list *elem, int line, int nbr_separator)
{
  int	separator;

  if ((separator = count_separator(elem, line)) == -1)
    {
      free_list(list);
      return (-1);
    }
  if (separator != nbr_separator && nbr_separator != -1)
    {
      number_arg_wrong();
      my_puterr("\nSyntax error line ");
      my_put_nbr(line + 1);
      my_puterr(" -- ");
      write(2, RED, 5);
      write(2, BOLD, 4);
      my_puterr("invalid number of arguments for the actual instruction.\n");
      write(2, DEFAULT, 4);
      free_list(list);
      return (-1);
    }
  return (0);
}

int		check_arguments(t_list *list)
{
  t_list	*elem;
  int		line;
  int		i;

  line = 0;
  i = 0;
  elem = list->next;
  if ((parser_separator(list)) == -1)
    return (-1);
  line = count_elem_line(line, &elem, list);
  while (elem != list)
    {
      i = 0;
      i = increment_value_elem(elem, i);
      if (elem->data[i] != '\0' && elem->data[i] != COMMENT_CHAR
	  && elem->data[i] != ';')
  	if ((count_arguments(list, elem, line, elem->nbr_arg - 1)) == -1)
  	  return (-1);
      ++line;
      elem = elem->next;
    }
  number_arg_ok();
  return (check_values(list));
}
