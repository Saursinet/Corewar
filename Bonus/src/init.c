/*
** init.c for  in /home/veyrie_f/rendu/CPE_2014_corewar/Bonus
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Fri Apr  3 17:28:52 2015 fernand veyrier
** Last update Tue Apr 14 20:44:55 2015 fernand veyrier
*/

#include "corewar_GL.h"

int		init_memory(t_vector3 *pos, t_color *color)
{
  pos->x = 0;
  pos->y = 0;
  pos->z = 0;
  color->r = 1;
  color->g = 1;
  color->b = 0;
  color->a = 0;
  return (0);
}

void		init_display_screen(t_aff *aff,
				    t_champ *champion,
				    t_mem *arena)
{
  aff->champs[0] = 1;
  aff->champs[1] = 1;
  aff->champs[2] = 1;
  aff->champs[3] = 1;
  aff->_continue = 1;
  aff->rank = 0;
  aff->game_over = 0;
  get_all_textures(aff->text, champion);
  start_anim(aff->text, arena, aff->champs);
}

char		*cut_word(char *text)
{
  int		i;
  char		*to_get;

  i = 0;
  if (strlen(text) < 10)
    return (text);
  ((to_get = malloc(sizeof(char) * (strlen(text) + 2))) == NULL) ?
    exit(ERROR_MALLOC) : 0;
  while (i < 7 && text[i])
    {
      to_get[i] = text[i];
      ++i;
    }
  while (i < 10)
    to_get[i++] = '.';
  to_get[i] = 0;
  return (to_get);
}

void		get_all_textures(GLuint *text, t_champ *champion)
{
  text[0] = get_ttf("Game Over");
  text[1] = get_ttf(cut_word(champion->name));
  text[2] = get_ttf(champion->next != NULL ?
		    cut_word(champion->next->name) : " ");
  text[3] = get_ttf(champion->next != NULL && champion->next->next != NULL ?
		    cut_word(champion->next->next->name) : " ");
  text[4] = get_ttf(champion->next != NULL && champion->next->next != NULL
		    && champion->next->next->next != NULL ?
		    cut_word(champion->next->next->next->name) :" ");
  text[5] = loadTexture(SDL_LoadBMP("./textures/CorewarBackground.bmp"));
  text[8] = loadTexture(SDL_LoadBMP("./textures/noboud_n_cut.bmp"));
  text[6] = loadTexture(SDL_LoadBMP("./textures/combau_a_cut.bmp"));
  text[7] = loadTexture(SDL_LoadBMP("./textures/saurs_f_cut.bmp"));
  text[9] = loadTexture(SDL_LoadBMP("./textures/veyrie_f_cut.bmp"));
  text[10] = loadTexture(SDL_LoadBMP("./textures/noboud_n_cut_head.bmp"));
  text[11] = loadTexture(SDL_LoadBMP("./textures/combau_a_cut_head.bmp"));
  text[12] = loadTexture(SDL_LoadBMP("./textures/saurs_f_cut_head.bmp"));
  text[13] = loadTexture(SDL_LoadBMP("./textures/veyrie_f_cut_head.bmp"));
}

void		init_audio(t_sound *sounds)
{
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
		    MIX_DEFAULT_CHANNELS, 1024) == -1)
    fprintf(stderr, "Audio Error : %s", Mix_GetError());
  if ((sounds->music =
       Mix_LoadWAV("./sound/TheSwissBubbleBath.wav")) == NULL)
    exit(fprintf(stderr, "Failed to load sound.\n"));
  if ((sounds->victory = Mix_LoadWAV("./sound/Street_Fighter.wav")) == NULL)
    exit(fprintf(stderr, "Failed to load sound.\n"));
  sounds->play = Mix_LoadWAV("./sound/PLAY.wav");
  sounds->holyshit = Mix_LoadWAV("./sound/HOLY SHIT.wav");
  sounds->firstblood = Mix_LoadWAV("./sound/FIRST BLOOD.wav");
  sounds->doublekill = Mix_LoadWAV("./sound/DoubleKill.wav");
  sounds->triplekill = Mix_LoadWAV("./sound/TripleKill.wav");
}
