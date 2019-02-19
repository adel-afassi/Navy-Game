/*
** invalid_navy_file.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:31:17 2017 John Doe
** Last update Fri Feb 17 16:31:19 2017 John Doe
*/

#include "my.h"

int	check_invalid_char(char *buffer, char **buf)
{
  int	i;
  int	z;

  if ((i = check_size_navy_file(buffer)) == 10)
    return (10);
  i = 0;
  while (buf[i] != NULL)
    {
      z = 0;
      while (buf[i][z] != '\0')
	{
	  if (buf[i][z] >= 49 && buf[i][z] <= 56)
	    z++;
	  else if (buf[i][z] >= 65 && buf[i][z] <= 72)
	    z++;
	  else if (buf[i][z] == '\n' || buf[i][z] == ':')
	    z++;
	  else
	    return (10);
	}
      i++;
    }
  return (0);
}

int	check_size_navy_file(char *buffer)
{
  int	i;

  i = my_strlen(buffer);
  if (i != 32 && i != 31)
    return (10);
  if (i == 31)
    return (0);
  if (i == 32)
    {
      if (buffer[i - 1] == '\n')
	return (0);
      else
	return (10);
    }
  return (0);
}

int	check_invalid_boat_size(char **pos)
{
  t_check	var;

  var.a = 0;
  var.b = 0;
  var.c = 0;
  var.d = 0;
  var.i = 0;
  while (var.i <= 3)
    {
      if (pos[var.i][0] == '2')
	var.a++;
      if (pos[var.i][0] == '3')
	var.b++;
      if (pos[var.i][0] == '4')
	var.c++;
      if (pos[var.i][0] == '5')
	var.d++;
      var.i++;
    }
  if (var.a != 1 || var.b != 1 || var.c != 1 || var.d != 1)
    return (10);
  return (0);
}

int	check_invalid_boat_position(char **pos)
{
  t_check	var;

  var.i = 0;
  while (var.i <= 3)
    {
      var.a = my_getcharnbr(pos[var.i][2]);
      var.b = my_getcharnbr(pos[var.i][5]);
      var.c = var.a - var.b;
      if (var.c != 0)
	{
	  var.a = my_getcharnbr(pos[var.i][3]);
	  var.b = my_getcharnbr(pos[var.i][6]);
	  if (var.a != var.b)
	    return (10);
	  if ((check_invalid_boat_position3(var.i, pos)) == 10)
	    return (10);
	}
      var.i++;
    }
  return (0);
}

int	check_invalid_boat_position2(char **pos)
{
  t_check	var;

  var.i = 0;
  while (var.i <= 3)
    {
      var.a = my_getcharnbr(pos[var.i][2]);
      var.b = my_getcharnbr(pos[var.i][5]);
      var.c = var.a - var.b;
      var.d = my_getcharnbr(pos[var.i][0]);
      if (var.c == 0)
	{
	  var.a = my_getcharnbr(pos[var.i][3]);
	  var.b = my_getcharnbr(pos[var.i][6]);
	  var.c = var.b - var.a;
	  if (var.c != (var.d - 1))
	    return (10);
	}
      var.i++;
    }
  return (0);
}
