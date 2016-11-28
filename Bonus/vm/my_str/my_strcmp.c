/*
** my_strcmp.c for my_strcmp in /home/saurs_f/rendu/Piscine_C_J06/ex_05
**
** Made by Florian Saurs
** Login   <saurs_f@epitech.net>
**
** Started on  Mon Oct  6 15:35:12 2014 Florian Saurs
** Last update Mon Mar 23 09:48:45 2015 Florian Saurs
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0')
    {
      i = i + 1;
    }
  i = s1[i] - s2[i];
  return (i);
}
