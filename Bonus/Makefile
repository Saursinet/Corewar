##
## Makefile for  in /home/veyrie_f/Documents/LIbSDL
## 
## Made by fernand veyrier
## Login   <veyrie_f@epitech.net>
## 
## Started on  Fri Mar 27 12:23:19 2015 fernand veyrier
## Last update Thu Apr 16 22:53:31 2015 fernand veyrier
##

CC		= gcc -O2

RM		= rm -f

NAME		= corewar

SRCS		= src/corewar_GL.c		\
		  src/gl_handler.c		\
		  src/gui.c			\
		  src/gui_next.c		\
		  src/drawing.c			\
		  sound/sound.c			\
		  src/player_color.c		\
		  src/init.c			\
		  vm/src/main.c			\
		  vm/src/my_put.c		\
		  vm/src/my_str.c		\
		  vm/src/init_my_list.c		\
		  vm/src/my_error.c		\
		  vm/src/arena.c		\
		  vm/src/game.c			\
		  vm/src/my_getnbr.c		\
		  vm/src/str.c			\
		  vm/src/my_ld_funct.c		\
		  vm/src/my_ldi_funct.c		\
		  vm/src/my_st_funct.c		\
		  vm/src/better_funct.c		\
		  vm/src/operate_funct.c	\
		  vm/src/my_arg_in_funct.c	\
		  vm/src/my_fork_funct.c	\
		  vm/src/init_all.c		\
		  vm/src/my_end_funct.c		\
		  vm/src/print_my_memory.c	\
		  vm/src/my_lld_funct.c		\
		  vm/src/try.c			\
		  vm/src/my_list.c		\
		  vm/src/my_sti_funct.c		\
		  vm/src/my_end.c		\
		  vm/src/delegate.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -I./SDL/include -L ./SDL/lib -lSDL -lSDL_ttf -lSDL_sound -lSDL_mixer -I./opengl/include -L./opengl/lib -lGLU -lGL -L./opengl/ -lglut -I./include -Wall -Wextra -lm -I./vm/include

$(NAME):	$(OBJS)

		$(CC) -o $(NAME) $(OBJS) $(LIB) $(CFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
