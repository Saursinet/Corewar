/*
** do_fcts.c for do_fcts in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Fri Mar 27 18:40:45 2015 Nyrandone Noboud-Inpeng
** Last update Sun Mar 29 18:35:24 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	display_champ(char *champ, int i)
{
  while (champ[i] != '\0')
    my_putchar(champ[i++]);
  return (0);
}

void		error_extend()
{
  write(2, BOLD, 4);
  my_puterr("Error : please, do NOT use any ");
  write(2, DEFAULT, 4);
  write(2, BOLD, 4);
  write(2, RED, 5);
  my_puterr(".extend ");
  write(2, DEFAULT, 4);
  write(2, BOLD, 4);
  my_putstr("or ");
  write(2, DEFAULT, 4);
  write(2, BOLD, 4);
  write(2, RED, 5);
  my_putstr(".code\n");
  write(2, DEFAULT, 4);
}

int		check_extend(t_list *list, char **argv, int i)
{
  int		x;
  t_list	*elem;

  elem = list->next;
  while (elem != list)
    {
      x = 0;
      x = increment_value_elem(elem, x);
      if ((strcmp_extend(".extend", elem->data, x)) == 0)
	{
	  error_extend();
	  compilation_stopped(i, argv, 0);
	  free_list(list);
	  return (1);
	}
      if ((strcmp_extend(".code", elem->data, x)) == 0)
	{
	  error_extend();
	  compilation_stopped(i, argv, 0);
	  free_list(list);
	  return (1);
	}
      elem = elem->next;
    }
  return (0);
}

int		check_is_ok(t_list *list, char **argv, int i)
{
  char		**label;

  if ((check_extend(list, argv, i)) == 1)
    return (0);
  if ((label = check_file(list)) == NULL)
    return (compilation_stopped(i, argv, 1));
  free_tab(label);
  header_ok();
  if ((check_instructions(list)) == -1)
    return (compilation_stopped(i, argv, 1));
  if ((write_hexa(list, NULL, NULL, argv[i])) == -1)
    return (compilation_stopped(i, argv, 1));
  transform_ok(argv[i]);
  free_list(list);
  compilation_finished(argv[i], argv, i);
  return (0);
}

int		do_fcts(int check_list, t_list *list, char **argv, int i)
{
  int		check;

  check = 0;
  if (check_list == 0)
    {
      if (check_lists(list, argv[i]) == -1)
	{
	  write(2, DEFAULT, 4);
	  ++check;
	  compilation_stopped(i, argv, 0);
	}
      if (check == 0)
	if ((check_is_ok(list, argv, i)) == -1)
	  return (-1);
    }
  return (0);
}
