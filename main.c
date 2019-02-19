/*
** main.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:31:28 2017 John Doe
** Last update Fri Feb 17 17:23:09 2017 adel
*/

#include "my.h"

int	navy_player1(char **map)
{
  int	check;

  if ((g_var.map_player = create_map()) == NULL)
    {
      my_puterror("MALLOC ERROR\n");
      return (84);
    }
  if ((connexion_player1(map)) == 84)
    return (84);
  if ((check = navy_shorcut(map)) != 10)
    return (check);
  return (10);
}

int	navy_player2(char **map, char **av)
{
  int	check;

  if ((g_var.map_player = create_map()) == NULL)
    {
      my_puterror("MALLOC ERROR\n");
      return (84);
    }
  if ((connexion_player2(map, av)) == 84)
    return (84);
  if ((check = navy_shorcut2(map)) != 10)
    return (check);
  return (10);
}

int	main(int ac, char **av)
{
  char	**map;
  int	a;

  if (ac == 2)
    {
      if (my_strcmp(av[1], "-h") == 0)
	{
	  message_h();
	  return (0);
	}
      if ((map = put_boat_on_map(av, 1)) == NULL)
	return (84);
      if ((a = navy_player1(map)) != 10)
	return (a);
    }
  else if (ac == 3)
    {
      if ((map = put_boat_on_map(av, 2)) == NULL)
	return (84);
      if ((a = navy_player2(map, av)) != 10)
	return (a);
    }
  return (0);
}
