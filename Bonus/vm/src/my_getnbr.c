/*
** my_getnbr.c for my_getnbr in /home/saurs_f/rendu/Piscine_C_J04
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Fri Oct  3 17:17:33 2014 Florian Saurs
** Last update Thu Apr 16 00:16:37 2015 Florian Saurs
*/

#include "types.h"

int	signe_neg(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	++n;
      ++i;
    }
  if (n % 2 == 0)
    return (0);
  else
    return (1);
}

int	my_getnbr(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')
    {
      while (str[i] == '+' || str[i] == '-')
	++i;
      n = n * 10 + str[i] - 48;
      ++i;
    }
  if (str[i])
    put_my_error("Wrong nbr_cycle.\n");
  if (signe_neg(str) == 1)
    put_my_error("Nbr_cycle has to be positive.\n");
  return (n);
}

int	my_getnbr_n(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')
    {
      while (str[i] == '+' || str[i] == '-')
	++i;
      n = n * 10 + str[i] - 48;
      ++i;
    }
  if (str[i])
    put_my_error("Usage -a [nbr] or -n [nbr].\n");
  if (signe_neg(str) == 1)
    put_my_error("Usa -a [nbr] or -n [nbr].\n");
  return (n);
}
