/*
** is_in.c for is_in in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Fri Mar 13 17:50:24 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 13 17:51:21 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	char_in_string(char tmp, char *pattern)
{
  int	i;

  i = 0;
  while (pattern[i] != '\0')
    {
      if (tmp == pattern[i])
	return (0);
      ++i;
    }
  return (-1);
}
