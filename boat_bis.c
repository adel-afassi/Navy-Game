/*
** boat_bis.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:30:20 2017 John Doe
** Last update Fri Feb 17 16:30:21 2017 John Doe
*/

#include "my.h"

char	**shorcut_put_it(char **map, char **position, t_boat *var)
{
  if (map[var->nb1][var->letter1] < '2' || map[var->nb1][var->letter1] > '5')
    map[var->nb1++][var->letter1] = position[var->line][0];
  else
    {
      my_puterror("INVALID NAVY FILE1\n");
      return (NULL);
    }
  return (map);
}

char	**shorcut_put_it2(char **map, char **position, t_boat *var)
{
  if (map[var->nb1][var->letter1] < '2' || map[var->nb1][var->letter1] > '5')
    map[var->nb1][var->letter1++] = position[var->line][0];
  else
    {
      my_puterror("INVALID NAVY FILE2\n");
      return (NULL);
    }
  return (map);
}
