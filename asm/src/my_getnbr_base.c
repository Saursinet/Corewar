/*
** my_getnbr_base.c for my_getnbr_base in /media/blinux/noboud_n/Practice
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Thu Feb 19 13:55:21 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 27 17:13:48 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	check_char(char *str, char *base)
{
  int	i;
  int	x;
  int	count;
  char	tmp;

  i = 0;
  x = 0;
  if (base[0] == '\0' || str[0] == '\0')
    return (-1);
  while (base[x] != '\0')
    {
      count = 0;
      tmp = base[x];
      while (base[i] != '\0')
	{
	  if (base[i] == tmp)
	    count++;
	  i++;
	}
      if (count != 1)
	return (-1);
      x++;
      i = 0;
    }
  return (0);
}

int	check_base(char *str, char *base)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  if ((check_char(str, base)) == -1)
    return (-1);
  while (str[i] != '\0' && base[x] != '\0')
    {
      while (base[x] != '\0')
	{
	  if (str[i] == base[x] || str[i] == '-' || str[i] == '+')
	    i++;
	  else
	    x++;
	}
      if (str[i] != '\0')
	i++;
    }
  if (base[x] != '\0' && x != 0)
    return (-1);
  return (0);
}

int	my_getnbr_base(char *str, char *base)
{
  int	len;
  int	x;
  int	nbr;
  int	i;

  if ((check_base(str, base)) == -1)
    return (0);
  x = 0;
  nbr = 0;
  len = my_strlen(base);
  while (str[x] != '\0')
    {
      i = 0;
      while (base[i] != str[x] && i < len)
	i++;
      if (base[i] == str[x])
	nbr = i + (nbr * len);
      else
      	if ((str[x] != '+' && str[x] != '-'))
	  return (0);
      x++;
    }
  return (nbr);
}
