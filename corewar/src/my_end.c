/*
** my_end.c for corewar in /home/saursf/rendu/CPE_2014_corewar/corewar
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Thu Apr 16 01:48:50 2015 Florian Saurs
** Last update Fri Apr 17 01:41:11 2015 Florian Saurs
*/

#include "types.h"

void		print_champ(t_champ *champ, int i)
{
  if (champ)
    {
      my_putstr(champ->name);
      my_putstr(" :le champion numero ");
      my_put_nbr(champ->player_id);
      if (i == 1)
	my_putstr(" est en vie.\n");
      else if (i == 0)
	my_putstr(" a gagné.\n");
      else
	my_putstr(" est mort.\n");
    }
}

int		finito(t_game *game, t_win *champ, int tmp, int alive)
{
  int		i;

  if (alive == 1)
    {
      i = 0;
      while (game->champ_alive[i][0] != -2 && game->champ_alive[i][1] < 0)
	++i;
      if (game->champ_alive[i][0] == -2)
	{
	  my_putstr("There is no winner\n");
	  return (-1);
	}
      while (champ->first_champ && champ->first_champ->player_id !=
	     game->champ_alive[i][0])
	champ->first_champ = champ->first_champ->next;
      print_champ(champ->first_champ, 0);
      return (-1);
    }
  else if ((alive == 2 && tmp <= 0) || alive == 0)
    {
      my_putstr("There is no winner\n");
      return (-1);
    }
  return (tmp);
}
