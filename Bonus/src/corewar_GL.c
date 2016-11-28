/*
** sphere.c for  in /home/veyrie_f/rendu/CPE_2014_corewar/interface
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Fri Mar 27 17:43:28 2015 fernand veyrier
** Last update Mon Apr 13 22:16:16 2015 fernand veyrier
*/

#include "corewar_GL.h"
#include "types.h"

void		start_anim_drawing(t_vector3 pos, t_color color,
				   int frames, t_mem *arena)
{
  int		pos_arena;
  int		i;
  int		j;

  i = -1;
  j = 0;
  pos_arena = 0;
  while (++i < 48)
    {
      while (j < 128)
	{
	  pos.z = cos(i / (30. - frames / 4.2)) * 4 - (frames / 23.);
	  pos.z = (pos.z < cos(j * i * 0.001f)) ?
	    cos(j * i * 0.001f) : pos.z;
	  get_player_color(&color, arena[pos_arena].player_id,
			   arena[pos_arena].head);
	  draw_sphere(pos, color, 0.1f);
	  pos.x += 0.3f;
	  ++j;
	  ++pos_arena;
	}
      pos.x = 0;
      pos.y += 0.3f;
      j = 0;
    }
}

void		start_anim(GLuint *text, t_mem *arena, char *champs)
{
  int		frames;
  t_vector3	pos;
  t_color	color;

  frames = init_memory(&pos, &color);
  while (frames < 67)
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      draw_image_textures(text, champs);
      draw_gui_textures(text);
      pos.y = 0;
      start_anim_drawing(pos, color, frames, arena);
      ++frames;
      glFlush();
      SDL_GL_SwapBuffers();
    }
}

void		disp_game_over(GLuint *text)
{
  t_color	color;
  t_vector3	pos;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  color.a = 1;
  pos.x = 0;
  pos.y = 0.5f;
  pos.z = 0;
  draw_gui(text[0], color, pos, 1);
}

int		main(int ac, char **av)
{
  t_sound	sounds;
  t_list	*champion;
  int		nbr_cycle;

  champion = NULL;
  (ac < 3 ? put_error_main() : (void)0);
  nbr_cycle = take_dump(av);
  take_header(&champion, av, 1);
  init_screen(WIDTH, HEIGHT, "Corewar");
  set_GL_params();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(0, 4, 2, 0, 0, 0, 0, 0, 1);
  add_position_light(-10000, 0, 0, GL_LIGHT0);
  glTranslated(-19, -23, -0.4);
  glRotated(-20, 1, 0, 0);
  init_sound(&sounds);
  while (champion->cmpt != 0)
    champion = champion->next;
  create_arena(champion, nbr_cycle, sounds);
  Mix_CloseAudio();
  TTF_Quit();
  SDL_Quit();
  return (0);
}
