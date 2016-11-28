/*
** live.c for live in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Fri Mar 20 16:02:00 2015 Nyrandone Noboud-Inpeng
** Last update Sat Mar 21 23:05:21 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	error_argument(int line, char *args)
{
  arguments_wrong();
  my_puterr("\nSyntax error line ");
  my_put_nbr(line + 1);
  my_puterr(" -- ");
  write(2, DEFAULT, 4);
  write(2, RED, 5);
  write(2, BOLD, 4);
  my_puterr(args);
  write(2, DEFAULT, 4);
  my_puterr(" is an invalid argument's value.");
  my_puterr("\nPlease, check if the type of your instruction's parameter is ");
  my_puterr("actually valid. (Direct, indirect, register ?)\n");
  write(2, DEFAULT, 4);
  return (-1);
}

int	live(t_list *list, t_list *elem, int line)
{
  int	i;
  int	direct;

  i = -1;
  direct = 0;
  while (elem->args[++i] != NULL)
    {
      if (i == 1)
	{
	  if ((direct = check_direct(list, elem->args[i], line)) == -2)
	    return (-1);
	  if (direct == -1)
	    return (error_argument(line, elem->args[i]));
	}
    }
  return (0);
}
