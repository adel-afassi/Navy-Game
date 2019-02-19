/*
** my_putstr.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:31:44 2017 John Doe
** Last update Fri Feb 17 16:31:46 2017 John Doe
*/

#include "my.h"

struct s_globe	g_var;

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

int	my_puterror(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar_error(str[i]);
      i++;
    }
  return (0);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int	my_putnbr(int x)
{
  if (x < 0)
    {
      my_putchar('-');
      x = x * (-1);
    }
  if (x >= 0 && x <= 9)
    my_putchar(x + 48);
  if (x > 9)
    {
      my_putnbr(x / 10);
      my_putnbr(x % 10);
    }
  return (0);
}
