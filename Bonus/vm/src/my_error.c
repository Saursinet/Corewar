/*
** my_error.c for corewar in /home/saursf/rendu/CPE_2014_corewar/src
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Mon Mar 16 13:40:42 2015 Florian Saurs
** Last update Thu Apr 16 13:59:23 2015 fernand veyrier
*/

#include "types.h"

void	put_error_main()
{
  write(2, "Usage : ./corewar [-dump nbr_cycle] [[-n prog_number] [-a ", 58);
  write(2, "load_address] prog_name] ...\n", 29);
  exit(-1);
}

void	put_error(char *av, char *str)
{
  write(2, av, my_strlen(av));
  write(2, " : ", 3);
  write(2, str, my_strlen(str));
  exit(-1);
}

void	put_my_error(char *str)
{
  write(2, str, my_strlen(str));
  exit(-1);
}

int		my_puterror(char *str)
{
  return (write(2, str, my_strlen(str)));
}
