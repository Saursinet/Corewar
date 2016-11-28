/*
** my_reallocs.c for my_reallocs in /media/blinux/noboud_n/rendu/PSU_2014_minishell2/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Tue Feb  3 22:29:49 2015 Nyrandone Noboud-Inpeng
** Last update Thu Mar 12 13:21:19 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

char	**my_realloc_dd(char **tab, int size, int size_tab)
{
  char	**tmp;
  int	x;
  int	y;

  y = 0;
  if ((tmp = malloc((size_tab + (size + 1)) * sizeof(char *))) == NULL)
    return (NULL);
  while (y < size_tab)
    {
      x = 0;
      if ((tmp[y] = malloc((my_strlen(tab[y]) + 1) * sizeof(char))) == NULL)
	return (NULL);
      while (tab[y][x] != '\0')
	{
	  tmp[y][x] = tab[y][x];
	  x++;
	}
      tmp[y][x] = '\0';
      y++;
    }
  tmp[y] = NULL;
  free_tab(tab);
  return (tmp);
}
