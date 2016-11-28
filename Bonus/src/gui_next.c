/*
** gui_next.c for  in /home/veyrie_f/rendu/CPE_2014_corewar/interface
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Wed Apr  1 18:33:42 2015 fernand veyrier
** Last update Wed Apr  1 18:35:22 2015 fernand veyrier
*/

#include "corewar_GL.h"

void		disable_gui_drawing()
{
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glDisable(GL_BLEND);
  glDisable(GL_TEXTURE_2D);
}

void		get_mask(Uint32 *rmask, Uint32 *gmask,
			 Uint32 *bmask, Uint32 *amask)
{
  if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
    {
      *rmask = 0xff000000;
      *gmask = 0x00ff0000;
      *bmask = 0x0000ff00;
      *amask = 0x000000ff;
    }
  else
    {
      *rmask = 0x000000ff;
      *gmask = 0x0000ff00;
      *bmask = 0x00ff0000;
      *amask = 0xff000000;
    }
}

GLuint		texture_loaded(SDL_Surface *gl_surface,
			       SDL_Surface *text,
			       GLuint glID)
{
    SDL_FreeSurface(gl_surface);
    SDL_FreeSurface(text);
    return (glID);
}
