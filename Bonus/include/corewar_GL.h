/*
** corewar_GL.h for  in /home/veyrie_f/rendu/CPE_2014_corewar/interface
** 
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
** 
** Started on  Fri Mar 27 20:25:56 2015 fernand veyrier
** Last update Thu Apr 16 23:28:25 2015 fernand veyrier
*/

#ifndef COREWAR_GL_H
# define COREWAR_GL_H

# include <math.h>
# include "SDL.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"
# include "glu.h"
# include "gl.h"
# include "glut.h"
# include "types.h"

# define WIDTH		1920
# define HEIGHT		1080
# define ERROR_SDL	fprintf(stderr, "SDL/OpenGL function failed.\n")
# define ERROR_TFF	fprintf(stderr, "TTF function failed.\n")
# define ERROR_SOUND	fprintf(stderr, "Sound load failed.\n")

typedef struct	s_vector3
{
  GLfloat	x;
  GLfloat	y;
  GLfloat	z;
}		t_vector3;

typedef struct	s_color
{
  GLfloat	r;
  GLfloat	g;
  GLfloat	b;
  GLfloat	a;
}		t_color;

typedef struct	s_sound
{
  Mix_Chunk	*music;
  Mix_Chunk	*victory;
  Mix_Chunk	*holyshit;
  Mix_Chunk	*play;
  Mix_Chunk	*firstblood;
  Mix_Chunk	*doublekill;
  Mix_Chunk	*triplekill;
}		t_sound;

typedef struct	s_aff
{
  int		_continue;
  int		game_over;
  SDL_Event	event;
  int		rank;
  GLuint	text[14];
  char		champs[4];
}		t_aff;

/*
**	gl_handler.c
*/

SDL_Surface	*init_screen(int size_x, int size_y, char *windows_name);
void		set_GL_params();
void		add_position_light(GLfloat x, GLfloat y, GLfloat z, int index);
TTF_Font	*police_saved(int i);

/*
**	corewar_GL.c
*/

void		draw_memory(int rank_up, t_mem *arena,
			    char *champs, int game_over);
void		start_anim(GLuint *text, t_mem *arena, char *champs);
int		init_memory(t_vector3 *pos, t_color *color);

/*
**	gui.c
*/

void		draw_gui(GLuint text_id, t_color color,
			 t_vector3 pos, GLfloat police_size);
GLuint		get_ttf(char *text);
GLuint		loadTexture(SDL_Surface *text);
void		draw_texture(GLuint texture_id, t_color color,
			     t_vector3 pos, t_vector3 size);
void		disable_gui_drawing();
void		get_mask(Uint32 *rmask, Uint32 *gmask,
			 Uint32 *bmask, Uint32 *amask);
GLuint		texture_loaded(SDL_Surface *gl_surface,
			       SDL_Surface *text,
			       GLuint glID);

/*
**	drawing.c
*/

void		draw_image_textures(GLuint *text, char *champs);
void		draw_sphere(t_vector3 pos, t_color color, GLfloat size);
void		draw_gui_textures(GLuint *text);
void		disp_game_over(GLuint *text);

/*
**	sound.c
*/

int		init_sound(t_sound *sounds);
void		free_audio(t_sound *sounds);
int		play_sound(Mix_Chunk *sound);
int		play_music(Mix_Chunk *music);

/*
**	init.c
*/

int		init_memory(t_vector3 *pos, t_color *color);
void		init_display_screen(t_aff *aff,
				    t_champ *champion,
				    t_mem *arena);
void		get_all_textures(GLuint *text, t_champ *champion);
void		get_player_color(t_color *color, int player_id, int head);
void		init_audio(t_sound *sounds);

/*
**	other
*/

void		create_arena(t_list *list, int nbr_cycle, t_sound sounds);
void		start_game(t_mem *arena, t_champ *champs,
			   t_game game, t_sound sound);
int		take_dump(char **av);
void		quake_sounds(t_sound sound, char *alive);
void		refresh_buffer(int option, t_aff *aff);
void		game_begins(t_game *game, t_champ *champion,
			    t_win *champ, t_sound sound);
void		game_play(t_mem *arena, t_champ *champion, t_game *game);

#endif /* !COREWAR_GL_H */
