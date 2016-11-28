/*
** my_end_funct.c for corewar in /home/saursf/rendu/CPE_2014_corewar/vm
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Sat Apr 11 19:27:07 2015 Florian Saurs
** Last update Thu Apr 16 14:08:27 2015 fernand veyrier
*/

#include "corewar_GL.h"

char		last_dead[4] = {1, 1, 1, 1};

void		init_quake(char *alive, unused int first)
{
  last_dead[0] = alive[0];
  last_dead[1] = alive[1];
  last_dead[2] = alive[2];
  last_dead[3] = alive[3];
}

void		quake_sounds(t_sound sound, char *alive)
{
  static int	sound_nbr = 0;
  static int	first_round = 0;

  if (first_round == 0)
    init_quake(alive, ++first_round);
  if (alive[0] == 0 && alive[1] == 0 && alive[2] == 0 && alive[3] == 0)
    return ;
  if (last_dead[0] != alive[0] || last_dead[1] != alive[1]
      || last_dead[2] != alive[2] || last_dead[3] != alive[3])
    {
      last_dead[0] = alive[0];
      last_dead[1] = alive[1];
      last_dead[2] = alive[2];
      last_dead[3] = alive[3];
      if (sound_nbr == 0)
	play_sound(sound.firstblood);
      else if (sound_nbr == 1)
	play_sound(sound.doublekill);
      else if (sound_nbr == 2)
	play_sound(sound.triplekill);
      ++sound_nbr;
    }
}
