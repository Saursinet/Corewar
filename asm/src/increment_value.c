/*
** increment_value.c for increment_value in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Fri Mar 27 11:32:29 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 27 11:33:28 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	increment_value_elem(t_list *elem, int i)
{
  while ((elem->data[i] == ' ' || elem->data[i] == '\t')
	 && elem->data[i] != '\0' && elem->data[i] != COMMENT_CHAR
	 && elem->data[i] != ';')
    ++i;
  return (i);
}
