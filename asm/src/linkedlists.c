/*
** linkedlists.c for linkedlists in /media/blinux/noboud_n/rendu/MUL_2014_rtv1/src
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
**
** Started on  Wed Feb 18 10:29:09 2015 Nyrandone Noboud-Inpeng
** Last update Sun Mar 29 15:20:12 2015 Alban Combaud
*/

#include "asm.h"

t_list		*init_list()
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->prev = list;
  list->next = list;
  return (list);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

t_list		*add_data(t_list *list, char *gnl)
{
  t_list	*n_elem;
  char		*str;

  if ((n_elem = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  if (n_elem != NULL)
    {
      if ((str = fill_line(gnl)) == NULL)
	return (NULL);
      n_elem->prev = list->prev;
      n_elem->next = list;
      list->prev->next = n_elem;
      list->prev = n_elem;
      n_elem->data = str;
      n_elem->len_data = my_strlen(str);
      n_elem->nbr_arg = 0;
      n_elem->label = NULL;
      n_elem->args = NULL;
      n_elem->lab = -1;
      n_elem->name = 0;
      n_elem->comment = 0;
    }
  return (list);
}
