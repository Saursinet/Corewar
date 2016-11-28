/*
** error_header.c for header_error.c in /home/noboud_n/rendu/CPE/CPE_2014_corewar/asm/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Thu Apr 16 23:13:18 2015 Nyrandone Noboud-Inpeng
** Last update Thu Apr 16 23:18:47 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	error_comment(int line)
{
  header_wrong();
  my_puterr("\nSyntax error line ");
  my_put_nbr(line);
  my_puterr(" -- (usage: .comment [STRING])\n");
  return (-1);
}

int	error_name(int line)
{
  header_wrong();
  my_puterr("\nSyntax error line ");
  my_put_nbr(line);
  my_puterr(" -- (usage: .name [STRING])\n");
  return (-1);
}
