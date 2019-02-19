/*
** victory.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:33:37 2017 John Doe
** Last update Fri Feb 17 16:33:38 2017 John Doe
*/

#include "my.h"

int	check_victory(char **map)
{
  int	line;
  int	col;
  int	x;

  line = 0;
  col = 0;
  x = 0;
  while (map[line] != NULL)
    {
      while (map[line][col] != '\0')
	{
	  if (map[line][col] == 'x')
	    x++;
	  col++;
	}
      line++;
      col = 0;
    }
  if (x == 14)
    return (1997);
  return (0);
}

int	victory(char **his_map, char **my_map)
{
  if ((check_victory(his_map)) == 1997)
    {
      print_map(my_map, "my positions:\n");
      print_map(g_var.map_player, "enemy's positions:\n");
      my_putstr("I won\n");
      return (1);
    }
  if ((check_victory(my_map)) == 1997)
    {
      print_map(my_map, "my positions:\n");
      print_map(g_var.map_player, "enemy's positions:\n");
      my_putstr("Enemy won\n");
      return (2);
    }
  return (0);
}

int	victory2(char **his_map, char **my_map)
{
  if ((check_victory(his_map)) == 1997)
    {
      print_map(my_map, "my positions:\n");
      print_map(g_var.map_player, "enemy's positions:\n");
      my_putstr("I won\n");
      return (2);
    }
  if ((check_victory(my_map)) == 1997)
    {
      print_map(my_map, "my positions:\n");
      print_map(g_var.map_player, "enemy's positions:\n");
      my_putstr("Enemy won\n");
      return (1);
    }
  return (0);
}
