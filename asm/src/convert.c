/*
** convert.c for  in /home/veyrie_f/rendu/CPE_2014_corewar/asm/src
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Thu Apr  9 15:18:36 2015 fernand veyrier
** Last update Thu Apr  9 15:18:43 2015 fernand veyrier
*/

#include "asm.h"

void	put_magic(int sd)
{
  int	magic;

  magic = COREWAR_EXEC_MAGIC;
  my_putchar_fd(0, sd);
  my_putchar_fd((magic >> 16) % 256, sd);
  my_putchar_fd((magic >> 8) % 256, sd);
  my_putchar_fd((magic % 256), sd);
}

int		init_hexa(t_hexa *h, t_list **list, t_list **new, char *champ)
{
  char		*new_champ;

  if ((new_champ = get_champion_name(champ)) == NULL)
    return (-1);
  h->check = 0;
  if ((h->sd = open(new_champ, O_CREAT | O_TRUNC | O_WRONLY, 0666)) == -1)
    return (-1);
  if ((h->ld = open(champ, O_RDONLY)) == -1)
    return (-1);
  put_magic(h->sd);
  (*new) = (*list)->next;
  header(h->sd, new, list);
  (*new) = (*list)->next;
  free(new_champ);
  return (0);
}

void	change_bytes(t_hexa **h, t_list **new)
{
  ((strcmp_asm((*new)->args[0], "live") == 0 ||
    strcmp_asm((*new)->args[0], "and") == 0 ||
    strcmp_asm((*new)->args[0], "xor") == 0 ||
    strcmp_asm((*new)->args[0], "or") == 0 ||
    strcmp_asm((*new)->args[0], "ld") == 0) ? ((*h)->y = 24) :
   ((*h)->y = 8));
}

void	check_conversion(t_list **val, t_hexa **h, t_list **list, t_list **new)
{
  if (*val == *list && check_label_asm(list, (*h)->tmp2) == 1)
    {
      *val = (*new)->prev;
      (*h)->h = search_label_neg(val, (*h)->tmp2, 0);
      (*h)->h = search_last_label_neg(val, (*h)->h, 1);
      (*h)->check = 1;
    }
  else if (strcmp_asm((*h)->tmp2, (*val)->label) == 0)
    (*h)->h = (*h)->count;
  else if ((*new)->args[(*h)->a][2] == '0' && (*new)->args[(*h)->a][3] == 'x')
    (*h)->h = my_getnbr_base(&(*new)->args[(*h)->a][4], "0123456789abcdef");
  else
    (*h)->h = my_getnbr(&(*new)->args[(*h)->a][2]);
}

void	check_conversion_ind(t_list **val, t_hexa **h, t_list **list,
			     t_list **new)
{
  if (*val == *list && check_label_asm(list, (*h)->tmp2) == 1)
    {
      *val = (*new)->prev;
      (*h)->h = search_label_neg(val, (*h)->tmp2, 0);
      (*h)->h = search_last_label_neg(val, (*h)->h, 1);
      (*h)->check = 1;
    }
  else if ((*h)->tmp2 != NULL && strcmp_asm((*h)->tmp2, (*val)->label) == 0)
    (*h)->h = (*h)->count;
  else if ((*new)->args[(*h)->a][1] == '0' && (*new)->args[(*h)->a][2] == 'x')
    (*h)->h = my_getnbr_base(&(*new)->args[(*h)->a][4], "0123456789abcdef");
  else if ((*new)->args[(*h)->a][0] == '0' && (*new)->args[(*h)->a][1] == 'x')
    (*h)->h = my_getnbr_base(&(*new)->args[(*h)->a][2], "0123456789abcdef");
  else
    (*h)->h = my_getnbr(&(*new)->args[(*h)->a][0]);
}
