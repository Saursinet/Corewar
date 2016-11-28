/*
** my_getnbr.c for my_getnbr in /media/blinux/noboud_n/Librairie/sources
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Mon Dec 22 00:08:21 2014 Nyrandone Noboud-Inpeng
** Last update Thu Mar 19 17:27:23 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	posneg(int *n, int y)
{
  *n = *n % 2;
  if (*n == 1)
    {
      y = y * (-1);
      return (y);
    }
  if (*n == 0)
    return (y);
  return (y);
}

int	loop(int *n, int *y, int *x, char *str)
{
  int	i;

  i = 0;
  while (((str[i] >= '0' && str[i] <= '9') || (str[i] == '-')
	  || str[i] == '+') && str[i] != '\0')
    i = i + 1;
  while ((str[i] < '0' || str[i] > '9') && i != 0)
    i = i - 1;
  while (i >= 0 && str[i] >= '0' && str[i] <= '9')
    {
      *y = (str[i] - '0') * (*x) + (*y);
      *x = *x * 10;
      i = i - 1;
    }
  while (((i >= 0 && str[i] == '-') || (i >= 0 && str[i] == '+')))
    {
      if (str[i] == '-')
	{
	  *n = (*n) + 1;
	  i = i - 1;
	}
      else if (str[i] == '+')
	i--;
    }
  return (i);
}

int	my_getnbr(char *str)
{
  int	y;
  int	x;
  int	n;

  y = 0;
  x = 1;
  n = 0;
  loop(&n, &y, &x, str);
  y = posneg(&n, y);
  return (y);
}
