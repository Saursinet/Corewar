/*
** check_list.c for check_list in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Wed Mar 18 18:44:24 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 27 12:13:12 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int		count_list(t_list *list)
{
  t_list	*elem;
  int		count;

  count = 0;
  elem = list->next;
  while (elem != list)
    {
      ++count;
      elem = elem->next;
    }
  return (count);
}

int		error_message(char *champ)
{
  write(2, CYAN, 5);
  write(2, BOLD, 4);
  my_putstr("Error : The file ");
  write(2, DEFAULT, 4);
  write(2, RED, 5);
  write(2, BOLD, 4);
  my_putstr(champ);
  write(2, DEFAULT, 4);
  write(2, CYAN, 5);
  write(2, BOLD, 4);
  my_putstr(" contains invalid data. (or contains none)\n\n");
  write(2, DEFAULT, 4);
  return (-1);
}

int		check_begin_file(t_list *list, char *champ)
{
  t_list	*elem;
  int		i;
  int		check;

  i = 0;
  check = 0;
  elem = list->next;
  while (elem != list)
    {
      i = 0;
      while ((elem->data[i] == ' ' || elem->data[i] == '\t')
	     && elem->data[i] != '\0' && elem->data[i] != COMMENT_CHAR
	     && elem->data[i] != ';')
	++i;
      if (elem->data[i] == '\0' || elem->data[i] == COMMENT_CHAR
	  || elem->data[i] == ';')
	++check;
      elem = elem->next;
    }
  if (check == (count_list(list)))
    return (error_message(champ));
  return (0);
}

int		check_lists(t_list *list, char *champ)
{
  t_list	*elem;

  elem = list->next;
  if (elem == list)
    {
      write(2, CYAN, 5);
      write(2, BOLD, 4);
      my_puterr("Error : the file ");
      write(2, DEFAULT, 4);
      write(2, RED, 5);
      write(2, BOLD, 4);
      my_puterr(champ);
      write(2, DEFAULT, 4);
      write(2, CYAN, 5);
      write(2, BOLD, 4);
      my_puterr(" you attempted to open is empty.\n");
      write(2, DEFAULT, 4);
      return (-1);
    }
  if ((check_begin_file(list, champ)) == -1)
    return (-1);
  return (0);
}
