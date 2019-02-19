/*
** convert_base.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:30:05 2017 John Doe
** Last update Fri Feb 17 16:30:06 2017 John Doe
*/

#include "my.h"

char	*eightbit(char *str)
{
  int	size;
  int	i;
  int	z;
  char	*nb_convert;

  if ((nb_convert = xmalloc(sizeof(char) *10)) == NULL)
    return (NULL);
  size = my_strlen(str);
  size = 8 - size;
  i = 0;
  z = 0;
  while (i < size)
    nb_convert[i++] = '0';
  while (str[z] != '\0')
    nb_convert[i++] = str[z++];
  nb_convert[i] = '\0';
  return (nb_convert);
}

char	*convert_base_char(int nb, char *base)
{
  int	size;
  int	power;
  int	nbr;
  char	*str;
  int	i;

  i = 0;
  if (nb == 1)
    return ("00000001");
  if ((str = xmalloc(10)) == NULL)
    return (NULL);
  size = my_strlen(base);
  power = 1;
  while ((nb / power) >= size)
    power = power * size;
  while (power > 0)
    {
      nbr = (nb / power) % size;
      str[i++] = base[nbr];
      power = power / size;
    }
  str[i] = '\0';
  if ((str = eightbit(str)) == NULL)
    return (NULL);
  return (str);
}

int	cut_number(int nb, int i)
{
  if (i == 1)
    {
      nb = nb / 10;
      return (nb);
    }
  else if (i == 2)
    {
      nb = nb % 10;
      return (nb);
    }
  return (0);
}

int	my_putnbr_base(int nb)
{
  int	i;
  int	result;
  int	a;

  a = 1;
  i = 0;
  result = 0;
  while (nb >= 1)
    {
      result = nb % 10;
      nb = nb / 10;
      i = i + (result * a);
      a = a * 2;
    }
  return (i);
}
