/*
** indirect_value.c for indirect_value in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Thu Mar 19 18:12:27 2015 Nyrandone Noboud-Inpeng
** Last update Mon Apr 13 14:44:20 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	check_overflow(char *str, int line, char *data)
{
  int	nbr;
  int	i;
  int	x;

  i = 0;
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
  if (((nbr = getnbr_overflow(str)) == -1 && my_getnbr(str) != -1)
      || nbr > IDX_MOD)
    return (warning_idxmod(line));
  return (0);
}

int		return_value_x(char *data, int *i, int *check, int mark)
{
  int		x;
  int		count;

  x = 0;
  count = 0;
  if (mark == 0)
    {
      if (data[x] == '%')
	{
	  while ((data[x] == '%' || data[x] == ':') && data[x] != '\0')
	    {
	      if (data[x] == ':')
		++count;
	      ++x;
	    }
	  if (count == 0)
	    return (-1);
	}
    }
  else
    if (data[x++] != ':')
      return (-1);
  *i = 0;
  *check = 0;
  return (x);
}

int		compare_lab_to_args(t_list *list, char *data, int mark)
{
  t_list	*elem;
  int		i;
  int		x;
  int		check;

  elem = list->next;
  while (elem != list)
    {
      if ((x = return_value_x(data, &i, &check, mark)) == -1)
	return (-1);
      if (elem->lab != -1)
	{
	  while (elem->label[i] != '\0' && elem->label[i] != ':')
	    {
	      (elem->label[i] != data[x] ? ++check : (check = check));
	      ++i;
	      (data[x] != '\0' ? ++x : (x = x));
	    }
	  (elem->label[i] == '\0' && data[x] != '\0' ? ++check : (check = check));
	  if (check == 0)
	    return (0);
	}
      elem = elem->next;
    }
  return (-1);
}

int	check_indirect(t_list *list, char *data, int line)
{
  int	i;
  char	*str;
  int	ret_value;

  i = 0;
  ret_value = check_hexa(data, i, line);
  if (ret_value == -1 || ret_value == 0)
    return (0);
  else if (ret_value == -2)
    return (-2);
  if ((compare_lab_to_args(list, data, 1)) == 0)
    return (0);
  if ((data[i] >= '0' && data[i] <= '9') || data[i] == '+' || data[i] == '-')
    {
      if ((str = malloc((my_strlen(data) + 1) * sizeof(char))) == NULL)
	{
	  my_puterr("\nCannot perform MALLOC.\n");
	  return (-2);
	}
      if ((check_overflow(str, line, data)) == -1)
	return (-1);
      free(str);
      return (0);
    }
  return (-1);
}
