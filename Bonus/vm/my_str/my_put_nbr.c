/*
** my_put_nbr.c for  in /home/saurs_f/rendu/Piscine_C_J03
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Wed Oct  1 16:59:05 2014 Florian Saurs
** Last update Tue Jan 27 17:40:26 2015 Florian Saurs
*/

#include "../include/my.h"

int	my_put_nbr(int nb)
{
  int	i;

  i = 1;
  if (nb == 0)
    {
      my_putchar('0');
    }
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  while (i <= nb)
    {
      i = i * 10;
    }
  i = i / 10;
  while (i > 0)
    {
      my_putchar(48 + (nb / i) % 10);
      i = i / 10;
    }
  return (0);
}
