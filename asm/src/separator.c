/*
** separator.c for separator in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Mon Mar 16 16:46:26 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 27 11:58:04 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	row_separator(int line)
{
  number_arg_wrong();
  my_puterr("\nSyntax error line ");
  my_put_nbr(line + 1);
  my_puterr(" -- ");
  write(2, RED, 5);
  write(2, BOLD, 4);
  my_puterr("invalid number of arguments.\n");
  write(2, DEFAULT, 4);
  return (-1);
}

int	no_arg_after_separator(t_list *elem, int line, int i)
{
  int	save;

  save = i;
  while ((elem->data[save] == ' ' || elem->data[save] == '\t')
	 && elem->data[save] != '\0' && elem->data[save] != COMMENT_CHAR
	 && elem->data[save] != ';')
    ++save;
  if (elem->data[save] == SEPARATOR_CHAR || elem->data[save] == '\0'
      || elem->data[save] == COMMENT_CHAR || elem->data[save] == ';')
    {
      number_arg_wrong();
      my_puterr("\nSyntax error line ");
      my_put_nbr(line + 1);
      my_puterr(" -- ");
      write(2, RED, 5);
      write(2, BOLD, 4);
      my_puterr("some parameters of the instruction are missing.\n");
      write(2, DEFAULT, 4);
      return (-1);
    }
  return (0);
}
