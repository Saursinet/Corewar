/*
** my_sti_funct.c for corewar in /home/saursf/rendu/CPE_2014_corewar/corewar
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Thu Apr 16 00:05:34 2015 Florian Saurs
** Last update Thu Apr 16 02:18:14 2015 Florian Saurs
*/

#include "types.h"

void		put_int(int c, int nb, t_mem *arena, int id)
{
  arena[c % MEM_SIZE].cmd = nb >> 24;
  arena[c % MEM_SIZE].player_id = id;
  ++c;
  nb = nb << 8;
  nb = nb >> 8;
  arena[c % MEM_SIZE].cmd = nb >> 16;
  arena[c % MEM_SIZE].player_id = id;
  ++c;
  nb = nb << 16;
  nb = nb >> 16;
  arena[c % MEM_SIZE].cmd = nb >> 8;
  arena[c % MEM_SIZE].player_id = id;
  ++c;
  nb = nb << 24;
  nb = nb >> 24;
  arena[c % MEM_SIZE].cmd = nb;
  arena[c % MEM_SIZE].player_id = id;
}

void		my_sti_next(t_decal *par, char cmd[8], t_win *my_are, int i)
{
  int		pos;

  if (cmd[3] == 0 && cmd[2] == 1)
    {
      par->my_reg2 =
	my_are->champion->registry[tern((int)my_are->arena[(par->ret + i + 3) %
							   MEM_SIZE].cmd)];
      par->ret += 1;
    }
  else if (cmd[3] == 1 && cmd[2] == 0)
    {
      pos = my_decal_of_two(my_are->arena, par->ret + i + 3);
      while ((pos + i) < 0)
	pos = MEM_SIZE + pos;
      par->my_reg2 = pos;
      par->ret += 2;
    }
}

void		my_sti(t_decal *par, char cmd[8], t_win *my_are, int i)
{
  int		pos;

  if ((cmd[5] == 0) && (cmd[4] == 1))
    {
      par->my_reg =
	my_are->champion->registry[tern((int)my_are->arena[(i + 3) %
							   MEM_SIZE].cmd)];
      par->ret += 1;
    }
  else if ((cmd[5] == 1 && cmd[4] == 0) || (cmd[5] == 1 && cmd[4] == 1))
    {
      pos = my_decal_of_two(my_are->arena, i + 3);
      while ((pos + i) < 0)
	pos = MEM_SIZE + pos;
      par->my_reg = pos;
      par->ret += 2;
    }
  my_sti_next(par, cmd, my_are, i);
}

int		do_sti(t_mem *arena, int i, t_champ *champion)
{
  t_decal	par;
  t_win		my_arena;

  par.c = 0;
  while (par.c < 8)
    {
      par.cmd[par.c] = (arena[(i + 1) % MEM_SIZE].cmd >> par.c) % 2;
      ++par.c;
    }
  par.ret = 0;
  my_arena.champion = champion;
  my_arena.arena = arena;
  if ((par.cmd[7] == 0) && (par.cmd[6] == 1))
    {
      my_sti(&par, par.cmd, &my_arena, i);
      champion = my_arena.champion;
      arena = my_arena.arena;
      par.c = (i + par.my_reg + par.my_reg2);
      par.c = my_neg_value(par.c);
      put_int(par.c, (champion->registry[tern((int)arena[i + 2].cmd)]), arena,
	      champion->player_id);
    }
  champion->cycles_to_next = 25;
  return (par.ret + 3);
}
