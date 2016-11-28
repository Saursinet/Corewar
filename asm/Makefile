##
## Makefile for minishell2 in /media/blinux/noboud_n/rendu/PSU_2014_minishell2
## 
## Made by Nyrandone Noboud-Inpeng
## Login   <noboud_n@epitech.net>
## 
## Started on  Mon Feb 23 11:59:24 2015 Nyrandone Noboud-Inpeng
## Last update Mon Nov 28 11:30:46 2016 Florian Saurs
##

SRC	= main.c \
	  display_char.c \
	  free.c \
	  get_next_line.c \
	  linkedlists.c \
	  puterr.c \
	  my_getnbr.c \
	  getnbr_overflow.c \
	  store_file.c \
	  check_file.c \
	  header.c \
	  my_strcmp.c \
	  labels.c \
	  my_reallocs.c \
	  dictionnary.c \
	  store_list.c \
	  check_instructions.c \
	  exact_error.c \
	  is_in.c \
	  arguments.c \
	  actualize_message.c \
	  wrong_actualize.c \
	  warning.c \
	  separator.c \
	  argument_parsing.c \
	  parser_separator.c \
	  check_values.c \
	  error.c \
	  true_strcmp.c \
	  compare_arguments.c \
	  check_list.c \
	  direct_value.c \
	  indirect_value.c \
	  register.c \
	  live.c \
	  ld.c \
	  st.c \
	  add.c \
	  andorxor.c \
	  ldi.c \
	  lldi.c \
	  aff.c \
	  sti.c \
	  count_elem.c \
	  increment_value.c \
	  champion_name.c \
	  my_getnbr_base.c \
	  file_descriptor.c \
	  file_management.c \
	  search_argument.c \
	  search_label.c \
	  write_in_file.c \
	  convert.c \
	  header_write.c \
	  do_fcts.c \
	  error_header.c

OBJ	= $(addprefix $(OBJDIR), $(SRC:.c=.o))

RM	= rm -f

CC	= cc

NAME	= asm

OBJDIR	= obj/
SRCDIR	= src/
INCDIR	= -I ./../include/

MAKEOBJ	= obj

CFLAGS	= -Wall -Wextra -W -ansi -pedantic

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(MAKEOBJ)
	$(CC) $(CFLAGS) $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
