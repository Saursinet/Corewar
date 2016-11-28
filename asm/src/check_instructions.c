/*
** check_instructions.c for check_instructions in /home/noboud_n/rendu/CPE/Corewar/src
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
**
** Started on  Fri Mar 13 11:23:38 2015 Nyrandone Noboud-Inpeng
** Last update Sun Mar 29 18:43:21 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int		compare_all_instructions(t_list *list, t_list *elem, int *i,
					 int line)
{
  int		x;
  int		ret_value;
  char		*dict[17];

  x = 0;
  dictionnary(dict);
  while (dict[x] != NULL)
    {
      if ((ret_value = strcmp_instructions(dict[x], elem, list, *i)) == -1
	  && dict[x + 1] == NULL)
	return (wrong_instruction(line, *i, elem, list));
      if (ret_value == 0)
	return (attribute_nbr_arg(elem, x));
      ++x;
    }
  return (0);
}

int		label_true(t_list *list, t_list *elem, int line, int mark)
{
  int		i;

  i = elem->lab;
  i = increment_value_elem(elem, i);
  while (elem->data[i] != '\0' && elem->data[i] != COMMENT_CHAR
	 && elem->data[i] != ';')
    {
      if (mark++ != 0)
	{
	  while (elem->data[i] != ':' && elem->data[i] != '\0'
		 && elem->data[i] != COMMENT_CHAR && elem->data[i] != ';')
	    ++i;
	  (elem->data[i] != '\0' && elem->data[i] != COMMENT_CHAR
	   && elem->data[i] != ';' ? ++i : 0);
	  i = increment_value_elem(elem, i);
	}
      if (elem->data[i] == '\0' || elem->data[i] == COMMENT_CHAR
	  || elem->data[i] == ';')
	return (invalid_line(elem, line, i, mark));
      if ((compare_all_instructions(list, elem, &i, line)) == -1)
	return (-1);
      (elem->data[i] != '\0' && elem->data[i] != COMMENT_CHAR
       && elem->data[i] != ';' ? ++i : (i = i));
    }
  return (0);
}

int		label_false(t_list *list, t_list *elem, int line, int mark)
{
  int		i;

  i = 0;
  i = increment_value_elem(elem, i);
  while (elem->data[i] != '\0' && elem->data[i] != COMMENT_CHAR
	 && elem->data[i] != ';')
    {
      if (mark++ != 0)
	{
	  while (elem->data[i] != ':' && elem->data[i] != '\0'
		 && elem->data[i] != COMMENT_CHAR && elem->data[i] != ';')
	    ++i;
	  (elem->data[i] != '\0' && elem->data[i] != COMMENT_CHAR
	   && elem->data[i] != ';' ? ++i : 0);
	  i = increment_value_elem(elem, i);
	}
      if (elem->data[i] == '\0' || elem->data[i] == COMMENT_CHAR
	  || elem->data[i] == ';')
	return (invalid_line(elem, line, i, mark));
      if ((compare_all_instructions(list, elem, &i, line)) == -1)
	return (-1);
      (elem->data[i] != '\0' && elem->data[i] != COMMENT_CHAR
       && elem->data[i] != ';' ? ++i : (i = i));
    }
  return (0);
}

int		line_check(t_list *list, t_list *elem, int line)
{
  int		mark;
  int		i;

  i = 0;
  mark = 0;
  i = increment_value_elem(elem, i);
  if (elem->data[i] == '\0' || elem->data[i] == COMMENT_CHAR
      || elem->data[i] == ';')
    return (0);
  if (elem->lab != -1)
    return (label_true(list, elem, line, mark));
  return (label_false(list, elem, line, mark));
}

int		check_instructions(t_list *list)
{
  t_list	*elem;
  int		line;

  line = 0;
  elem = list->next;
  line = count_elem_line(line, &elem, list);
  while (elem != list)
    {
      if ((line_check(list, elem, line)) == -1)
	return (-1);
      if (elem->len_data > 512)
	warning_idxmod(line);
      ++line;
      elem = elem->next;
    }
  if ((check_arguments(list)) == -1)
    return (-1);
  return (0);
}
