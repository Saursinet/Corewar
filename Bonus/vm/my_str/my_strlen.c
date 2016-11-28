/*
** my_strlen.c for my_strlen in /home/saurs_f/rendu/Piscine_C_J04
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Fri Oct  3 00:46:01 2014 Florian Saurs
** Last update Mon Feb 16 16:58:38 2015 Florian Saurs
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
