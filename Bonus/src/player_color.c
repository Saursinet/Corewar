/*
** player_color.c for  in /home/veyrie_f/rendu/CPE_2014_corewar/Bonus
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Fri Apr 10 23:19:28 2015 fernand veyrier
** Last update Thu Apr 16 22:16:31 2015 fernand veyrier
*/

#include "corewar_GL.h"

void		get_player_color_next(t_color *color, int player_id, int head)
{
  if (player_id == 4)
    {
      color->r = 1 + 255 * (head != 0 ? 1 : 0);
      color->g = 0;
      color->b = 1 + 255 * (head != 0 ? 1 : 0);
    }
  else
    {
      color->r = 0.7f;
      color->g = 0.7f;
      color->b = 0;
    }
}

void		get_player_color(t_color *color, int player_id, int head)
{
  color->a = 0;
  if (player_id == 1)
    {
      color->r = 1 + 255 * (head != 0 ? 1 : 0);
      color->g = 0;
      color->b = 0;
    }
  else if (player_id == 2)
    {
      color->r = 0;
      color->g = 1.2f + 255 * (head != 0 ? 1 : 0);
      color->b = 1  + 255 * (head != 0 ? 1 : 0);
    }
  else if (player_id == 3)
    {
      color->r = 0;
      color->g = 0;
      color->b = 1 + 255 * (head != 0 ? 1 : 0);
    }
  else
    get_player_color_next(color, player_id, head);
}

void		draw_sphere(t_vector3 pos, t_color color, GLfloat size)
{
  GLUquadric	*params;

  glPushMatrix();
  params = gluNewQuadric();
  glColor4f(color.r, color.g, color.b, color.a);
  glTranslated(pos.x, pos.y, pos.z);
  gluSphere(params, size, 4, 4);
  gluDeleteQuadric(params);
  glPopMatrix();
}
