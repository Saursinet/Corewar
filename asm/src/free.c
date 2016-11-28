/*
** free.c for free in /media/blinux/noboud_n/rendu/MUL_2014_rtv1/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Wed Feb 18 11:04:47 2015 Nyrandone Noboud-Inpeng
** Last update Mon Mar 16 20:01:15 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int		intfree_list(t_list *list)
{
  t_list	*elem;
  t_list	*tmp;

  elem = (list)->next;
  if (elem == list)
    {
      free(list);
      return (0);
    }
  if (elem != (list)->prev)
    {
      while (elem != (list)->prev)
	{
	  tmp = elem;
	  elem = elem->next;
	  free(tmp->data);
	  free(tmp);
	}
    }
  tmp = elem;
  free(tmp->data);
  free(tmp);
  if (tmp != list)
    free(list);
  return (0);
}

void		free_part(t_list *tmp)
{
  free(tmp->data);
  if (tmp->lab != -1)
    free(tmp->label);
  if (tmp->args != NULL)
    free_tab(tmp->args);
  free(tmp);
}

void		*free_list(t_list *list)
{
  t_list	*elem;
  t_list	*tmp;

  elem = (list)->next;
  if (elem == list)
    {
      free(list);
      return (NULL);
    }
  if (elem != (list)->prev)
    {
      while (elem != (list)->prev)
	{
	  tmp = elem;
	  elem = elem->next;
	  free_part(tmp);
	}
    }
  tmp = elem;
  free_part(tmp);
  if (tmp != list)
    free(list);
  return (NULL);
}

char		**free_tab(char **str)
{
  int		x;
  int		mark;

  x = 0;
  mark = 0;
  if (str[x] != NULL)
    mark = 1;
  while (str[x] != NULL)
    free(str[x++]);
  if (mark == 1)
    free(str);
  return (NULL);
}
