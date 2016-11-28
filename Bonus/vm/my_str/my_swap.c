/*
** my_swap.c for my_swap in /home/saurs_f
** 
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
** 
** Started on  Fri Oct  3 01:27:30 2014 Florian Saurs
** Last update Tue Oct  7 15:04:45 2014 Florian Saurs
*/

int	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
