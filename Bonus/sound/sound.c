/*
** sound.c for sound in /home/noboud_n/rendu/CPE/CPE_2014_corewar/SDL
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Tue Mar 31 13:39:57 2015 Nyrandone Noboud-Inpeng
** Last update Sun Apr 12 18:07:36 2015 fernand veyrier
*/

#include <stdio.h>
#include <stdlib.h>
#include "corewar_GL.h"

void		free_audio(t_sound *sounds)
{
  if (sounds->play != NULL)
    Mix_FreeChunk(sounds->play);
  if (sounds->music != NULL)
    Mix_FreeChunk(sounds->music);
}

int		play_sound(Mix_Chunk *sound)
{
  if ((Mix_PlayChannel(-1, sound, 0)) == -1)
    return (fprintf(stderr, "Play failed.\n"));
  return (0);
}

int		play_music(Mix_Chunk *music)
{
  if (Mix_PlayChannel(-1, music, -1) == -1)
    return (ERROR_SOUND);
  return (0);
}

int		init_sound(t_sound *sounds)
{

  init_audio(sounds);
  if (Mix_PlayChannel(-1, sounds->music, -1) == -1)
    return (ERROR_SOUND);
  if (sounds->play == NULL || sounds->holyshit == NULL
      || sounds->firstblood == NULL || sounds->doublekill == NULL
      || sounds->triplekill == NULL)
    return (ERROR_SOUND);
  return (0);
}
