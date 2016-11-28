/*
** pars_my_cor.c for corewar in /home/saursf/rendu/CPE_2014_corewar
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Fri Mar 13 14:21:51 2015 Florian Saurs
** Last update Tue Apr 14 16:17:17 2015 Florian Saurs
*/

#include "types.h"

char	*my_strcpy(char *str)
{
  int	i;
  char	*buff;

  if (str)
    {
      if ((buff = malloc(my_strlen(str) + 1)) == NULL)
	exit(-1);
      i = 0;
      while (str[i])
	{
	  buff[i] = str[i];
	  ++i;
	}
      buff[i] = 0;
      return (buff);
    }
  return (NULL);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str)
    {
      while (str[i])
	++i;
      return (i);
    }
  return (-1);
}

int	my_strcmp(char *pattern, char *compare_with)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  if (pattern == NULL || compare_with == NULL)
    return (-1);
  while (pattern[i] != '\0' && compare_with[i] != 0)
    {
      if (pattern[i] != compare_with[x])
	return (-1);
      ++i;
      ++x;
    }
  if (compare_with[i] != 0 || pattern[i] != 0)
    return (-1);
  return (0);
}
