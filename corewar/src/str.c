/*
** str.c for corewar in /home/saursf/rendu/CPE_2014_corewar
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Mon Mar 23 11:13:13 2015 Florian Saurs
** Last update Mon Apr 13 14:38:40 2015 Florian Saurs
*/

#include "types.h"

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  if (s1 && s2)
    {
      while (s1[i] == s2[i] && s1[i] != '\0' && nb > 0)
	{
	  i = i + 1;
	  --nb;
	}
      i = s1[i] - s2[i];
      return (i);
    }
  return (-1);
}

char	**take_arg(char *s, int i, char **arg)
{
  int	tmp;
  int	c;

  tmp = i;
  c = 0;
  while (s && s[i] && s[i++] != ' ');
  while (s && s[i] && s[i] != ' ')
    ++i;
  while (arg[c] != NULL)
    ++c;
  if ((arg[c] = malloc((i + 1) * sizeof(char))) == NULL)
    exit(-1);
  i = 0;
  while (s && s[tmp] && s[tmp] != ' ')
    arg[c][i++] = s[tmp++];
  arg[c][i++] = s[tmp++];
  while (s && s[tmp] && s[tmp] != ' ')
    arg[c][i++] = s[tmp++];
  arg[c][i] = 0;
  arg[c + 1] = NULL;
  return (arg);
}

char	**my_affect_line(char *s, int i, char **arg)
{
  int	tmp;
  int	c;

  if (s && s[i] && s[i] == '-')
    return (take_arg(s, i, arg));
  tmp = i;
  c = 0;
  while (s && s[i] && s[i] != ' ')
    ++i;
  while (arg[c] != NULL)
    ++c;
  if ((arg[c] = malloc((i + 1) * sizeof(char))) == NULL)
    exit(-1);
  i = 0;
  while (s && s[tmp] && s[tmp] != ' ')
    arg[c][i++] = s[tmp++];
  arg[c][i] = 0;
  arg[c + 1] = NULL;
  return (arg);
}

int	pass_tir(char *s, int i)
{
  while (s && s[i] && s[i++] != ' ');
  return (i);
}

char	**cut_my_arg(char *s)
{
  char	**arg;
  int	i;
  int	c;

  i = 0;
  c = 1;
  while (s[i] != 0)
    {
      if (my_strncmp("-n ", &s[i], 2) == 0 || my_strncmp("-a ", &s[i], 2) == 0)
	++c;
      ++i;
    }
  i = 0;
  ((arg = malloc((c + 2) * sizeof(char *))) == NULL ? exit(-1) : (void)0);
  arg[0] = NULL;
  while (s[i] != 0)
    {
      arg = my_affect_line(s, i, arg);
      s[i] == '-' ? i = pass_tir(s, i) : 0;
      while (s && s[i] && s[i] != ' ')
	++i;
      while (s[i] == ' ')
	++i;
    }
  return (arg);
}
