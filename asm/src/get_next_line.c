/*
** get_next_line.c for get_next_line in /media/blinux/noboud_n/Librairie/sources/getnextline
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Mon Dec 22 00:06:10 2014 Nyrandone Noboud-Inpeng
** Last update Fri Mar 27 14:01:26 2015 Nyrandone Noboud-Inpeng
*/

#include "get_next_line.h"

char	*my_realloc(char *str, int i)
{
  char	*src;
  int	y;
  int	x;

  y = 0;
  x = 0;
  while (str[y] != '\0')
    y++;
  if ((src = malloc((y + (i + 1)) * sizeof(char))) == NULL)
    return (NULL);
  while (str[x] != '\0')
    {
      src[x] = str[x];
      x++;
    }
  src[x] = '\0';
  free(str);
  return (src);
}

int	search_char(char *str, char x)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == x)
	return (1);
      i = i + 1;
    }
  return (0);
}

char	*store_str(t_gnl *v, char *storage, char *buffer, int fd)
{
  while (v->x > 0)
    {
      buffer[v->x] = '\0';
      v->i = 0;
      v->str[v->k] = '\0';
      v->str = my_realloc(v->str, SIZE + 1);
      if ((v->y = search_char(buffer, '\n')) == 0)
	while (buffer[v->i] != '\0')
	  v->str[v->k++] = buffer[v->i++];
      else if ((v->y = search_char(buffer, '\n')) == 1)
	{
	  while (buffer[v->i] != '\n')
	    v->str[v->k++] = buffer[v->i++];
	  v->str[v->k] = '\0';
	  v->i = v->i + 1;
	  while (buffer[v->i] != '\0')
	    storage[v->s++] = buffer[v->i++];
	  storage[v->s] = '\0';
	  return (NULL);
	}
      v->str[v->k] = '\0';
      if ((v->x = read(fd, buffer, SIZE)) == (-1))
	return (NULL);
    }
  return (NULL);
}

char	*check_read(t_gnl *v, char *storage)
{
  char	tmp[SIZE + 1];

  v->k = 0;
  if ((v->y = search_char(storage, '\n')) == 1)
    {
      while (storage[v->s] != '\n')
	v->str[v->k++] = storage[v->s++];
      v->str[v->k] = '\0';
      v->s++;
      v->k = 0;
      while (storage[v->s] != '\0')
	tmp[v->k++] = storage[v->s++];
      tmp[v->k] = '\0';
      v->s = 0;
      v->k = 0;
      while (tmp[v->k] != '\0')
	storage[v->s++] = tmp[v->k++];
      storage[v->s] = '\0';
      return (NULL);
    }
  while (storage[v->s] != '\0')
    v->str[v->k++] = storage[v->s++];
  v->str[v->k] = '\0';
  storage[0] = '\0';
  return (NULL);
}

char		*get_next_line(const int fd)
{
  static char	storage[SIZE + 1] = "";
  char		buffer[SIZE + 1];
  t_gnl		v;

  v.s = 0;
  v.k = 0;
  if ((v.str = malloc((SIZE + 1) * sizeof(char))) == NULL)
    return (NULL);
  if ((v.x = read(fd, buffer, SIZE)) == (-1))
    return (NULL);
  while (storage[v.s] != '\0')
    v.str[v.k++] = storage[v.s++];
  v.s = 0;
  if (v.x == 0 && storage[0] != '\0')
    {
      check_read(&v, storage);
      return (v.str);
    }
  else if (v.x > 0)
    {
      store_str(&v, storage, buffer, fd);
      return (v.str);
    }
  free(v.str);
  return (NULL);
}
