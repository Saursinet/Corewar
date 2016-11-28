/*
** corewar.c for corewar in /home/saursf/rendu/CPE_2014_corewar/src
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Wed Mar 11 11:19:22 2015 Florian Saurs
** Last update Thu Apr 16 13:30:09 2015 fernand veyrier
*/

#include "types.h"

int		take_dump(char **av)
{
  int		i;
  int		cmpt;

  cmpt = 0;
  i = 0;
  while (av[i])
    {
      if (av[i] && my_strncmp("-dump", av[i], 5) == 0)
	++cmpt;
      ++i;
    }
  if (cmpt > 1)
    put_error_main();
  if (cmpt == 1)
    {
      i = 1;
      while (av[i] && my_strncmp("-dump", av[i], 5) != 0)
	++i;
      if (av[++i])
	cmpt = my_getnbr(av[i]);
      else
	put_error_main();
      return (cmpt);
    }
  return (-1);
}
