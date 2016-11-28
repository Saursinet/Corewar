/*
** direct_value.c for direct_value in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Thu Mar 19 16:55:48 2015 Nyrandone Noboud-Inpeng
** Last update Mon Apr 13 14:41:51 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	syntax_error_direct(int line)
{
  my_puterr("Syntax error line ");
  my_put_nbr(line);
  my_puterr(" -- ");
  write(2, DEFAULT, 4);
  write(2, RED, 5);
  write(2, BOLD, 4);
  my_puterr("cannot find any value.\n");
  write(2, DEFAULT, 4);
  my_puterr("In case you're trying to use some ");
  my_puterr("hexa's value, please use this base : ");
  write(2, RED, 5);
  write(2, BOLD, 4);
  my_puterr("\"0123456789abcdef\"\n");
  write(2, DEFAULT, 4);
  return (-2);
}

int	error_direct(int line)
{
  write(2, YELLOW, 5);
  write(2, BOLD, 4);
  my_puterr("\nWarning : ");
  write(2, DEFAULT, 4);
  my_puterr("direct too far line ");
  my_put_nbr(line);
  my_puterr(" -- you can avoid random changes on your integer by ");
  write(2, YELLOW, 5);
  write(2, BOLD, 4);
  my_puterr("reducing it.\n\n");
  write(2, DEFAULT, 4);
  return (0);
}

int	direct_checking(char *data, char *str, int line, int i)
{
  int	nbr;
  int	x;

  x = 0;
  while (data[i] != '\0')
    {
      if ((data[i] < '0' || data[i] > '9') && data[i] != '-'
	  && data[i] != '+')
	{
	  str[x] = '\0';
	  free(str);
	  return (-1);
	}
      str[x++] = data[i++];
    }
  str[x] = '\0';
  if ((nbr = getnbr_overflow(str)) == -1 && my_getnbr(str) != -1)
    {
      error_direct(line);
      free(str);
      return (0);
    }
  free(str);
  return (0);
}

int	check_hexa(char *data, int i, int line)
{
  int	count;

  count = 0;
  if (data[i] != '0')
    return (1);
  if (data[i + 1])
    {
      if (data[++i] != 'x')
	return (1);
      if (data[i] == '\0')
	return (syntax_error_direct(line));
    }
  while (data[++i] != '\0')
    {
      if ((char_in_string(data[i], "0123456789abcdef")) == -1)
	return (syntax_error_direct(line));
      ++count;
    }
  if (count > 6)
    {
      error_direct(line);
      return (-1);
    }
  return (0);
}

int	check_direct(t_list *list, char *data, int line)
{
  int	i;
  char	*str;
  int	ret;

  i = 0;
  if (data[i++] == '%')
    {
      if (data[i] == '\0')
	return (syntax_error_direct(line));
      (data[i + 1] ? (ret = check_hexa(data, i, line)) : (ret = 3));
      if (ret == -1 || ret == 0)
	return (0);
      else if (ret == -2)
	return (-2);
      if ((compare_lab_to_args(list, data, 0)) == 0)
	return (0);
      if ((str = malloc((my_strlen(data) + 1) * sizeof(char))) == NULL)
	{
	  my_puterr("\nCannot perform MALLOC.\n");
	  return (-2);
	}
      return (direct_checking(data, str, line, i));
    }
  return (-1);
}
