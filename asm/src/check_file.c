/*
** check_file.c for check_file in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Wed Mar 11 16:33:38 2015 Nyrandone Noboud-Inpeng
** Last update Thu Apr 16 23:25:17 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int		store_header(t_list **elem, t_list *list, int line)
{
  int		x;
  int		i;

  x = 0;
  i = 0;
  while (*elem != list)
    {
      x = 0;
      while (((*elem)->data[x] == ' ' || (*elem)->data[x] == '\t')
	     && (*elem)->data[x] != '\0' && (*elem)->data[x] != '#'
	     && (*elem)->data[x] != ';')
	++x;
      if ((*elem)->data[x] != '\0' && (*elem)->data[x] != COMMENT_CHAR
	  && (*elem)->data[x] != ';' && (i == 0 || i == 1))
	{
	  if ((check_header(i, *elem, line)) == -1)
	    return (-1);
	  ++i;
	}
      if (i == 2)
	return (i);
      (*elem) = (*elem)->next;
      ++line;
    }
  return (0);
}

char		**check_file(t_list *list)
{
  int		i;
  t_list	*elem;
  char		**labels;
  char		*dict[17];

  dictionnary(dict);
  elem = list->next;
  if ((labels = malloc((MALLOC_SIZE + 1) * sizeof(char *))) == NULL)
    return (put_error("Cannot perform MALLOC.\n"));
  labels[0] = NULL;
  if ((i = store_header(&elem, list, 1)) == -1)
    return (NULL);
  while (elem != list)
    {
      if ((labels = check_label(i, elem, labels)) == NULL)
	return (free_list(list));
      ++i;
      elem = elem->next;
    }
  return (labels);
}
