/*
** my_putchar.c for my_putchar in /home/saurs_f
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Thu Oct  2 17:53:24 2014 Florian Saurs
** Last update Sat Apr 11 19:37:37 2015 Florian Saurs
*/

#include "types.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

void	my_put_nbr(int nb)
{
  int	i;

  i = 1;
  if (nb == 0)
    my_putchar('0');
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  while (i <= nb)
    i = i * 10;
  i = i / 10;
  while (i > 0)
    {
      my_putchar(48 + (nb / i) % 10);
      i = i / 10;
    }
}
