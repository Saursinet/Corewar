/*
** error.c for error in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Tue Mar 17 22:45:04 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 20 11:52:05 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	wrong_arguments(int line, t_list *list)
{
  instructions_wrong();
  my_puterr("\nSyntax error line ");
  my_put_nbr(line + 1);
  my_putstr(" -- ");
  write(2, RED, 5);
  write(2, BOLD, 4);
  my_puterr("invalid argument or label's name.");
  write(2, DEFAULT, 4);
  free_list(list);
  return (my_puterr("\n"));
}
