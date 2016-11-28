/*
** my_strcat.c for my_strcat in /home/saurs_f/rendu/Piscine_C_J07/lib/my
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Tue Oct  7 10:14:57 2014 Florian Saurs
** Last update Mon Feb 16 16:58:25 2015 Florian Saurs
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	c;
  char	*str;
  int	len;

  i = 0;
  c = 0;
  len = my_strlen(dest) + my_strlen(src);
  if ((str = malloc(sizeof(char) * (len + 2))) == NULL)
    return (NULL);
  while (dest[i] != 0)
    {
      str[i] = dest[i];
      ++i;
    }
  str[i++] = '/';
  while (src[c] != 0)
    str[i++] = src[c++];
  str[i] = 0;
  return (str);
}
