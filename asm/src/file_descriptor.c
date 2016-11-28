/*
** file_descriptor.c for file_descriptor in /home/noboud_n/rendu/CPE/Corewar/src
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
**
** Started on  Fri Mar 27 17:18:53 2015 Nyrandone Noboud-Inpeng
** Last update Sun Mar 29 16:38:39 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

void	my_putchar_fd(char a, int sd)
{
  write(sd, &a, 1);
}

void	search_hexa(char *data, int sd)
{
  char	*dic1[17];
  int	*dic2;
  int	a;

  a = 0;
  dictionnary_order(dic1);
  if ((dic2 = dictionnary_hexa(NULL)) == NULL)
    exit(my_putstr("Cannot perform MALLOC.\n"));
  while (strcmp_asm(data, dic1[a]) != 0)
    a++;
  my_putchar_fd(dic2[a] % 256, sd);
  free(dic2);
}

int		my_dec_to_hex(int nb)
{
  char		tab[3];

  tab[0] = nb / 16 + '0';
  tab[1] = nb % 16 + '0';
  tab[2] = 0;
  return (my_getnbr(tab));
}

int	my_strlen_double(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    i++;
  return (i);
}

int		check_label_asm(t_list **list, char *tmp)
{
  t_list	*check;

  check = (*list)->next;
  while (check != *list)
    {
      if (check->lab != -1)
        if (strcmp_asm(check->label, tmp) == 0)
          return (1);
      check = check->next;
    }
  return (0);
}
