/*
** display_char.c for display_char in /home/noboud_n/Librairie/sources
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Sun Feb  1 15:45:32 2015 Nyrandone Noboud-Inpeng
** Last update Wed Mar 11 14:51:03 2015 Nyrandone Noboud-Inpeng
*/

#include <unistd.h>
#include "asm.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_put_err(char c)
{
  write(2, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    my_putchar(str[i++]);
  return (0);
}

int	my_puterr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    my_put_err(str[i++]);
  return (-1);
}

void	my_put_nbr(int nb)
{
  int	i;

  i = 1;
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-');
    }
  while ((nb / i) > 9)
    i = i * 10;
  while (i > 0)
    {
      my_putchar('0' + ((nb / i) % 10));
      i = i / 10;
    }
}
