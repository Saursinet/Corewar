/*
** file_management.c for file_management in /home/noboud_n/rendu/CPE/Corewar/src
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
**
** Started on  Fri Mar 27 17:23:25 2015 Nyrandone Noboud-Inpeng
** Last update Wed Apr  8 18:01:25 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	size_prog(int a, int count, t_list **new)
{
  if ((*new)->nbr_arg != 0)
    count++;
  while ((*new)->nbr_arg != 0 && (*new)->args[a] != 0)
    {
      if ((*new)->args[a][0] == 'r')
        count++;
      else if (((*new)->args[a][0] == '%' && (*new)->args[a][1] == ':') ||
               ((*new)->args[a][0] == '%'))
        ((strcmp_asm((*new)->args[0], "live") == 0 ||
          strcmp_asm((*new)->args[0], "and") == 0 ||
	  strcmp_asm((*new)->args[0], "xor") == 0 ||
	  strcmp_asm((*new)->args[0], "or") == 0 ||
          strcmp_asm((*new)->args[0], "ld") == 0) ?
         (count += 4) : (count += 2));
      else
        count += 2;
      a++;
    }
  if ((*new)->nbr_arg != 0 && strcmp_asm((*new)->args[0], "live") != 0 &&
      strcmp_asm((*new)->args[0], "fork") != 0 &&
      strcmp_asm((*new)->args[0], "lfork") != 0 &&
      strcmp_asm((*new)->args[0], "zjmp") != 0)
    count++;
  (*new) = (*new)->next;
  return (count);
}

int	prog_name(int count, int sd, t_list **new, t_list **list)
{
  int	a;

  while (count++ < PROG_NAME_LENGTH + 4)
    my_putchar_fd(0, sd);
  count = 0;
  (*new) = (*list)->next;
  count = 0;
  while ((*new) != (*list))
    count = size_prog(1, 0, new) + count;
  a = 24;
  while (a >= 0)
    {
      my_putchar_fd(count >> a, sd);
      a -= 8;
    }
  return (-1);
}

int	registre_hexa(char *tmp2, t_list *new, int sd, int a)
{
  int	h;
  int	y;

  if (new->args[a][0] == 'r')
    {
      y = 1;
      h = 0;
      if ((tmp2 = malloc(sizeof(char *) * 100)) == NULL)
	return (my_puterr("Cannot perform MALLOC.\n"));
      while (new->args[a][y] != 0)
	tmp2[h++] = new->args[a][y++];
      tmp2[h] = 0;
      my_putchar_fd(my_getnbr(tmp2) % 256, sd);
      free(tmp2);
    }
  return (0);
}

void	padding_byte_encoding(char (*stock)[9], int i)
{
  while (i <= 7)
    (*stock)[i++] = '0';
  (*stock)[i] = 0;
}
