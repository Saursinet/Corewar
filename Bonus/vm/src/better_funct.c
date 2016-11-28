/*
** better_funct.c for corewar in /home/saursf/rendu/CPE_2014_corewar/vm/src
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Mon Mar 23 17:32:51 2015 Florian Saurs
** Last update Thu Apr 16 23:01:44 2015 fernand veyrier
*/

#include "types.h"

int		do_live(t_mem *arena, t_champ *champion, int *nbr_live,
			t_game *game)
{
  static int	c = 0;
  int		live;
  int		a;
  int		i;

  ++c;
  i = champion->PC;
  *nbr_live = c;
  live = 0;
  live = arena[(i + 1) % MEM_SIZE].cmd;
  live = live << 8;
  live = live + arena[(i + 2) % MEM_SIZE].cmd;
  live = live << 8;
  live = live + arena[(i + 3) % MEM_SIZE].cmd;
  live = live << 8;
  live = live + arena[(i + 4) % MEM_SIZE].cmd;
  a = 0;
  while (game->champ_alive[a][0] != -2 && game->champ_alive[a][0] != live)
    ++a;
  if (game->champ_alive[a][0] != -2 && game->champ_alive[a][1] != -1)
    ++game->champ_alive[a][1];
  champion->cycles_to_next = 10;
  return (5);
}

int		take_neg_value(t_mem *arena, int i, char cmd[16])
{
  int		jump;

  if (cmd[15] == 1)
    {
      jump = 0;
      jump =
	((arena[(i + 1) % MEM_SIZE].cmd) << 8) + arena[(i + 2) % MEM_SIZE].cmd;
      return ((-(65536 - jump)) % IDX_MOD);
    }
  else
    {
      jump =
	((arena[(i + 1) % MEM_SIZE].cmd) << 8) + arena[(i + 2) % MEM_SIZE].cmd;
    }
  return (jump % IDX_MOD);
}

int		do_zjmp(t_mem *arena, int i, t_champ *champion)
{
  int		jump;
  char		cmd[16];
  int		c;

  c = 0;
  jump = 0;
  while (c < 8)
    {
      cmd[c] = (arena[(i + 2) % MEM_SIZE].cmd >> c) % 2;
      ++c;
    }
  while (jump < 8)
    {
      cmd[c] = (arena[(i + 1) % MEM_SIZE].cmd >> jump++) % 2;
      ++c;
    }
  champion->cycles_to_next = 20;
  if (champion->carry == 1)
    return (take_neg_value(arena, i, cmd));
  return (3);
}

int		do_aff(unused t_mem *arena, unused int i, t_champ *champion)
{
  champion->cycles_to_next = 2;
  return (3);
}
