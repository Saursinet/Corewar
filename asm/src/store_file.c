/*
** store_file.c for store_file in /home/noboud_n/rendu/CPE/Corewar
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Wed Mar 11 13:10:18 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 27 01:00:55 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

void		error_open(char *to_open)
{
  write(2, CYAN, 5);
  write(2, BOLD, 4);
  my_puterr("Error : the file ");
  write(2, DEFAULT, 4);
  write(2, RED, 5);
  write(2, BOLD, 4);
  my_puterr(to_open);
  write(2, DEFAULT, 4);
  write(2, CYAN, 5);
  write(2, BOLD, 4);
  my_puterr(" cannot be reached.\n");
  write(2, DEFAULT, 4);
}

t_list		*store_file(char *to_open)
{
  int		fd;
  t_list	*list;
  char		*str;

  if ((fd = open(to_open, O_RDONLY)) == -1)
    {
      error_open(to_open);
      return (NULL);
    }
  if ((list = init_list()) == NULL)
    return (put_error("Cannot perform MALLOC.\n"));
  while ((str = get_next_line(fd)))
    {
	if ((list = add_data(list, str)) == NULL)
	  return (put_error("Cannot perform MALLOC.\n"));
      free(str);
    }
  if ((close(fd)) == -1)
    return (put_error("Error : close failed.\n"));
  return (list);
}
