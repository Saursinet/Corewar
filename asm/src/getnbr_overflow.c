/*
** getnbr_overflow.c for getnbr_overflow in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Thu Mar 19 17:20:13 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 20 16:32:37 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	pos_neg(int *n, int y)
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

int		check(int y, int i, char *str)
{
  int		count;
  static int	check = 0;

  count = 0;
  if (i == 0)
    check = 0;
  while (y > 0)
    {
      y = y / 10;
      ++count;
    }
  if (count == 0)
    if ((str[i] - '0') > 7)
      ++check;
  if (count == 9 && check != 0)
    if ((str[i] - '0') >= 2 && check != 0)
      return (-1);
  return (0);
}

int	increment_str(char *str)
{
  int	i;

  i = 0;
  while (((str[i] >= '0' && str[i] <= '9') || (str[i] == '-')
	  || str[i] == '+') && str[i] != '\0')
    i = i + 1;
  while ((str[i] < '0' || str[i] > '9') && i != 0)
    i = i - 1;
  return (i);
}

int	loop_overflow(int *n, int *y, int *x, char *str)
{
  int	i;

  i = increment_str(str);
  while (i >= 0 && str[i] >= '0' && str[i] <= '9')
    {
      if ((check(*y, i, str)) == -1)
	return (-1);
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
  return (0);
}

int	getnbr_overflow(char *str)
{
  int	y;
  int	x;
  int	n;

  y = 0;
  x = 1;
  n = 0;
  if ((loop_overflow(&n, &y, &x, str)) == -1)
    return (-1);
  y = pos_neg(&n, y);
  return (y);
}
