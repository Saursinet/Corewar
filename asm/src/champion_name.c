/*
** champion_name.c for champion_name in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Fri Mar 27 12:26:51 2015 Nyrandone Noboud-Inpeng
** Last update Sun Mar 29 18:36:34 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	count_diff_zero(char *champ, int count)
{
  int	i;
  int	save_i;
  int	save;

  i = 0;
  while (champ[i] != '\0' && count > 0)
    {
      if (champ[i] == '/')
	--count;
      ++i;
    }
  save_i = i;
  while (champ[i] != '\0')
    ++i;
  while (champ[i] != '.' && i > 0)
    --i;
  save = i;
  i = save_i;
  while (i < save)
    my_putchar(champ[i++]);
  return (0);
}

int		champion_name(char *champ)
{
  int		i;
  int		count;
  int		save;

  i = -1;
  count = 0;
  while (champ[++i] != '\0')
    (champ[i] == '/' ? ++count : (count = count));
  if (count == 0)
    {
      i = -1;
      while (champ[++i] != '\0');
      while (i > 0 && champ[i] != '.')
	--i;
      if (i == 0)
	return (display_champ(champ, i));
      save = i;
      i = 0;
      while (i < save)
	my_putchar(champ[i++]);
    }
  (count != 0 ? count_diff_zero(champ, count) : (int)count);
  return (0);
}

char	*count_is_zero(char *champ, char *new_champ, int i, int x)
{
  int	save;
  int	save_i;

  save_i = i;
  while (champ[i] != '\0')
    ++i;
  while (champ[i] != '.' && i > 0)
    --i;
  save = i;
  i = save_i;
  while (i < save)
    new_champ[x++] = champ[i++];
  new_champ[x] = '.';
  new_champ[++x] = 'c';
  new_champ[++x] = 'o';
  new_champ[++x] = 'r';
  new_champ[++x] = '\0';
  return (new_champ);
}

char	*count_isnt_zero(char *champ, char *new_champ, int i, int count)
{
  int	save;
  int	save_i;
  int	x;

  x = 0;
  while (champ[i] != '\0' && count > 0)
    {
      (champ[i] == '/' ? --count : (count = count));
      ++i;
    }
  save_i = i;
  while (champ[i] != '\0')
    ++i;
  while (champ[i] != '.' && i > 0)
    --i;
  save = i;
  i = save_i;
  while (i < save)
    new_champ[x++] = champ[i++];
  new_champ[x] = '.';
  new_champ[++x] = 'c';
  new_champ[++x] = 'o';
  new_champ[++x] = 'r';
  new_champ[++x] = '\0';
  return (new_champ);
}

char		*get_champion_name(char *champ)
{
  int		i;
  int		count;
  char		*new_champ;
  int		x;

  i = -1;
  count = 0;
  x = 0;
  if ((new_champ = malloc((my_strlen(champ) + 5) * sizeof(char))) == NULL)
    return (put_error("Cannot perform MALLOC.\n"));
  while (champ[++i] != '\0')
    if (champ[i] == '/')
      ++count;
  i = 0;
  if (count == 0)
    return (count_is_zero(champ, new_champ, i, x));
  else if (count != 0)
    return (count_isnt_zero(champ, new_champ, i, count));
  return (NULL);
}
