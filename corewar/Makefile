##
## Makefile for corewar in /home/saursf/rendu/CPE_2014_corewar
## 
## Made by Florian Saurs
## Login   <saurs_f@epitech.net>
## 
## Started on  Wed Mar 11 11:17:29 2015 Florian Saurs
##

CC		= gcc

CFLAGS		+= -I./../include
CFLAGS		+= -Wall -Wextra -W
CFLAGS		+= -ansi -pedantic

RM		= rm -f

NAME		= corewar

SRCS		= main.c		\
		  my_put.c		\
		  my_str.c		\
		  init_my_list.c	\
		  my_list.c		\
		  my_error.c		\
		  arena.c		\
		  game.c		\
		  my_getnbr.c		\
		  str.c			\
		  my_ld_funct.c		\
		  my_ldi_funct.c	\
		  my_st_funct.c		\
		  my_sti_funct.c	\
		  better_funct.c	\
		  operate_funct.c	\
		  my_arg_in_funct.c	\
		  my_fork_funct.c	\
		  init_all.c		\
		  print_my_memory.c	\
		  my_lld_funct.c	\
		  try.c			\
		  my_end.c		\

SDIR		= src
ODIR		= obj

OBJS		= $(addprefix $(ODIR)/, $(SRCS:.c=.o))

$(ODIR)/%.o: $(SDIR)/%.c
	@if [ ! -d $(ODIR) ] ; then mkdir $(ODIR) ; fi
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@if [ -d $(ODIR) ] ; then rmdir $(ODIR) ; fi

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
