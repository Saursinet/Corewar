/*
** wrong_actualize.c for wrong_actualize in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Sun Mar 15 15:33:56 2015 Nyrandone Noboud-Inpeng
** Last update Thu Mar 19 16:25:28 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

void	header_wrong()
{
  write(2, BOLD, 4);
  my_putstr("Header checked -- ");
  write(2, DEFAULT, 4);
  write(2, RED, 5);
  write(2, BOLD, 4);
  my_putstr("ERROR.\n");
  write(2, DEFAULT, 4);
}

void	instructions_wrong()
{
  write(2, BOLD, 4);
  my_putstr("Instructions' validity and labels' validity checked -- ");
  write(2, DEFAULT, 4);
  write(2, RED, 5);
  write(2, BOLD, 4);
  my_putstr("ERROR.\n");
  write(2, DEFAULT, 4);
}

void	number_arg_wrong()
{
  write(2, BOLD, 4);
  my_putstr("Arguments' number of every instructions checked -- ");
  write(2, DEFAULT, 4);
  write(2, RED, 5);
  write(2, BOLD, 4);
  my_putstr("ERROR.\n");
  write(2, DEFAULT, 4);
}

void	arguments_wrong()
{
  write(2, BOLD, 4);
  my_putstr("Arguments' data checked -- ");
  write(2, DEFAULT, 4);
  write(2, RED, 5);
  write(2, BOLD, 4);
  my_putstr("ERROR.\n");
  write(2, DEFAULT, 4);
}
