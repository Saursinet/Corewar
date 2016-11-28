/*
** my_strcmp.c for my_strcmp in /media/blinux/noboud_n/rendu/PSU_2014_minishell1/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Mon Jan 26 17:27:02 2015 Nyrandone Noboud-Inpeng
** Last update Sat Mar 28 19:26:34 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int		strcmp_begin(int begin, char *pattern, char *compare_with)
{
  int		i;
  int		x;

  i = 0;
  x = begin;
  while (pattern[i] != ':' && pattern[i] != '\0')
    {
      if (compare_with[x] != pattern[i])
	return (-1);
      ++i;
      ++x;
    }
  if (compare_with[x])
    if (compare_with[x] != '\0' && compare_with[x] != ' '
	&& compare_with[x] != '\t' && compare_with[x] != LABEL_CHAR
	&& compare_with[x] != SEPARATOR_CHAR && compare_with[x] != COMMENT_CHAR
	&& compare_with[x] != ';')
      return (-1);
  return (0);
}

int		cmp_instructions(int save, char *compare_with, t_list *list)
{
  t_list	*elem;

  elem = list->next;
  while (elem != list)
    {
      if (elem->lab != -1)
	{
	  if ((strcmp_begin(save, elem->label, compare_with)) == 0)
	    return (1);
	}
      elem = elem->next;
    }
  return (-1);
}

int	strcmp_instructions(char *pattern, t_list *elem,
			    t_list *list, int begin)
{
  int	i;
  int	x;
  int	save;

  i = 0;
  x = 0;
  while (x < begin)
    ++x;
  save = x;
  while (pattern[i] != '\0')
    {
      if (pattern[i] != elem->data[x])
	return (cmp_instructions(save, elem->data, list));
      ++i;
      ++x;
    }
  if (elem->data[x] != ' ' && elem->data[x] != '\t')
    return (-1);
  return (0);
}

int	custom_strcmp(char *pattern, char *compare_with)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  while ((compare_with[x] == ' ' || compare_with[x] == '\t')
	 && compare_with[x] != '\0')
    ++x;
  while (pattern[i] != '\0')
    {
      if (pattern[i] != compare_with[x])
	return (-1);
      ++i;
      ++x;
    }
  if (compare_with[x] != '\0')
    if (compare_with[x] == ':')
      return (-1);
  return (0);
}

int	my_strcmp(char *pattern, char *compare_with)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  if (pattern == NULL || compare_with == NULL)
    return (-1);
  while (pattern[i] != '\0')
    {
      if (pattern[i] != compare_with[x])
	return (-1);
      ++i;
      ++x;
    }
  return (0);
}
