/*
** get_next_line.h for get_next_line.h in /media/blinux/noboud_n/Librairie/sources/getnextline
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Mon Dec 22 00:06:24 2014 Nyrandone Noboud-Inpeng
** Last update Wed Mar 11 13:31:13 2015 Nyrandone Noboud-Inpeng
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include <stdlib.h>
# include <unistd.h>
# include "asm.h"

# define SIZE 1

typedef struct	s_gnl
{
  int		i;
  int		k;
  int		s;
  int		x;
  int		y;
  char		*str;
}		t_gnl;

char	*get_next_line(const int);

#endif /* !GET_NEXT_LINE_H_ */
