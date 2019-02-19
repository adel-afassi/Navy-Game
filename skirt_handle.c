/*
** skirt_handle.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:33:29 2017 John Doe
** Last update Fri Feb 17 16:33:30 2017 John Doe
*/

#include "my.h"

char		*copy_bin(int x, int sig)
{
  static char	*ptr;
  static int	i = 0;
  static int	z = 0;

  if (x == 1)
    {
      if (z == 0)
	{
	  if ((ptr = xmalloc(9)) == NULL)
	    return (NULL);
	}
      z = 100;
      if (sig == 10)
	ptr[i++] = '0';
      else if (sig == 12)
	ptr[i++] = '1';
      if (i == 8)
	{
	  ptr[i] = '\0';
	  i = 0;
	}
    }
  else if (x == 2)
    return (ptr);
  return (NULL);
}

int		put_in_his_map(int col, int line, int sig)
{
  static int	z = 0;
  static int	i = 0;

  if (sig == 1997)
    {
      z = col;
      i = line;
    }
  else
    {
      if (sig == 10)
	{
	  if (g_var.map_player[i][z] != 'o')
	    g_var.map_player[i][z] = 'x';
	  my_putstr("hit\n\n");
	}
      if (sig == 12)
	{
	  if (g_var.map_player[i][z] != 'x')
	    g_var.map_player[i][z] = 'o';
	  my_putstr("missed\n\n");
	}
    }
  return (0);
}
