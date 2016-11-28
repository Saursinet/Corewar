/*
** header_write.c for header_write in /home/noboud_n/Practice/CPE_2014_corewar/asm/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Wed Apr  8 18:01:39 2015 Nyrandone Noboud-Inpeng
** Last update Wed Apr  8 18:01:48 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

int	cut_header(t_list *header, int sd, int check, t_list **list)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (header != *list)
    {
      if ((header->comment == 1 && check == -1)
	  || (header->name == 1 && check == 0))
	{
	  while (header->data[i++] != '\"');
	  while (header->data[i] != '\"')
	    {
	      my_putchar_fd(header->data[i++], sd);
	      count++;
	    }
	}
      header = header->next;
    }
  return (count);
}

void		header(int sd, t_list **new, t_list **list)
{
  int		check;
  int		count;
  t_list	*header;

  check = 0;
  while (check != 2)
    {
      header = (*list)->next;
      count = cut_header(header, sd, check, list);
      if (check == 0)
	check = prog_name(count, sd, new, list);
      else if (check == -1)
	{
	  while (count++ < COMMENT_LENGTH + 4)
	    my_putchar_fd(0, sd);
	  check = 2;
	}
    }
}
