/*
** print_my_memory.c for corewar in /home/saursf/rendu/CPE_2014_corewar/vm
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Sat Apr 11 20:06:11 2015 Florian Saurs
** Last update Mon Apr 13 17:39:39 2015 Florian Saurs
*/

#include "types.h"

void		put_it(int i, char *str, t_mem *arena)
{
  t_put		put;

  put.nb2 = 8;
  put.c = -1;
  while (++put.c < 8)
    put.cmd[put.c] = (arena[i].cmd >> put.c) % 2;
  put.nb = 0;
  while (--put.c > 3)
    {
      if (put.cmd[put.c] == 1)
	put.nb += put.nb2;
      put.nb2 /= 2;
    }
  my_putchar(str[put.nb]);
  put.nb2 = 8;
  put.nb = 0;
  while (put.c >= 0)
    {
      if (put.cmd[put.c] == 1)
	put.nb += put.nb2;
      put.nb2 /= 2;
      --put.c;
    }
  my_putchar(str[put.nb]);
}

void		print_memory(t_mem *arena, char *str)
{
  int		i;
  int		j;

  i = 0;
  while (i < MEM_SIZE)
    {
      j = 0;
      while (j < 32 && i < MEM_SIZE)
	{
	  my_putchar(' ');
	  put_it(i, str, arena);
	  ++j;
	  ++i;
	}
      my_putchar('\n');
    }
  exit(0);
}
