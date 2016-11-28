/*
** store_list.c for store_list.c in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Thu Mar 12 16:24:21 2015 Nyrandone Noboud-Inpeng
** Last update Sat Mar 28 19:21:51 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

char		*fill_line(char *gnl)
{
  char		*str;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((str = malloc((my_strlen(gnl) + 2) * sizeof(char))) == NULL)
    return (NULL);
  while (gnl[i] != '\0')
    str[j++] = gnl[i++];
  str[j] = '\0';
  return (str);
}
