/*
** drawing.c for  in /home/veyrie_f/rendu/CPE_2014_corewar/interface
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Wed Apr  1 18:52:48 2015 fernand veyrier
** Last update Thu Apr 16 23:26:46 2015 fernand veyrier
*/

#include "corewar_GL.h"

void		draw_image_textures_next(GLuint *text, t_vector3 size,
					 t_color color_text, char *champs)
{
  t_vector3	pos_text;

  size.x = 0.27f;
  size.y = 0.4f;
  size.z = 0;
  pos_text.x = -0.7f;
  pos_text.y = -1.55f;
  pos_text.z = 0;
  draw_texture(text[champs[1] == 0 ? 12 : 7], color_text, pos_text, size);
  size.x = 0.27f;
  size.y = 0.4f;
  size.z = 0;
  pos_text.x = 0.8f;
  pos_text.y = -1.55f;
  pos_text.z = 0;
  draw_texture(text[champs[2] == 0 ? 10 : 8], color_text, pos_text, size);
  size.x = 0.27f;
  size.y = 0.4f;
  size.z = 0;
  pos_text.x = 2.2f;
  pos_text.y = -1.55f;
  pos_text.z = 0;
  draw_texture(text[champs[3] == 0 ? 13 : 9], color_text, pos_text, size);
}

void		draw_image_textures(GLuint *text, char *champs)
{
  t_vector3	size;
  t_color	color_text;
  t_vector3	pos_text;

  color_text.r = 255;
  color_text.g = 255;
  color_text.b = 255;
  color_text.a = 1;
  size.x = 3.9f;
  size.y = 2.1f;
  size.z = 0;
  pos_text.x = 0;
  pos_text.y = 0.06f;
  pos_text.z = 0;
  draw_texture(text[5], color_text, pos_text, size);
  size.x = 0.27f;
  size.y = 0.4f;
  size.z = 0;
  pos_text.x = -2.2f;
  pos_text.y = -1.55f;
  pos_text.z = 0;
  draw_texture(text[champs[0] == 0 ? 11 : 6], color_text, pos_text, size);
  draw_image_textures_next(text, size, color_text, champs);
}

void		draw_gui_textures_next(GLuint *text,
				       t_color color,
				       t_vector3 pos)
{
  draw_gui(text[2], color, pos, 10);
  pos.y = -4.4f;
  pos.x = 3;
  color.r = 0;
  color.g = 0;
  color.b = 185;
  draw_gui(text[3], color, pos, 10);
  pos.y = -4.4f;
  pos.x = 9;
  color.r = 185;
  color.g = 0;
  color.b = 185;
  draw_gui(text[4], color, pos, 10);
}

void		draw_gui_textures(GLuint *text)
{
  t_color	color;
  t_vector3	pos;

  color.r = 185;
  color.g = 0;
  color.b = 0;
  color.a = 1;
  pos.y = -4.4f;
  pos.x = -9;
  pos.z = 0;
  draw_gui(text[1], color, pos, 10);
  pos.y = -4.4f;
  pos.x = -3;
  color.r = 0;
  color.g = 225;
  color.b = 225;
  draw_gui_textures_next(text, color, pos);
}

void		draw_memory(int rank_up, t_mem *arena,
			    unused char *champs, int game_over)
{
  int		pos_arena;
  int		i;
  int		j;
  t_vector3	pos;
  t_color	color;

  j = init_memory(&pos, &color) - 1;
  i = -1;
  pos_arena = 0;
  while (++i < 48)
    {
      while (++j < 128)
	{
	  pos.z = cos(j * i * 0.001f + rank_up * M_PI * 0.022f);
	  get_player_color(&color, arena[pos_arena].player_id,
			   arena[pos_arena].head);
	  (game_over == 1) ? color.r = (pos.z > 0.9f) ? 255 : color.r : 0;
	  draw_sphere(pos, color, 0.1f);
	  pos.x += 0.3f;
	  ++pos_arena;
	}
      pos.x = 0;
      pos.y += 0.3f;
      j = -1;
    }
}
