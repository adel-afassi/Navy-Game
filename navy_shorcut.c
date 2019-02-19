/*
** navy_shorcut.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:32:09 2017 John Doe
** Last update Fri Feb 17 16:32:11 2017 John Doe
*/

#include "my.h"

int	navy_shorcut(char **map)
{
  int	check;

  while (1)
    {
      if ((get_and_send_attack(12)) == 84)
	return (84);
      if ((check = victory(g_var.map_player, map)) == 1)
	return (0);
      else if (check == 2)
	return (1);
      if ((receive_and_reply_attack(map, 10)) == 84)
	return (84);
      if ((check = victory(g_var.map_player, map)) == 1)
	return (0);
      if (check == 2)
	return (1);
      print_map(map, "my positions:\n");
      print_map(g_var.map_player, "enemy's positions:\n");
    }
  return (10);
}

int	navy_shorcut2(char **map)
{
  int	check;

  while (1)
    {
      if ((receive_and_reply_attack(map, 12)) == 84)
	return (84);
      if ((check = victory2(g_var.map_player, map)) == 1)
	return (1);
      else if (check == 2)
	return (0);
      if ((get_and_send_attack(10)) == 84)
	return (84);
      if ((check = victory2(g_var.map_player, map)) == 1)
	return (1);
      else if (check == 2)
	return (0);
      print_map(map, "my positions:\n");
      print_map(g_var.map_player, "enemy's positions:\n");
    }
  return (10);
}
