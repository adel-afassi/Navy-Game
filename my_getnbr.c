/*
** my_getnbr.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:31:37 2017 John Doe
** Last update Fri Feb 17 16:31:39 2017 John Doe
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	i;
  int	neg;
  int	nb;

  nb = 0;
  i = 0;
  neg = 0;
  while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
    i = i + 1;
  if (str[i - 1] != '\0' && str[i - 1] == '-')
    neg = 1;
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
      nb = nb * 10 + (str[i] - 48);
      i = i + 1;
    }
  if (neg == 1)
    nb = nb * -1;
  return (nb);
}

int	my_getcharnbr(char c)
{
  int	nb;

  nb = 0;
  nb = nb * 10 + (c - 48);
  return (nb);
}
