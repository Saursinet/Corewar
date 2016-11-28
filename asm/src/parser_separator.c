/*
** parser_separator.c for parser in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Mon Mar 16 13:45:21 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 27 13:37:33 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int		count_elem(t_list *list)
{
  t_list	*elem;
  int		size;

  size = 0;
  elem = list->next;
  while (elem != list)
    {
      ++size;
      elem = elem->next;
    }
  return (size);
}

int		check_all_arguments(t_list *list)
{
  t_list	*elem;
  int		line;
  char		*dict[17];

  line = 0;
  elem = list->next;
  dictionnary(dict);
  line = count_elem_line(line, &elem, list);
  while (elem != list)
    {
      if (elem->args != NULL)
	{
	  if ((compare_arguments(list, elem, line, dict)) == -1)
	    return (-1);
	}
      ++line;
      elem = elem->next;
    }
  return (0);
}

int		parser_separator(t_list *list)
{
  t_list	*elem;
  int		line;
  int		i;

  line = 0;
  elem = list->next;
  line = count_elem_line(line, &elem, list);
  while (elem != list)
    {
      i = 0;
      while ((elem->data[i] == ' ' || elem->data[i] == '\t')
	     && elem->data[i] != '\0' && elem->data[i] != COMMENT_CHAR
	     && elem->data[i] != ';')
  	++i;
      if (elem->data[i] != '\0' && elem->data[i] != COMMENT_CHAR
	  && elem->data[i] != ';')
  	if ((argument_parsing(list, elem)) == -1)
  	  return (-1);
      ++line;
      elem = elem->next;
    }
  if ((check_all_arguments(list)) == -1)
    return (-1);
  instructions_ok();
  return (0);
}
