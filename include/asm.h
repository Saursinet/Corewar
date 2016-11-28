/*
** corewar.h for corewar in /home/noboud_n/rendu/CPE/Corewar/inc
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
**
** Started on  Wed Mar 11 13:17:08 2015 Nyrandone Noboud-Inpeng
** Last update Thu Apr 16 23:22:33 2015 Nyrandone Noboud-Inpeng
*/

#ifndef ASM_H_
# define ASM_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "op.h"

# define MALLOC_SIZE 20
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\x1B[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[37m"
# define DEFAULT "\033[0m"
# define BOLD "\033[1m"

typedef struct	s_list
{
  struct s_list	*next;
  struct s_list	*prev;
  int		nbr_arg;
  int		len_data;
  char		**args;
  char		*data;
  char		*label;
  int		lab;
  int		name;
  int		comment;
}		t_list;

typedef struct	s_args
{
  int		x;
  int		k;
  int		y;
  int		save;
  int		error_lab;
  int		error_dict;
  int		lab_true;
  int		dict_true;
  int		check;
  int		line;
  t_list	*tmp;
}		t_args;

typedef struct	s_pars
{
  int		i;
  int		fsd;
  int		check;
}		t_pars;

typedef struct	s_hexa
{
  int		a;
  int		ld;
  int		count;
  int		check;
  int		sd;
  int		y;
  int		h;
  char		*tmp2;
}		t_hexa;

/*
** main.c
*/
void	compilation_started(char *, int);
void	compilation_finished(char *, char **, int);
int	compilation_stopped(int, char **, int);

/*
** get_next_line.c
*/
char	*my_realloc(char *, int);

/*
** linkedlists.c
*/
int	my_strlen(char *);
t_list	*init_list();
t_list	*add_data(t_list *, char *);

/*
** puterr.c
*/
void	*put_error(char *);

/*
** free.c
*/
int	intfree_list(t_list *);
void	*free_list(t_list *);
char	**free_tab(char **);

/*
** display_char.c
*/
void	my_putchar(char);
void	my_put_err(char);
int	my_putstr(char *);
int	my_puterr(char *);
void	my_put_nbr(int);

/*
** store_file.c
*/
t_list	*store_file(char *);

/*
** header.c
*/
int	check_header(int, t_list *, int);

/*
** check_file.c
*/
char	**check_file(t_list *);

/*
** labels.c
*/
char	**label_in_list(int, int *, t_list *, char **);
char	**check_label(int, t_list *, char **);

/*
** my_reallocs.c
*/
char	**my_realloc_dd(char **, int, int);

/*
** dictionnary.c
*/
void	dictionnary(char **);
void	dictionnary_order(char **);
int	*dictionnary_hexa(int *);

/*
** my_strcmp.c
*/
int	strcmp_instructions(char *, t_list *, t_list *, int);
int	custom_strcmp(char *, char *);
int	my_strcmp(char *, char *);

/*
** store_list.c
*/
char	*fill_line(char *);

/*
** check_instructions.c
*/
int	check_instructions(t_list *);

/*
** exact_error.c
*/
int	exact_error(t_list *, int, char *);
int	wrong_instruction(int, int, t_list *, t_list *);
int	wrong_label(int, int, t_list *, t_list *);
int	invalid_line(t_list *, int, int, int);

/*
** is_in.c
*/
int	char_in_string(char, char *);

/*
** arguments.c
*/
int	check_arguments(t_list *);
int	strcmp_extend(char *, char *, int);

/*
** actualize_message.c
*/
void	header_ok();
void	instructions_ok();
void	number_arg_ok();
void	arguments_ok();
void	transform_ok(char *);

/*
** wrong_actualize.c
*/
void	header_wrong();
void	instructions_wrong();
void	number_arg_wrong();
void	arguments_wrong();

/*
** warning.c
*/
int	warning_idxmod(int);
int	attribute_nbr_arg(t_list *, int);

/*
** separator.c
*/
int	row_separator(int);
int	no_arg_after_separator(t_list *, int, int);

/*
** parser_separator.c
*/
int	count_elem(t_list *);
int	parser_separator(t_list *);

/*
** argument_parsing.c
*/
int	argument_parsing(t_list *, t_list *);

/*
** check_values.c
*/
int	check_values(t_list *);

/*
** error.c
*/
int	wrong_arguments(int, t_list *);

/*
** true_strcmp.c
*/
int	strncmp_b(char *, char *, int, int);
int	true_strcmp(char *, char *);
int	initialized_strcmp(int, char *, char *);
int	my_strncmp(int, char *, char *);
int	strcmp_asm(char *, char *);

/*
** compare_arguments.c
*/
int	compare_arguments(t_list *, t_list *, int, char *dict[17]);

/*
** check_list.c
*/
int	check_lists(t_list *, char *);

/*
** direct_value.c
*/
int	check_hexa(char *, int, int);
int	check_direct(t_list *, char *, int);

/*
** indirect_value.c
*/
int	compare_lab_to_args(t_list *, char *, int);
int	check_indirect(t_list *, char *, int);

/*
** register.c
*/
int	check_register(char *, int);

/*
** live.c
*/
int	live(t_list *, t_list *, int);
int	error_argument(int, char *);

/*
** ld.c
*/
int	ld(t_list *, t_list *, int);

/*
** st.c
*/
int	st(t_list *, t_list *, int);

/*
** add.c
*/
int	add(t_list *, t_list *, int);

/*
** andorxor.c
*/
int	andorxor(t_list *, t_list *, int);

/*
** ldi.c
*/
int	ldi(t_list *, t_list *, int);

/*
** sti.c
*/
int	sti(t_list *, t_list *, int);

/*
** lldi.c
*/
int	lldi(t_list *, t_list *, int);

/*
** aff.c
*/
int	aff(t_list *, t_list *, int);

/*
** count_elem.c
*/
int	count_elem_line(int, t_list **, t_list *);

/*
** increment_value.c
*/
int	increment_value_elem(t_list *, int);

/*
** champion_name.c
*/
int	champion_name(char *);
char	*get_champion_name(char *);

/*
** file_descriptor.c
*/
void	my_putchar_fd(char, int);
void	search_hexa(char *, int);
int	my_dec_to_hex(int);
int	my_strlen_double(char **);
int	check_label_asm(t_list **, char *);

/*
** file_management.c
*/
int	size_prog(int, int, t_list **);
int	prog_name(int, int, t_list **, t_list **);
void	header(int, t_list **, t_list **);
int	registre_hexa(char *, t_list *, int, int);
void	padding_byte_encoding(char (*stock)[9], int);

/*
** search_argument.c
*/
void	byte_encoding(int, t_list *, int, int);
void	search_argument(t_list **, int *, int *);
void	search_argument_neg(t_list **, int *, int *);

/*
** search_label.c
*/
int	search_label(t_list **, t_list **, char *, int);
int	search_label_neg(t_list **, char *, int);
int	search_last_label_neg(t_list **, int , int);
char	*fill_tmp(char *, t_list **, int, int);

/*
** write_in_file.c
*/
void	direct(t_hexa *, t_list **, t_list **, t_list **);
void	indirect(t_hexa *, t_list **, t_list **, t_list **);
int	write_instruction(t_list *, t_hexa);
int	write_hexa(t_list *, t_list *, t_list *, char *);

/*
** convert.c
*/
void	put_magic(int);
int	init_hexa(t_hexa *, t_list **, t_list **, char *);
void	change_bytes(t_hexa **, t_list **);
void	check_conversion(t_list **, t_hexa **, t_list **, t_list **);
void	check_conversion_ind(t_list **, t_hexa **, t_list **, t_list **);

/*
** do_fcts.c
*/
int	display_champ(char *, int);
int	do_fcts(int, t_list *, char **, int);

/*
** header_write.c
*/
int	cut_header(t_list *, int, int, t_list **);
void	header(int, t_list **, t_list **);

/*
** error_header.c
*/
int	error_comment(int);
int	error_name(int);

int	my_getnbr(char *);
int	getnbr_overflow(char *);
int	my_getnbr_base(char *, char *);

#endif /* !ASM_H_ */
