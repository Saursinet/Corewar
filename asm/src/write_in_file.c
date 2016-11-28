/*
** write_in_file.c for write_in_file in /home/noboud_n/rendu/CPE/Corewar/src
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
**
** Started on  Fri Mar 27 17:31:06 2015 Nyrandone Noboud-Inpeng
** Last update Tue Apr  7 13:47:17 2015 Alban Combaud
*/

#include "asm.h"

void	direct(t_hexa *h, t_list **list, t_list **new, t_list **val)
{
  if ((*new)->args[h->a][1] == ':')
    {
      if ((h->tmp2 = fill_tmp(h->tmp2, new, h->a, 2)) == NULL)
	exit(-1);
      (*val) = (*new);
      h->count = search_label(list, val, h->tmp2, 0);
      check_conversion(val, &h, list, new);
      free(h->tmp2);
    }
  else
    (((*new)->args[h->a][1] == '0' && (*new)->args[h->a][2] == 'x') ?
     (h->h = my_getnbr_base(&(*new)->args[h->a][3], "0123456789abcdef")) :
     (h->h = my_getnbr(&(*new)->args[h->a][1])));
  change_bytes(&h, new);
  while (h->y >= 0)
    {
      ((h->check == 1) ? (my_putchar_fd((h->h >> h->y) % 256, h->sd)) :
       (my_putchar_fd((h->h >> h->y) % 256, h->sd)));
      h->y = h->y - 8;
    }
}

void	indirect(t_hexa *h, t_list **list, t_list **new, t_list **val)
{
  if ((*new)->nbr_arg != 0)
    {
      if ((h->tmp2 = fill_tmp(h->tmp2, new, h->a, 0)) == NULL)
	exit(-1);
      *val = *new;
      h->count = search_label(list, val, h->tmp2, 0);
      check_conversion_ind(val, &h, list, new);
      free(h->tmp2);
    }
  h->y = 8;
  while (h->y >= 0)
    {
      ((h->check == 1) ? (my_putchar_fd((h->h >> h->y) % 256, h->sd)) :
       (my_putchar_fd((h->h >> h->y) % 256, h->sd)));
      h->y = h->y - 8;
    }
}

int	write_instruction(t_list *new, t_hexa h)
{
  h.a = 1;
  if (new->nbr_arg != 0)
    search_hexa(new->args[0], h.sd);
  if (new->nbr_arg != 0)
    if (new->nbr_arg != 0 && strcmp_asm(new->args[0], "live") != 0 &&
	strcmp_asm(new->args[0], "fork") != 0 &&
	strcmp_asm(new->args[0], "lfork") != 0 &&
	strcmp_asm(new->args[0], "zjmp") != 0)
      byte_encoding(h.a, new, 0, h.sd);
  return (h.a);
}

int		write_hexa(t_list *list, t_list *new, t_list *val, char *champ)
{
  t_hexa	h;

  if ((init_hexa(&h, &list, &new, champ)) == -1)
    return (-1);
  while (new != list)
    {
      h.a = write_instruction(new, h);
      if (new->nbr_arg != 0)
	while (new->nbr_arg != 0 && new->args[h.a] != 0)
	  {
	    if (new->args[h.a][0] == 'r')
	      {
		if ((registre_hexa(h.tmp2, new, h.sd, h.a)) == -1)
		  return (-1);
	      }
	    else if ((new->args[h.a][0] == '%' && new->args[h.a][1] == ':') ||
		     (new->args[h.a][0] == '%'))
	      direct(&h, &list, &new, &val);
	    else
	      indirect(&h, &list, &new, &val);
	    h.a++;
	  }
      new = new->next;
    }
  return (0);
}
