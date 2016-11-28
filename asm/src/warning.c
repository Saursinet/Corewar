/*
** warning.c for warning in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Sun Mar 15 17:00:03 2015 Nyrandone Noboud-Inpeng
** Last update Mon Apr 13 14:31:09 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	warning_idxmod(int line)
{
  write(2, YELLOW, 5);
  write(2, BOLD, 4);
  my_puterr("\nWarning : ");
  write(2, DEFAULT, 4);
  my_puterr("Indirection too far line ");
  my_put_nbr(line);
  my_puterr(" -- you can actually avoid it by ");
  write(2, YELLOW, 5);
  write(2, BOLD, 4);
  my_puterr("reducing your indirect value.\n\n");
  write(2, DEFAULT, 4);
  return (0);
}
