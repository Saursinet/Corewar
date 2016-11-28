/*
** labels.c for labels in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Wed Mar 11 18:10:13 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 27 12:14:53 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

char	**label_in_list(int x, int *save, t_list *elem, char **labels)
{
  int	i;
  char	*str;

  i = 0;
  *save = x;
  if ((str = malloc((my_strlen(labels[x]) + 1) * sizeof(char))) == NULL)
    return (put_error("Cannot perform MALLOC.\n"));
  while (labels[x][i] != '\0')
    {
      str[i] = labels[x][i];
      i++;
    }
  str[i] = '\0';
  elem->label = str;
  elem->lab = my_strlen(str);
  labels[++x] = NULL;
  return (labels);
}

char	**store_label(int i, int *save, t_list *elem, char **labels)
{
  int	x;
  int	a;
  int	k;

  x = -1;
  a = 0;
  k = 0;
  *save = k;
  k = increment_value_elem(elem, k);
  while (elem->data[k] != ':' && elem->data[k] != '\0' && elem->data[k] != '#'
	 && elem->data[k] != ';')
    ++k;
  while (labels[++x] != NULL);
  if (i - 2 > MALLOC_SIZE - 1)
    if ((labels = my_realloc_dd(labels, MALLOC_SIZE + 1, x)) == NULL)
      return (put_error("Cannot perform MALLOC.\n"));
  if ((labels[x] = malloc((my_strlen(elem->data) + 1) * sizeof(char))) == NULL)
    return (put_error("Cannot perform MALLOC\n"));
  while (*save < (elem->data[k] == ':' ? k + 1 : k))
    labels[x][a++] = elem->data[(*save)++];
  labels[x][a] = '\0';
  if ((labels = label_in_list(x, save, elem, labels)) == NULL)
    return (NULL);
  return (labels);
}

int	identical_label(char **labels, int save, int y, int i)
{
  my_puterr("Label ");
  write(2, RED, 5);
  write(2, BOLD, 4);
  while (labels[save][y] != '\0' && labels[save][y] != ':'
	 && labels[save][y] != SEPARATOR_CHAR
	 && labels[save][y] != COMMENT_CHAR && labels[save][y] != ' '
	 && labels[save][y] != '\t' && labels[save][y] != ';')
    my_put_err(labels[save][y++]);
  write(2, DEFAULT, 4);
  my_puterr(" undefined line ");
  my_put_nbr(i + 1);
  my_puterr(" -- another label already got this name.");
  write(2, DEFAULT, 4);
  free_tab(labels);
  return (my_puterr("\n"));
}

int	compare_all_labels(int i, int save, char **labels)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (labels[x] != NULL && x != save)
    {
      if ((my_strcmp(labels[save], labels[x])) == 0)
	return (identical_label(labels, save, y, i));
      ++x;
    }
  return (0);
}

char	**check_label(int i, t_list *elem, char **labels)
{
  int	save;
  int	k;
  int	mark;

  k = 0;
  mark = 0;
  while (elem->data[k] != ':' && elem->data[k] != '\0'
	 && elem->data[k] != COMMENT_CHAR && elem->data[k] != ';')
    ++k;
  save = k;
  while (--k > 0)
    ((char_in_string(elem->data[k], LABEL_CHARS)) == -1 ? mark = 1 : 0);
  k = save;
  if (elem->data[k] != ':' || k - 1 <= 0 || mark == 1)
    return (labels);
  else
    {
      if ((labels = store_label(i, &save, elem, labels)) == NULL)
	return (NULL);
      if ((compare_all_labels(i, save, labels)) == -1)
	return (NULL);
    }
  return (labels);
}
