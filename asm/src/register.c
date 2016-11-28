/*
** register.c for register in /home/noboud_n/rendu/CPE/Corewar/src
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
**
** Started on  Thu Mar 19 16:11:48 2015 Nyrandone Noboud-Inpeng
** Last update Wed Apr  8 10:45:27 2015 Alban Combaud
*/

#include "asm.h"

int	error_register(char *data, int line)
{
  arguments_wrong();
  write(2, CYAN, 5);
  write(2, BOLD, 4);
  my_puterr("\nNo such register line ");
  my_put_nbr(line);
  my_puterr(" -- ");
  write(2, DEFAULT, 4);
  write(2, RED, 5);
  write(2, BOLD, 4);
  my_puterr(data);
  my_puterr("\n");
  write(2, DEFAULT, 4);
  return (-2);
}

int	check_failure(char *data, int i, int line)
{
  if (data[i] == '\0')
    return (error_register(data, line));
  return (0);
}

int	string_register(char *str, char *data, int i, int line)
{
  int	x;

  x = 0;
  while (data[i] != '\0')
    {
      if (data[i] < '0' || data[i] > '9')
	{
	  str[x] = '\0';
	  free(str);
	  return (error_register(data, line));
	}
      str[x++] = data[i++];
    }
  str[x] = '\0';
  return (0);
}

int	check_register(char *data, int line)
{
  int	i;
  int	nbr;
  char	*str;

  i = 0;
  if (data[i++] == 'r')
    {
      if ((check_failure(data, i, line)) == -2)
	return (-2);
      if ((str = malloc((my_strlen(data) + 1) * sizeof(char))) == NULL)
	{
	  my_puterr("Cannot perform MALLOC.\n");
	  return (-2);
	}
      if ((string_register(str, data, i, line)) == -2)
	return (-1);
      nbr = getnbr_overflow(str);
      free(str);
      if (nbr < 1 || nbr > 16)
	return (error_register(data, line));
      return (0);
    }
  return (-1);
}
