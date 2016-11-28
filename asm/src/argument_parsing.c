/*
** argument_parsing.c for arguments_parsing in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Mon Mar 16 17:34:13 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 27 13:36:00 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	check_elem(t_list *elem)
{
  int	i;

  (elem->lab != -1 ? (i = elem->lab) : (i = 0));
  if (elem->lab != -1)
    {
      while ((elem->data[i] == ' ' || elem->data[i] == '\t')
	     && elem->data[i] != '\0' && elem->data[i] != COMMENT_CHAR
	     && elem->data[i] != ';')
	++i;
      if (elem->data[i] == '\0' || elem->data[i] == COMMENT_CHAR
	  || elem->data[i] == ';')
	return (1);
    }
  if (elem->nbr_arg == 0)
    return (1);
  return (0);
}

char	**initialize_tab(t_list *list, t_list *elem, int *i)
{
  char	**tab;
  int	fsd;
  int	len;

  fsd = 0;
  (elem->lab != -1 ? (*i = elem->lab) : (*i = 0));
  len = elem->len_data;
  if ((tab = malloc(((count_elem(list)) + 1) * sizeof(char *))) == NULL)
    return (put_error("Cannot perform MALLOC.\n"));
  tab[fsd] = NULL;
  if ((tab[fsd] = malloc((len + 1) * sizeof(char))) == NULL)
    return (put_error("Cannot perform MALLOC.\n"));
  return (tab);
}

char	**store_instruction(t_list *elem, char **tab, int *i, int *fsd)
{
  int	len;
  int	x;

  x = 0;
  len = elem->len_data;
  while ((elem->data[*i] == ' ' || elem->data[*i] == '\t')
	 && elem->data[*i] != '\0' && elem->data[*i] != COMMENT_CHAR
	 && elem->data[*i] != ';')
    ++(*i);
  while ((elem->data[*i] != ' ' && elem->data[*i] != '\t')
	 && elem->data[*i] != '\0' && elem->data[*i] != COMMENT_CHAR
	 && elem->data[*i] != ';')
    tab[*fsd][x++] = elem->data[(*i)++];
  tab[*fsd][x] = '\0';
  if (elem->data[*i] != '\0' && elem->data[*i] != COMMENT_CHAR
      && elem->data[*i] != ';' && *fsd != elem->nbr_arg)
    if ((tab[++(*fsd)] = malloc((len + 1) * sizeof(char))) == NULL)
      return (put_error("Cannot perform MALLOC.\n"));
  return (tab);
}

char		**store_arguments(t_list *elem, char **tab, int *i, int *fsd)
{
  int		x;

  x = 0;
  while (elem->data[*i] != SEPARATOR_CHAR && elem->data[*i] != '\0'
	 && elem->data[*i] != COMMENT_CHAR && elem->data[*i] != ';')
    {
      while ((elem->data[*i] == ' ' || elem->data[*i] == '\t')
      	     && elem->data[*i] != '\0' && elem->data[*i] != COMMENT_CHAR
      	     && elem->data[*i] != SEPARATOR_CHAR && elem->data[*i] != ';')
      	++(*i);
      if (elem->data[*i] != SEPARATOR_CHAR && elem->data[*i] != '\0'
	  && elem->data[*i] != COMMENT_CHAR && elem->data[*i] != ';')
	  tab[*fsd][x++] = elem->data[(*i)++];
    }
  tab[*fsd][x] = '\0';
  while ((elem->data[*i] == ' ' || elem->data[*i] == '\t')
	 && elem->data[*i] != '\0' && elem->data[*i] != COMMENT_CHAR
	 && elem->data[*i] != ';')
    ++(*i);
  if (elem->data[*i] != '\0' && elem->data[*i] != COMMENT_CHAR
      && elem->data[*i] != ';' && *fsd != elem->nbr_arg)
    if ((tab[++(*fsd)] = malloc((elem->len_data + 1) * sizeof(char))) == NULL)
      return (put_error("Cannot perform MALLOC.\n"));
  return (tab);
}

int		argument_parsing(t_list *list, t_list *elem)
{
  char		**tab;
  t_pars	pars;

  pars.fsd = 0;
  pars.check = 0;
  if ((check_elem(elem)) == 1)
    return (0);
  if ((tab = initialize_tab(list, elem, &pars.i)) == NULL)
    return (-1);
  while (elem->data[pars.i] != '\0' && elem->data[pars.i] != COMMENT_CHAR
	 && elem->data[pars.i] != ';')
    {
      if (pars.check++ == 0)
	if ((tab = store_instruction(elem, tab, &pars.i, &pars.fsd)) == NULL)
	  return (-1);
      if (pars.check != 0)
	if ((tab = store_arguments(elem, tab, &pars.i, &pars.fsd)) == NULL)
	  return (-1);
      (elem->data[pars.i] != '\0' && elem->data[pars.i] != COMMENT_CHAR
       && elem->data[pars.i] != ';' ? ++pars.i : (pars.i = pars.i));
    }
  (pars.fsd != 0 ? (tab[++pars.fsd] = NULL) : (tab[pars.fsd] = NULL));
  elem->args = tab;
  return (0);
}
