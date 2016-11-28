/*
** dictionnary.c for dictionnary in /home/noboud_n/rendu/CPE/Corewar/src
** 
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.net>
** 
** Started on  Wed Mar 11 16:38:21 2015 Nyrandone Noboud-Inpeng
** Last update Fri Mar 27 17:15:58 2015 Nyrandone Noboud-Inpeng
*/

#include "asm.h"

void	dictionnary(char **dict)
{
  dict[0] = "live";
  dict[1] = "ldi";
  dict[2] = "sti";
  dict[3] = "add";
  dict[4] = "sub";
  dict[5] = "and";
  dict[6] = "or";
  dict[7] = "xor";
  dict[8] = "zjmp";
  dict[9] = "ld";
  dict[10] = "st";
  dict[11] = "fork";
  dict[12] = "lldi";
  dict[13] = "lld";
  dict[14] = "lfork";
  dict[15] = "aff";
  dict[16] = NULL;
}

void	dictionnary_order(char **dict)
{
  dict[0] = "live";
  dict[1] = "ld";
  dict[2] = "st";
  dict[3] = "add";
  dict[4] = "sub";
  dict[5] = "and";
  dict[6] = "or";
  dict[7] = "xor";
  dict[8] = "zjmp";
  dict[9] = "ldi";
  dict[10] = "sti";
  dict[11] = "fork";
  dict[12] = "lld";
  dict[13] = "lldi";
  dict[14] = "lfork";
  dict[15] = "aff";
  dict[16] = NULL;
}

int	*dictionnary_hexa(int *tab)
{
  if ((tab = malloc(sizeof(int *) * 17)) == NULL)
    return (NULL);
  tab[0] = 0x01 % 256;
  tab[1] = 0x02 % 256;
  tab[2] = 0x03 % 256;
  tab[3] = 0x04 % 256;
  tab[4] = 0x05 % 256;
  tab[5] = 0x06 % 256;
  tab[6] = 0x07 % 256;
  tab[7] = 0x08 % 256;
  tab[8] = 0x09 % 256;
  tab[9] = 0x0a % 256;
  tab[10] = 0x0b % 256;
  tab[11] = 0x0c % 256;
  tab[12] = 0x0d % 256;
  tab[13] = 0x0e % 256;
  tab[14] = 0x0f % 256;
  tab[15] = 0x10 % 256;
  tab[16] = -1;
  return (tab);
}
