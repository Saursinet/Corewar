/*
** header.c for header in /home/noboud_n/rendu/CPE/Corewar/src
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
**
** Started on  Wed Mar 11 16:59:46 2015 Nyrandone Noboud-Inpeng
** Last update Thu Apr 16 23:21:13 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	check_error_name(int x, int len, t_list *elem, int line)
{
  if (elem->data[x++] != '"')
    return (error_name(line));
  while ((elem->data[x] == ' ' || elem->data[x] == '\t')
	 && elem->data[x] != '\0' && elem->data[x] != '#'
	 && elem->data[x] != ';')
    ++x;
  if (elem->data[x] != '\0' && elem->data[x] != '#'
      && elem->data[x] != ';')
    {
      header_wrong();
      my_puterr("\nSyntax error line ");
      my_put_nbr(line);
      my_puterr(" -- once you have put your comment, ");
      return (my_puterr("you cannot put something else afterwards.\n"));
    }
  if (len > 128)
    {
      header_wrong();
      my_puterr("\nSyntax error line ");
      my_put_nbr(line);
      return (my_puterr(" -- name length should be inferior to 128.\n"));
    }
  return (0);
}

int	check_name(int i, int x, t_list *elem, int line)
{
  int	len;

  len = 0;
  if (i == 0)
    {
      if ((my_strncmp(x, ".name", elem->data)) == -1)
	return (error_name(line));
      x = x + 5;
      x = increment_value_elem(elem, x);
      if (elem->data[x++] != '"')
	return (error_name(line));
      while (elem->data[x] != '"' && elem->data[x] != '\0'
	     && elem->data[x] != ';' && elem->data[x] != '#')
	{
	  (elem->data[x + 1] != '"' && elem->data[x + 1] != '\0' ? ++len :
	   (len = len));
	  ++x;
	}
      return (check_error_name(x, len, elem, line));
    }
  return (0);
}

int	check_error_comment(int x, int len, t_list *elem, int line)
{
  if (elem->data[x++] != '"')
    return (error_comment(line));
  x = increment_value_elem(elem, x);
  if (elem->data[x] != '\0' && elem->data[x] != '#'
      && elem->data[x] != ';')
    {
      header_wrong();
      my_puterr("\nSyntax error line ");
      my_put_nbr(line);
      my_puterr(" -- once you have put your comment, ");
      return (my_puterr("you cannot put something else afterwards.\n"));
    }
  if (len > 2048)
    {
      header_wrong();
      my_puterr("\nSyntax error line ");
      my_put_nbr(line);
      my_puterr(" -- comment length should be inferior to 2048.\n");
      return (-1);
    }
  return (0);
}

int	check_comment(int i, int x, t_list *elem, int line)
{
  int	len;

  len = 0;
  if (i == 1)
    {
      if ((my_strncmp(x, ".comment", elem->data)) == -1)
	return (-2);
      x = increment_value_elem(elem, x + 8);
      if (elem->data[x++] != '"')
	return (error_comment(line));
      while (elem->data[x] != '"' && elem->data[x] != '\0'
	     && elem->data[x] != '#' && elem->data[x] != ';')
	{
	  (elem->data[x] != '"' && elem->data[x] != '\0' ? ++len
	   : (len = len));
	  ++x;
	}
      return (check_error_comment(x, len, elem, line));
    }
  return (2);
}

int	check_header(int i, t_list *elem, int line)
{
  int	x;
  int	check;

  x = 0;
  check = 0;
  while ((elem->data[x] == ' ' || elem->data[x] == '\t')
	 && elem->data[x] != '\0'&& elem->data[x] != '#'
	 && elem->data[x] != ';')
    ++x;
  if ((check_name(i, x, elem, line)) == -1)
    return (-1);
  if ((check = check_comment(i, x, elem, line)) == -1)
    return (-1);
  if (i == 0)
    elem->name = 1;
  else if (i == 1 && check != -2 && check != 2)
    elem->comment = 1;
  return (0);
}
