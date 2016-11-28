/*
** my_list.c for corewar in /home/saursf/rendu/CPE_2014_corewar/corewar
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Thu Apr 16 00:36:01 2015 Florian Saurs
** Last update Thu Apr 16 01:05:12 2015 Florian Saurs
*/

#include "types.h"

void		init_k(t_check *k)
{
  k->field = 0;
  k->check_a = -1;
  k->check_n = -1;
}

int		my_put_in_list(t_list **list, t_header head, char *prog_data,
			       t_check k)
{
  t_list	*elem;
  static int	i = 0;

  if ((elem = malloc(sizeof(**list))) == NULL)
    exit(EXIT_FAILURE);
  elem->cmpt = i++;
  elem->magic = head.magic;
  elem->prog_name = my_strcpy(head.prog_name);
  elem->prog_size = head.prog_size;
  elem->comment = my_strcpy(head.comment);
  elem->num_prog = k.check_n;
  elem->num_addr = k.check_a;
  elem->prog_data = prog_data;
  elem->prev = *list;
  elem->next = 0;
  if (*list != NULL)
    (*list)->next = elem;
  *list = elem;
  return (0);
}

void		my_rotate_list(t_list **list)
{
  t_list	*tmp;

  tmp = *list;
  while ((*list)->prev != NULL)
    *list = (*list)->prev;
  (*list)->prev = tmp;
  tmp = *list;
  *list = (*list)->prev;
  (*list)->next = tmp;
  *list = (*list)->prev;
}

void		init_func(int (*func[16])())
{
  func[0] = do_live;
  func[1] = do_ld;
  func[2] = do_st;
  func[3] = do_add;
  func[4] = do_sub;
  func[5] = do_and;
  func[6] = do_or;
  func[7] = do_xor;
  func[8] = do_zjmp;
  func[9] = do_ldi;
  func[10] = do_sti;
  func[11] = do_fork;
  func[12] = do_lld;
  func[13] = do_lldi;
  func[14] = do_lfork;
  func[15] = do_aff;
}

void		init_cmd(int *cmd)
{
  cmd[0] = 0x01;
  cmd[1] = 0x02;
  cmd[2] = 0x03;
  cmd[3] = 0x04;
  cmd[4] = 0x05;
  cmd[5] = 0x06;
  cmd[6] = 0x07;
  cmd[7] = 0x08;
  cmd[8] = 0x09;
  cmd[9] = 0x0a;
  cmd[10] = 0x0b;
  cmd[11] = 0x0c;
  cmd[12] = 0x0d;
  cmd[13] = 0x0e;
  cmd[14] = 0x0f;
  cmd[15] = 0x10;
}
