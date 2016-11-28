/*
** struct.h for  in /home/veyrie_f/rendu/CPE_2014_corewar
**
** Made by fernand veyrier
** Login   <veyrie_f@epitech.net>
**
** Started on  Sat Mar 21 12:59:24 2015 fernand veyrier
** Last update Thu Apr 16 00:34:19 2015 Florian Saurs
*/

#ifndef STRUCT_H_
# define STRUCT_H_

/*
** argument struct
*/
typedef	struct		s_args
{
  int			opt;
  int			i;
  char			*src_file;
  char			*key;
  unsigned char		*keypad;
  char			*out_file;
}			t_args;

typedef	struct		s_check
{
  int			check_a;
  int			check_n;
  int			fd;
  char			**tab;
  int			c;
  int			field;
}			t_check;

typedef	struct		s_list
{
  int			cmpt;
  int			magic;
  char			*prog_name;
  int			prog_size;
  char			*comment;
  char			*prog_data;
  int			num_prog;
  int			num_addr;
  struct s_list		*prev;
  struct s_list		*next;
}			t_list;

typedef struct		s_champ
{
  int			player_id;
  char			*name;
  int			PC;
  int			carry;
  int			alive;
  int			dead;
  int			has_lived;
  int			cycles_to_next;
  int			registry[16];
  int			last_result;
  int			cmpt;
  struct s_champ	*next;
  struct s_champ	*prev;
}			t_champ;

typedef struct		s_mem
{
  unsigned char		cmd;
  int			player_id;
  int			head;
}			t_mem;

typedef struct		s_decal
{
  int			my_reg;
  int			my_reg2;
  int			ret;
  int			decal;
  int			c;
  char			cmd[8];
}			t_decal;

typedef	struct		s_win
{
  t_champ		*champion;
  t_champ		*first_champ;
  t_mem			*arena;
}			t_win;

typedef	struct		s_init
{
  t_mem			*arena;
  t_champ		*champion;
  t_champ		*first_champ;
  int			i;
  int			j;
  int			count;
  int			end;
  int			gap;
  int			c;
}			t_init;

typedef	struct		s_game
{
  int			j;
  int			cmd[16];
  int			(*func[16])();
  t_champ		*first_champ;
  int			nb_turn;
  int			my_turn;
  int			cycle_todie;
  int			nbr_live;
  int			i;
  int			**champ_alive;
}			t_game;

typedef	struct		s_put
{
  char			cmd[8];
  int			c;
  int			nb;
  int			nb2;
}			t_put;

#endif /* !STRUCT_H_ */
