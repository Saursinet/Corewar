/*
** search_label.c for search_label in /home/noboud_n/rendu/CPE/Corewar/src
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
**
** Started on  Fri Mar 27 17:29:29 2015 Nyrandone Noboud-Inpeng
** Last update Mon Mar 30 14:00:31 2015 Alban Combaud
*/

#include "asm.h"

int	search_label(t_list **test, t_list **val, char *tmp2, int count)
{
  int	a_bis;

  while ((*val) != (*test) && ((*val)->lab == -1 ||
			    strcmp_asm(tmp2, (*val)->label) != 0))
    {
      a_bis = 1;
      if ((*val)->nbr_arg != 0)
	count++;
      while ((*val)->nbr_arg != 0 && (*val)->args[a_bis] != 0)
	search_argument(val, &a_bis, &count);
      if ((*val)->nbr_arg != 0 && strcmp_asm((*val)->args[0], "live") != 0
	  && strcmp_asm((*val)->args[0], "fork") != 0 &&
	  strcmp_asm((*val)->args[0], "zjmp") != 0 &&
	  strcmp_asm((*val)->args[0], "lfork") != 0)
	count++;
      (*val) = (*val)->next;
    }
  return (count);
}

int	search_label_neg(t_list **val, char *tmp2, int h)
{
  int	a_bis;

  while ((*val)->lab == -1 || strcmp_asm(tmp2, (*val)->label) != 0)
    {
      a_bis = 1;
      if ((*val)->nbr_arg != 0)
	h++;
      while ((*val)->nbr_arg != 0 && (*val)->args[a_bis] != 0)
	search_argument_neg(val, &a_bis, &h);
      if ((*val)->nbr_arg != 0 && strcmp_asm((*val)->args[0], "live") != 0
	  && strcmp_asm((*val)->args[0], "fork") != 0
	  && strcmp_asm((*val)->args[0], "lfork") != 0
	  && strcmp_asm((*val)->args[0], "zjmp") != 0)
	h++;
      (*val) = (*val)->prev;
    }
  return (h);
}

int	search_last_label_neg(t_list **val, int h, int a_bis)
{
  if ((*val)->nbr_arg != 0)
    h++;
  while ((*val)->nbr_arg != 0 && (*val)->args[a_bis] != 0)
    {
      if ((*val)->args[a_bis][0] == 'r')
	h++;
      else if (((*val)->args[a_bis][0] == '%' &&
		(*val)->args[a_bis][1] == ':') ||
	       ((*val)->args[a_bis][0] == '%'))
	((strcmp_asm((*val)->args[0], "live") == 0 ||
	  strcmp_asm((*val)->args[0], "and") == 0 ||
	  strcmp_asm((*val)->args[0], "or") == 0 ||
	  strcmp_asm((*val)->args[0], "xor") == 0 ||
	  strcmp_asm((*val)->args[0], "ld") == 0) ?
	 (h += 4) : (h += 2));
      else
	h += 2;
      a_bis++;
    }
  if ((*val)->nbr_arg != 0 && strcmp_asm((*val)->args[0], "live") != 0 &&
      strcmp_asm((*val)->args[0], "fork") != 0 &&
      strcmp_asm((*val)->args[0], "lfork") != 0 &&
      strcmp_asm((*val)->args[0], "zjmp") != 0)
    h++;
  return (-h);
}

char	*fill_tmp(char *tmp2, t_list **new, int a, int h)
{
  int	tmp;

  tmp = h;
  if ((tmp2 = malloc((my_strlen((*new)->args[a]) + 10) * sizeof(char *)))
      == NULL)
    return (NULL);
  while ((*new)->args[a][h] != 0)
    {
      tmp2[h - tmp] = (*new)->args[a][h];
      h++;
    }
  tmp2[h++ - tmp] = ':';
  tmp2[h - tmp] = 0;
  tmp = 0;
  if ((*new)->args[a][0] == ':')
    {
      while (tmp2[tmp + 1] != 0)
	{
	  tmp2[tmp] = tmp2[tmp + 1];
	  tmp++;
	}
      tmp2[tmp] = 0;
    }
  return (tmp2);
}
