/*
** actualize_message.c for actualize_message in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Sun Mar 15 15:14:13 2015 Nyrandone Noboud-Inpeng
** Last update Sun Mar 29 18:16:52 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

void	header_ok()
{
  write(2, BOLD, 4);
  my_putstr("Header checked -- ");
  write(2, DEFAULT, 4);
  write(2, GREEN, 5);
  write(2, BOLD, 4);
  my_putstr("OK.\n");
  write(2, DEFAULT, 4);
}

void	instructions_ok()
{
  write(2, BOLD, 4);
  my_putstr("Instructions' validity and labels' validity checked -- ");
  write(2, DEFAULT, 4);
  write(2, GREEN, 5);
  write(2, BOLD, 4);
  my_putstr("OK.\n");
  write(2, DEFAULT, 4);
}

void	number_arg_ok()
{
  write(2, BOLD, 4);
  my_putstr("Arguments' number of every instructions checked -- ");
  write(2, DEFAULT, 4);
  write(2, GREEN, 5);
  write(2, BOLD, 4);
  my_putstr("OK.\n");
  write(2, DEFAULT, 4);
}

void	arguments_ok()
{
  write(2, BOLD, 4);
  my_putstr("Arguments' data checked -- ");
  write(2, GREEN, 5);
  write(2, BOLD, 4);
  my_putstr("OK.\n");
  write(2, DEFAULT, 4);
}

void	transform_ok(char *champ)
{
  write(2, BOLD, 4);
  my_putstr("Conversion of ");
  write(2, DEFAULT, 4);
  write(2, BOLD, 4);
  write(2, PURPLE, 5);
  champion_name(champ);
  write(2, DEFAULT, 4);
  write(2, BOLD, 4);
  my_putstr(" to his format ");
  write(2, PURPLE, 5);
  write(2, BOLD, 4);
  my_putstr(".cor ");
  write(2, DEFAULT, 4);
  write(2, BOLD, 4);
  my_putstr("-- ");
  write(2, GREEN, 5);
  write(2, BOLD, 4);
  my_putstr("DONE.\n");
  write(2, DEFAULT, 4);
}
