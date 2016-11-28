/*
** game.c for  in /home/veyrie_f/rendu/CPE_2014_corewar
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat Mar 21 14:54:38 2015 fernand veyrier
** Last update Thu Apr 16 23:06:37 2015 fernand veyrier
*/

#include "corewar_GL.h"

int		refresh_vel = 200;
char		vars[5] = {0, 0, 0, 0, 0};

int		my_alive_champ(t_game *game, t_win *champ, int alive, int i)
{
  if (game->champ_alive[i][1] > 0)
    {
      while (champ->champion && champ->champion->player_id !=
	     game->champ_alive[i][0])
	champ->champion = champ->champion->next;
      ++alive;
      game->champ_alive[i][1] = 0;
      vars[i] = 1;
    }
  else
    {
      game->champ_alive[i][1] = -1;
      while (champ->champion && champ->champion->player_id !=
	     game->champ_alive[i][0])
	champ->champion = champ->champion->next;
      champ->champion->dead = 1;
      vars[i] = 0;
    }
  return (alive);
}

int		champion_alive(t_win *champ, int tmp,
			       int nbr_live, t_game *game)
{
  static int	total_cycle = 0;
  int		i;
  int		alive;

  i = -1;
  alive = 0;
  total_cycle = total_cycle + tmp;
  if (nbr_live >= 40)
    tmp -= CYCLE_DELTA;
  while (game->champ_alive[++i][0] != -2)
    {
      champ->champion = champ->first_champ;
      alive = my_alive_champ(game, champ, alive, i);
    }
  return (finito(game, champ, tmp, alive));
}

void		manage_events(t_aff *aff)
{
  SDL_Delay(1);
  while (SDL_PollEvent(&aff->event))
    {
      (aff->event.type == SDL_QUIT ||
       (aff->event.type == SDL_KEYDOWN
	&& aff->event.key.keysym.sym == SDLK_ESCAPE))
	? aff->_continue = 0 : 0;
      if (aff->event.type == SDL_KEYDOWN
	  && aff->event.key.keysym.sym == SDLK_LEFT)
	refresh_vel -= 50;
      if (aff->event.type == SDL_KEYDOWN
	  && aff->event.key.keysym.sym == SDLK_RIGHT)
	refresh_vel += 50;
      if (aff->event.type == SDL_KEYDOWN
	  && aff->event.key.keysym.sym == SDLK_UP)
	vars[0] = 0;
      refresh_vel = (refresh_vel < 1) ? 1 : refresh_vel;
    }
}

void		refresh_image(t_aff *aff, unused t_win *champ,
			      t_sound sound, t_mem *arena)
{
  if (vars[4] == 0)
    ++vars[4];
  else
    quake_sounds(sound, vars);
  manage_events(aff);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  draw_image_textures(aff->text, vars);
  draw_gui_textures(aff->text);
  draw_memory(aff->rank % 90, arena, aff->champs, aff->game_over - 1);
  ++aff->rank;
  aff->rank = (aff->rank > 20000) ? 0 : aff->rank;
  if (aff->game_over == 1)
    {
      Mix_FreeChunk(sound.music);
      play_music(sound.victory);
      aff->game_over = 2;
    }
  if (aff->game_over == 2)
    disp_game_over(aff->text);
}

void		start_game(t_mem *arena, t_champ *champion,
			   t_game game, t_sound sound)
{
  t_win		champ;
  t_aff		aff;

  init_display_screen(&aff, champion, arena);
  game_begins(&game, champion, &champ, sound);
  while (aff._continue == 1)
    {
      refresh_image(&aff, &champ, sound, arena);
      while (aff.game_over == 0 && aff._continue == 1
	     && (game.cycle_todie = champion_alive(&champ, game.cycle_todie,
						   game.nbr_live, &game)) > 0)
	{
	  champion = game.first_champ;
	  game.my_turn = 0;
	  while (aff._continue == 1 && game.my_turn < game.cycle_todie)
	    {
	      game_play(arena, champion, &game);
	      if (game.nb_turn % refresh_vel == 0)
		refresh_image(&aff, &champ, sound, arena);
	      (game.nb_turn % refresh_vel == 0) ? refresh_buffer(0, &aff) : 0;
	    }
	  ++game.i;
	}
      refresh_buffer(1, &aff);
    }
}
