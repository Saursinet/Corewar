/*
** mainbis.c for my_select in /home/saurs_f/rendu/PSU_2014_my_select
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Tue Dec 23 14:18:20 2014 Florian Saurs
** Last update Fri Apr 17 01:35:38 2015 Florian Saurs
*/

#include "types.h"

int	take_my_magic_nbr(unsigned char buff[4])
{
  int	magic_nbr;

  magic_nbr = 0;
  magic_nbr = magic_nbr >> 24 | buff[0];
  magic_nbr = magic_nbr << 24;
  magic_nbr = magic_nbr >> 16 | buff[1];
  magic_nbr = magic_nbr << 16;
  magic_nbr = magic_nbr >> 8 | buff[2];
  magic_nbr = magic_nbr << 8;
  magic_nbr = magic_nbr | buff[3];
  return (magic_nbr);
}

void		take_in_champ(t_check k, t_list **champion, char *av)
{
  unsigned char	buff[4];
  int		magic_nbr;
  t_header	head;
  char		*prog_data;

  read(k.fd, buff, sizeof(int)) <= 0 ? exit(ERROR_READ) : (void)0;
  magic_nbr = take_my_magic_nbr(buff);
  if (magic_nbr != COREWAR_EXEC_MAGIC)
    put_error(av, Wrong_magic_nbr);
  head.magic = magic_nbr;
  read(k.fd, head.prog_name, PROG_NAME_LENGTH) == -1 ?
    exit(ERROR_READ) : (void)0;
  head.prog_name[PROG_NAME_LENGTH] = 0;
  read(k.fd, buff, sizeof(int)) <= 0 ? exit(ERROR_READ) : (void)0;
  read(k.fd, buff, sizeof(int)) <= 0 ? exit(ERROR_READ) : (void)0;
  head.prog_size = take_my_magic_nbr(buff);
  read(k.fd, head.comment, COMMENT_LENGTH) <= 0 ? exit(ERROR_READ) : (void)0;
  head.comment[COMMENT_LENGTH] = 0;
  read(k.fd, buff, sizeof(int)) <= 0 ? exit(ERROR_READ) : (void)0;
  ((prog_data = malloc(sizeof(char) * (head.prog_size + 2))) == NULL) ?
    exit(ERROR_MALLOC) : (void)0;
  read(k.fd, prog_data, head.prog_size) <= 0 ? exit(ERROR_READ) : (void)0;
  prog_data[head.prog_size + 1] = 0;
  my_put_in_list(champion, head, prog_data, k);
}

int	is_a_name(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  while (str[i] != '.' && i > 0)
    --i;
  if (str[i] == 0 || str[i + 1] == 0)
    return (-1);
  i++;
  if (my_strcmp(&str[i], "cor") == 0)
    return (0);
  my_putstr(str);
  my_putstr(" is not a corewar executable\n");
  return (-1);
}

int		check_n_a(t_check *k, char **av, int i)
{
  k->check_a = -1;
  k->check_n = -1;
  if (my_strcmp(av[i], "-n") == 0 || my_strcmp(av[i], "-a") == 0)
    {
      if (av[i + 1] == 0)
	put_error_main();
      (my_strcmp(av[i], "-n") == 0) ? (k->check_n = my_getnbr_n(av[i + 1])) :
	(k->check_a = my_getnbr_n(av[i + 1]));
      i += 2;
      if ((k->check_n != -1 && my_strcmp(av[i], "-n") == 0) ||
	  (k->check_a != -1 && my_strcmp(av[i], "-a") == 0))
	put_error_main();
      else if (my_strcmp(av[i], "-n") == 0 || my_strcmp(av[i], "-a") == 0)
	{
	  if (av[i + 1] == 0)
	    put_error_main();
	  (my_strcmp(av[i], "-n") == 0) ?
	    (k->check_n = my_getnbr_n(av[i + 1])) :
	    (k->check_a = my_getnbr_n(av[i + 1]));
	  i += 2;
	}
      if ((av[i] == 0 || is_a_name(av[i]) == -1))
	put_error_main();
    }
  return (i);
}

void		take_header(t_list **champion, char **av, int i)
{
  t_check	k;

  init_k(&k);
  while (av[i])
    {
      if (av[i] && my_strncmp("-dump", av[i], 5) == 0)
	i += 2;
      i = check_n_a(&k, av, i);
      if (av[i])
	{
	  k.tab = cut_my_arg(av[i]);
	  k.c = 0;
	  while (k.tab[k.c][0] == '-')
	    ++k.c;
	  ++k.field;
	  ((k.fd = open(k.tab[k.c], O_RDONLY)) == -1) ?
	    exit(ERROR_OPEN) : (void)0;
	  take_in_champ(k, champion, av[i]);
	  ++i;
	}
    }
  if (k.field == 0 || k.field == 1)
    put_error_main();
  my_rotate_list(champion);
}
