/*
** exact_error.c for exact_error in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Fri Mar 13 14:36:12 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 27 12:14:21 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	exact_error(t_list *list, int begin, char *error)
{
  int	x;

  x = 0;
  my_puterr(" -- ");
  while (x < begin)
    ++x;
  write(2, RED, 5);
  write(2, BOLD, 4);
  while ((error[x] != ' ' && error[x] != '\t') && error[x] != '\0'
	 && error[x] != COMMENT_CHAR && error[x] != ';')
    write(2, &(error[x++]), 1);
  write(2, DEFAULT, 4);
  free_list(list);
  return (0);
}

int	wrong_instruction(int line, int i, t_list *elem, t_list *list)
{
  int	x;

  x = 0;
  if (elem->lab != -1)
    {
      x = elem->lab;
      while ((elem->data[x] == ' ' || elem->data[x] == '\t')
	     && elem->data[x] != '\0' && elem->data[x] != ';'
	     && elem->data[x] != COMMENT_CHAR)
	++x;
    }
  if (i == x)
    {
      instructions_wrong();
      my_puterr("\nSyntax error line ");
      my_put_nbr(line + 1);
      exact_error(list, i, elem->data);
      my_puterr("\n");
    }
  else
    wrong_label(line, i, elem, list);
  return (-1);
}

int	wrong_label(int line, int i, t_list *elem, t_list *list)
{
  instructions_wrong();
  my_puterr("\nLabel ");
  write(2, RED, 5);
  write(2, BOLD, 4);
  while (elem->data[i] != '\0' && elem->data[i] != ':'
	 && elem->data[i] != SEPARATOR_CHAR
	 && elem->data[i] != COMMENT_CHAR && elem->data[i] != ' '
	 && elem->data[i] != '\t' && elem->data[i] != ';')
    write(2, &(elem->data[i++]), 1);
  write(2, DEFAULT, 4);
  my_puterr(" undefined line ");
  my_put_nbr(line + 1);
  free_list(list);
  return (my_puterr("\n"));
}

int	check_mark(t_list *elem, int i, int mark, int line)
{
  if (elem->lab != -1)
    {
      if (elem->data[i] == ':' && (--mark) != 0)
	{
	  instructions_wrong();
	  my_puterr("\nSyntax error line ");
	  my_put_nbr(line + 1);
	  my_puterr(" -- ");
	  write(2, RED, 5);
	  write(2, BOLD, 4);
	  return (my_puterr("label missing\n"));
	}
    }
  else
    if (elem->data[i] == ':')
      {
	instructions_wrong();
	my_puterr("\nSyntax error line ");
	my_put_nbr(line + 1);
	my_puterr(" -- ");
	write(2, RED, 5);
	write(2, BOLD, 4);
	return (my_puterr("label missing\n"));
      }
  return (0);
}

int	invalid_line(t_list *elem, int line, int i, int mark)
{
  int	return_value;

  (i > 0 ? --i : 0);
  while (i > 0 && (elem->data[i] == ' ' || elem->data[i] == '\t'))
    --i;
  return_value = check_mark(elem, i, mark, line);
  write(2, DEFAULT, 4);
  return (return_value);
}
