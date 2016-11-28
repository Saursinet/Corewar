/*
** main.c for main in /home/noboud_n/rendu/CPE/Corewar
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Wed Mar 11 11:18:03 2015 Nyrandone Noboud-Inpeng
** Last update Sun Mar 29 18:21:15 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

void		compilation_started(char *champ, int i)
{
  if (i != 1)
    {
      write(2, RED, 5);
      write(2, BOLD, 4);
      my_putstr("\n              Waiting for another file...\n\n");
      write(2, DEFAULT, 4);
      write(2, BLUE, 5);
      write(2, BOLD, 4);
      my_putstr("########################################################\n");
      write(2, DEFAULT, 4);
    }
  write(2, CYAN, 5);
  write(2, BOLD, 4);
  my_putstr("\n** Compilation started for ");
  write(2, DEFAULT, 4);
  write(2, GREEN, 5);
  write(2, BOLD, 4);
  champion_name(champ);
  write(2, DEFAULT, 4);
  write(2, CYAN, 5);
  write(2, BOLD, 4);
  my_putstr("... **\n\n");
  write(2, DEFAULT, 4);
}

void		compilation_finished(char *champ, char **argv, int i)
{
  write(2, CYAN, 5);
  write(2, BOLD, 4);
  my_putstr("\n** Compilation finished. ");
  my_putstr("Your champion can be found as : ");
  write(2, DEFAULT, 4);
  write(2, PURPLE, 5);
  write(2, BOLD, 4);
  champion_name(champ);
  my_putstr(".cor");
  write(2, DEFAULT, 4);
  write(2, CYAN, 5);
  write(2, BOLD, 4);
  my_putstr(" **\n\n");
  write(2, DEFAULT, 4);
  if (argv[i + 1])
    {
      write(2, BLUE, 5);
      write(2, BOLD, 4);
      my_putstr("########################################################\n");
      write(2, DEFAULT, 4);
    }
}

int		compilation_stopped(int i, char **argv, int mark)
{
  write(2, CYAN, 5);
  write(2, BOLD, 4);
  my_putstr("\n** Compilation ");
  write(2, DEFAULT, 4);
  write(2, RED, 5);
  write(2, BOLD, 4);
  my_putstr("stopped. ");
  write(2, DEFAULT, 4);
  write(2, CYAN, 5);
  write(2, BOLD, 4);
  my_putstr("**\n\n");
  write(2, DEFAULT, 4);
  if (argv[i + 1] && mark == 0)
    {
      write(2, BLUE, 5);
      write(2, BOLD, 4);
      my_putstr("########################################################\n");
      write(2, DEFAULT, 4);
    }
  return (-1);
}

int	try_open(char *champ, int i, char **argv)
{
  int	x;

  x = 0;
  while (champ[x] != '\0')
    ++x;
  if (x - 1 > 0)
    if (champ[--x] == 's')
      if (x - 1 > 0)
	if (champ[--x] == '.')
	  return (0);
  write(2, BOLD, 4);
  my_puterr("The format of the file is actually invalid. Please, ");
  write(2, RED, 5);
  my_puterr("use a '.s'");
  write(2, DEFAULT, 4);
  my_puterr(".\n");
  compilation_stopped(i, argv, 0);
  return (-1);
}

int		main(int argc, char **argv)
{
  t_list	*list;
  int		i;
  int		check_list;

  if (argc < 2)
    return (my_puterr("usage: ./asm file_name[.s]\n"));
  i = 1;
  while (i < argc)
    {
      compilation_started(argv[i], i);
      if ((try_open(argv[i], i, argv)) == 0)
	{
	  check_list = 0;
	  if ((list = store_file(argv[i])) == NULL)
	    {
	      ++check_list;
	      compilation_stopped(i, argv, 0);
	    }
	  if (check_list == 0)
	    if ((do_fcts(check_list, list, argv, i)) == -1)
	      return (-1);
	}
      ++i;
    }
  return (0);
}
