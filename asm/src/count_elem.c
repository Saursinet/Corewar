/*
** count_elem.c for count_elem in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Fri Mar 27 01:09:43 2015 Nyrandone Noboud-Inpeng
** Last update Mon Apr 13 14:28:22 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int		count_elem_line(int line, t_list **elem, t_list *list)
{
  int		save;
  t_list	*tmp;

  save = line;
  tmp = (*elem);
  while ((*elem)->comment != 1 && (*elem) != list)
    {
      ++line;
      *elem = (*elem)->next;
    }
  if ((*elem) == list)
    {
      (*elem) = tmp;
      while ((*elem)->name != 1 && (*elem) != list)
	{
	  ++save;
	  *elem = (*elem)->next;
	}
      (*elem) = (*elem)->next;
      return (++save);
    }
  (*elem) = (*elem)->next;
  return (++line);
}
