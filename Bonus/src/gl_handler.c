/*
** gl_handler.c for  in /home/veyrie_f/rendu/CPE_2014_corewar/interface
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Fri Mar 27 20:28:12 2015 fernand veyrier
** Last update Thu Apr 16 15:38:14 2015 fernand veyrier
*/

#include "corewar_GL.h"

SDL_Surface	*init_screen(int size_x, int size_y, char *windows_name)
{
  SDL_Surface	*screen;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    exit(ERROR_SDL);
  screen = SDL_SetVideoMode(size_x, size_y, 32, SDL_OPENGL | SDL_FULLSCREEN);
  if (TTF_Init() == -1)
    exit(ERROR_TFF);
  if (screen == NULL)
    exit(ERROR_SDL);
  SDL_WM_SetCaption(windows_name, NULL);
  if (SDL_Flip(screen) == -1)
    exit(ERROR_SDL);
  return (screen);
}

TTF_Font		*police_saved(int i)
{
  static TTF_Font	*police;

  if (i == 0)
    {
      if ((police = TTF_OpenFont("./fonts/rexlia_rg.ttf", 1000)) == NULL)
	exit(fprintf(stderr, "Failed to open font.\n"));
    }
  return (police);
}

void		set_GL_params()
{
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  gluPerspective(70, (double)WIDTH/HEIGHT, 1, 1000);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glShadeModel(GL_SMOOTH);
  glMatrixMode(GL_MODELVIEW);
  police_saved(0);
}

void		add_position_light(GLfloat x, GLfloat y, GLfloat z, int index)
{
  GLfloat	position[4];

  glClearColor(0.0, 0.0, 0.0, 0.0);
  position[0] = x;
  position[1] = y;
  position[2] = z;
  position[3] = 1;
  glLightfv(index, GL_POSITION, position);
}
