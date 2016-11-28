/*
** gui.c for  in /home/veyrie_f/rendu/CPE_2014_corewar/interface
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Mon Mar 30 13:08:07 2015 fernand veyrier
** Last update Wed Apr  8 18:14:43 2015 fernand veyrier
*/

#include "corewar_GL.h"

GLuint			loadTexture(SDL_Surface *text)
{
    GLuint		glID;
    SDL_Surface		*gl_surface;
    Uint32		rmask;
    Uint32		gmask;
    Uint32		bmask;
    Uint32		amask;
    SDL_PixelFormat	format;

    (text == NULL) ? exit(fprintf(stderr, "Failed to load image.\n")) : 0;
    get_mask(&rmask, &gmask, &bmask, &amask);
    format = *(text->format);
    format.BitsPerPixel = 32;
    format.BytesPerPixel = 4;
    format.Rmask = rmask;
    format.Gmask = gmask;
    format.Bmask = bmask;
    format.Amask = amask;
    gl_surface = SDL_ConvertSurface(text, &format, SDL_SWSURFACE);
    glGenTextures(1, &glID);
    glBindTexture(GL_TEXTURE_2D, glID);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, gl_surface->w, gl_surface->h,
		 0, GL_RGBA, GL_UNSIGNED_BYTE, gl_surface->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    return (texture_loaded(gl_surface, text, glID));
}

GLuint		get_ttf(char *text)
{
  SDL_Surface	*text_surface;
  SDL_Color	color;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  if ((text_surface = TTF_RenderText_Solid(police_saved(1),
					   text, color)) == NULL)
    exit(fprintf(stderr, "Failed to render text.\n"));
  return (loadTexture(text_surface));
}

void		draw_texture(GLuint texture_id, t_color color,
			     t_vector3 pos, t_vector3 size)
{
  glPushMatrix();
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);
  glEnable(GL_TEXTURE_2D);
  glLoadIdentity();
  gluLookAt(0, 2, 0, 0, 0, 0, 0, 0, 1);
  glBindTexture(GL_TEXTURE_2D, texture_id);
  glTranslated(-pos.x, 0, pos.y);
  glBegin(GL_QUADS);
  glColor4f(color.r, color.g, color.b, color.a);
  glTexCoord2d(0, 1);
  glVertex3d(size.x, -1, -size.y);
  glTexCoord2d(0, 0);
  glVertex3d(size.x, -1, size.y);
  glTexCoord2d(1, 0);
  glVertex3d(-size.x, -1, size.y);
  glTexCoord2d(1, 1);
  glVertex3d(-size.x, -1, -size.y);
  glEnd();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}

void		draw_gui(GLuint text_id, t_color color,
			 t_vector3 pos, GLfloat police_size)
{
  glPushMatrix();
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);
  glEnable(GL_BLEND);
  glEnable(GL_TEXTURE_2D);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glLoadIdentity();
  gluLookAt(0, 2, 0, 0, 0, 0, 0, 0, 1);
  glBindTexture(GL_TEXTURE_2D, text_id);
  glTranslated(-pos.x, 0, pos.y);
  glBegin(GL_QUADS);
  glColor3ub(color.r, color.g, color.b);
  glTexCoord2d(0, 1);
  glVertex3d(2, -police_size, -1);
  glTexCoord2d(0, 0);
  glVertex3d(2, -police_size, 1);
  glTexCoord2d(1, 0);
  glVertex3d(-2, -police_size, 1);
  glTexCoord2d(1, 1);
  glVertex3d(-2, -police_size, -1);
  glEnd();
  disable_gui_drawing();
  glPopMatrix();
}
