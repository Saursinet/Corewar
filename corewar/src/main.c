/*
** corewar.c for corewar in /home/saursf/rendu/CPE_2014_corewar/src
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Wed Mar 11 11:19:22 2015 Florian Saurs
** Last update Wed Apr 15 07:10:14 2015 Florian Saurs
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

int		main(int ac, char **av)
{
  t_list	*champion;
  int		nbr_cycle;

  champion = NULL;
  (ac < 3 ? put_error_main() : (void)0);
  nbr_cycle = take_dump(av);
  take_header(&champion, av, 1);
  while (champion->cmpt != 0)
    champion = champion->next;
  create_arena(champion, nbr_cycle);
  return (0);
}
