/*
** types.h for  in /home/veyrie_f/rendu/CPE_2014_corewar/include
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat Mar 21 14:57:42 2015 fernand veyrier
** Last update Thu Apr 16 23:21:57 2015 fernand veyrier
*/

#ifndef TYPES_H_
# define TYPES_H_

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>
# include <getopt.h>
# include "struct.h"
# include "op.h"
# include "champ.h"

/*
** Defines
*/
# define Wrong_magic_nbr	"This champion is not a good file!\n"
# define Too_much_argument	"There are too many champions. Maximum is 4.\n"
# define unused			__attribute__((unused))
# define tern(v)	(v >= 1 && v <= 16) ? v - 1 : (v <= 0) ? 0 : v % 16

/*
** my_str.c
*/
int		my_strlen(char *str);
char		*my_strcpy(char *str);
int		my_strcmp(char *pattern, char *compare_with);

/*
** my_error.c
*/
void		put_error_main();
void		put_error(char *av, char *str);
void		put_my_error(char *str);
int		my_puterror(char *str);

/*
** init_my_list.c
*/
void		print_header(t_list *champion);
void		take_header(t_list **champion, char **av, int i);
int		my_put_in_list(t_list **list, t_header head, char *prog_data,
			       t_check k);
void		my_rotate_list(t_list **list);
void		init_k(t_check *k);

/*
** arena.c
*/
void		print_memory(t_mem *arena, char *str);
void		init_func(int (*func[16])());
void		init_cmd(int *cmd);

/*
**game.c
*/
void		start_game_print(t_mem *arena,
				 t_champ *champs,
				 int champ_count);
int		finito(t_game *game, t_win *champ, int tmp, int alive);
void		print_champ(t_champ *champ, int i);

/*
**str.c
*/
int		my_getnbr_n(char *str);
int		my_getnbr(char *str);
int		my_strncmp(char *s1, char *s2, int nb);
char		**cut_my_arg(char *s);

/*
**operate.c
*/
int		do_st(t_mem *arena, int i, t_champ *champion);
int		do_sti(t_mem *arena, int i, t_champ *champion);
int		do_ld(t_mem *arena, int i, t_champ *champion);
int		do_ldi(t_mem *arena, int i, t_champ *champion);
int		do_lld(t_mem *arena, int i, t_champ *champion);
int		do_lldi(t_mem *arena, int i, t_champ *champion);
int		do_live(t_mem *arena, t_champ *champion, 
			int *nbr_live, t_game *game);
int		do_zjmp(t_mem *arena, int i, t_champ *champion);
int		do_fork(t_mem *arena, int i, t_champ *champion);
int		do_lfork(t_mem *arena, int i, t_champ *champion);
int		do_aff(t_mem *arena, int i, t_champ *champion);
int		do_add(t_mem *arena, int i, t_champ *champion);
int		do_sub(t_mem *arena, int i, t_champ *champion);
int		do_and(t_mem *arena, int i, t_champ *champion);
int		do_or(t_mem *arena, int i, t_champ *champion);
int		do_xor(t_mem *arena, int i, t_champ *champion);

/*
**my_arg_in_funct.c
*/
void		my_param(t_mem *arena, int i, t_champ *champion, t_decal *par);
void		my_parameters(t_mem *arena, int i, t_champ *champion,
			      t_decal *par);
int		do_decal_of_4(t_mem *arena, int i);
int		do_decal_of_2(t_mem *arena, int i);
void		my_param_next(t_mem *arena, int i, t_champ *champion,
			      t_decal *par);
int		take_neg_value(t_mem *arena, int i, char cmd[16]);
int		my_decal_of_two(t_mem *arena, int i);
int		my_decal_of_four(t_mem *arena, int i);
int		my_decal_of_two_idx(t_mem *arena, int i);
int		my_decal_of_four_idx(t_mem *arena, int i);
void		init_my_decal(t_decal *par);
int		my_neg_value(int i);

/*
**init_all.c
*/
void		clear_arena(t_mem *arena);
void		fill_champ_registry(t_champ *champion);
t_champ		*prepare_first_champion(int id, int pc, char *name);
t_champ		*prepare_champion(int id, int pc, char *name, t_champ *champ);

/*
**my_end_funct.c
*/
int		check_winner(t_champ *winner, t_champ *tmp_champ,
			     int turn, int alive);
void		check_champ_alive(t_win *champ, int i);
void		champion_alive_next(t_win *champ);
int		champion_alive(t_win *champ, int tmp,
			       int nbr_live,
			       t_game *game);

/*
**my_put.c
*/
void		my_putchar(char c);
void		my_putstr(char *str);
void		my_put_nbr(int nb);

#endif /* !TYPES_H_ */
