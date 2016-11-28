/*
** my_putstr.c for my_putstr in /home/saurs_f
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Mon Oct  6 11:59:37 2014 Florian Saurs
** Last update Tue Dec  2 13:43:13 2014 Florian Saurs
*/

#include "../include/my.h"

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
