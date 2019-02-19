/*
** invalid_navy_file_bis.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:31:03 2017 John Doe
** Last update Fri Feb 17 16:31:04 2017 John Doe
*/

#include "my.h"

int	check_invalid_char_position_bis(int col, char **pos)
{
  t_check	var;

  var.a = 0;
  var.i = 0;
  var.b = col;
  while (var.i <= 3)
    {
      if (pos[var.i][var.b] == ':')
	var.a++;
      var.i++;
    }
  if (var.a != var.i)
    return (10);
  return (0);
}

int	check_invalid_char_position(int col, char **pos)
{
  t_check	var;

  var.a = 0;
  var.i = 0;
  var.b = col;
  while (var.i <= 3)
    {
      if (pos[var.i][var.b] >= 'A' && pos[var.i][var.b] <= 'H')
	var.a++;
      var.i++;
    }
  if (var.a != var.i)
    return (10);
  return (0);
}

int	check_invalid_int_position(int col, char **pos)
{
  t_check	var;

  var.a = 0;
  var.i = 0;
  var.b = col;
  while (var.i <= 3)
    {
      if (pos[var.i][var.b] >= '1' && pos[var.i][var.b] <= '8')
	var.a++;
      var.i++;
    }
  if (var.a != var.i)
    return (10);
  return (0);
}

int	check_invalid_boat_position3(int line, char **pos)
{
  t_check	var;

  var.a = my_getcharnbr(pos[line][2]) - 16;
  var.b = my_getcharnbr(pos[line][5]) - 16;
  var.c = my_getcharnbr(pos[line][0]);
  var.d = var.b - var.a;
  if (var.d != (var.c - 1))
    return (10);
  return (0);
}
