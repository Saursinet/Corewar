/*
** true_strcmp.c for true_strcmp in /home/noboud_n/rendu/CPE/Corewar/src
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
**
** Started on  Tue Mar 17 23:23:29 2015 Nyrandone Noboud-Inpeng
** Last update Tue Apr  7 14:18:22 2015 Alban Combaud
*/

#include "asm.h"

int	strncmp_b(char *pattern, char *compare_with, int x, int label)
{
  int	i;

  i = 0;
  if (label == 1)
    while (pattern[i] != '\0' && pattern[i] != ':')
      {
	if (pattern[i] != compare_with[x])
	  return (-1);
	++i;
	++x;
      }
  else
      while (pattern[i] != '\0' && pattern[i] != ':')
	{
	  if (pattern[i] != compare_with[x])
	    return (-1);
	  ++i;
	  ++x;
	}
  if (pattern[i] == '\0' && compare_with[x] != '\0')
    return (-1);
  if (label == 1 && (pattern[i] == ':' || pattern[i] == '\0')
      && compare_with[x] != '\0')
    return (-1);
  return (0);
}

int	initialized_strcmp(int i, char *pattern, char *compare_with)
{
  int	x;

  x = 0;
  while (pattern[i] != '\0')
    {
      if (pattern[i] != compare_with[x])
	return (-1);
      ++i;
      ++x;
    }
  if (pattern[i] == '\0' && compare_with[x] != '\0')
    return (-1);
  return (0);
}

int	my_strncmp(int i, char *pattern, char *compare_with)
{
  int	x;

  x = 0;
  while (pattern[x] != '\0')
    {
      if (pattern[x] != compare_with[i])
	return (-1);
      ++i;
      ++x;
    }
  if (pattern[x] == '\0'
      && (compare_with[i] != ' ' && compare_with[i] != '\t'
	  && compare_with[i] != '"'))
    return (-1);
  return (0);
}

int	true_strcmp(char *pattern, char *compare_with)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  if (pattern == NULL || compare_with == NULL)
    return (-1);
  while (pattern[i] != '\0' && compare_with[x] != '\0')
    {
      if (pattern[i] != compare_with[x])
	return (-1);
      ++i;
      ++x;
    }
  if (pattern[i] != '\0' || compare_with[x] != '\0')
    return (-1);
  return (0);
}

int	strcmp_asm(char *s1, char *s2)
{
  int	a;

  a = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[a] != '\0' && s2[a] != '\0' && s1[a] == s2[a])
    ++a;
  if (s1[a] != '\0' || s2[a] != '\0')
    return (-1);
  return (0);
}
