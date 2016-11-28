/*
** my_revstr.c for my_revstr in /home/saurs_f
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Fri Oct  3 08:41:18 2014 Florian Saurs
** Last update Tue Dec  2 13:48:40 2014 Florian Saurs
*/

int	my_boucle(int c, char *str)
{
  while (str[c] != '\0')
    {
      c = c + 1;
    }
  c = c - 1;
  return (c);
}

char	*my_revstr(char *str)
{
  char	i;
  int	c;
  int	d;
  char	*a;
  char	*b;

  i = 0;
  d = 0;
  c = 0;
  c = my_boucle(c, str);
  a = &str[d];
  b = &str[c];
  while (a != b && d < c)
    {
      a = &str[d];
      b = &str[c];
      i = *a;
      *a = *b;
      *b = i;
      d = d + 1;
      c = c - 1;
    }
  return (str);
}
