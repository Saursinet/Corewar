/*
** search_argument.c for search_argument in /home/noboud_n/rendu/CPE/Corewar/src
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
**
** Started on  Fri Mar 27 17:27:47 2015 Nyrandone Noboud-Inpeng
** Last update Mon Mar 30 13:56:24 2015 Alban Combaud
*/

#include "asm.h"

void	byte_encoding(int a, t_list *new, int i, int sd)
{
  char	stock[9];

  while (new->nbr_arg != 0 && new->args[a] != 0)
    {
      if (new->args[a][0] == 'r')
	{
	  stock[i++] = '0';
	  stock[i++] = '1';
	}
      else if ((new->args[a][0] == '%' && new->args[a][1] == ':') ||
	       (new->args[a][0] == '%'))
	{
	  stock[i++] = '1';
	  stock[i++] = '0';
	}
      else
	{
	  stock[i++] = '1';
	  stock[i++] = '1';
	}
      a++;
    }
  padding_byte_encoding(&stock, i);
  my_putchar_fd(my_getnbr_base(stock, "01") % 256, sd);
}

void	search_argument(t_list **val, int (*a_bis), int (*count))
{
  if ((*val)->args[(*a_bis)][0] == 'r')
    (*count)++;
  else if (((*val)->args[(*a_bis)][0] == '%' &&
	    (*val)->args[(*a_bis)][1] == ':') ||
	   ((*val)->args[(*a_bis)][0] == '%'))
    ((strcmp_asm((*val)->args[0], "live") == 0 ||
      strcmp_asm((*val)->args[0], "and") == 0 ||
      strcmp_asm((*val)->args[0], "xor") == 0 ||
      strcmp_asm((*val)->args[0], "or") == 0 ||
      strcmp_asm((*val)->args[0], "ld") == 0) ?
     ((*count) += 4) : ((*count) += 2));
  else
    (*count) += 2;
  (*a_bis)++;
}

void	search_argument_neg(t_list **val, int (*a_bis), int (*h))
{
  if ((*val)->args[(*a_bis)][0] == 'r')
    (*h)++;
  else if (((*val)->args[(*a_bis)][0] == '%' &&
	    (*val)->args[(*a_bis)][1] == ':') ||
	   ((*val)->args[(*a_bis)][0] == '%'))
    ((strcmp_asm((*val)->args[0], "live") == 0 ||
      strcmp_asm((*val)->args[0], "and") == 0 ||
      strcmp_asm((*val)->args[0], "xor") == 0 ||
      strcmp_asm((*val)->args[0], "or") == 0 ||
      strcmp_asm((*val)->args[0], "ld") == 0) ?
     (*h += 4) : (*h += 2));
  else
    *h += 2;
  (*a_bis)++;
}
