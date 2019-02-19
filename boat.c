/*
** boat.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:30:27 2017 John Doe
** Last update Fri Feb 17 16:30:28 2017 John Doe
*/

#include "my.h"

char	**position_clean(char **position)
{
  int	line;
  int	col;

  line = 0;
  col = 0;
  while (position[line] != NULL)
    {
      while (position[line][col] != '\0' && position[line][col] != '\n')
	{
	  if (position[line][col] >= 65 && position[line][col] <= 90)
	    position[line][col] = position[line][col] - 16;
	  col++;
	}
      col = 0;
      line++;
    }
  return (position);
}

char	**boat_position(char **av, int i)
{
  char	*buf;
  char	**position;
  int	ret;

  ret = 0;
  if ((buf = open_read(av[i])) == NULL)
    return (NULL);
  if ((position = my_str_to_wordtab(buf)) == NULL)
    {
      my_puterror("WORDTAB ERROR\n");
      return (NULL);
    }
  if ((ret = parsing_and_check(buf, position)) == 10)
    {
      my_puterror("INVALID NAVY FILE\n");
      return (NULL);
    }
  position = position_clean(position);
  free(buf);
  return (position);
}

char	**put_it(char **map, char **position, t_boat *var)
{
  if (position[var->line][var->col] == position[var->line][var->col + 3])
    {
      var->letter1 = my_getcharnbr(position[var->line][var->col]) - 1;
      var->nb1 = my_getcharnbr(position[var->line][var->col + 1]) - 1;
      var->last_var = my_getcharnbr(position[var->line][var->col + 4]) - 1;
      while (var->nb1 <= var->last_var)
	{
	  if ((map = shorcut_put_it(map, position, var)) == NULL)
	    return (NULL);
	}
    }
  else if (position[var->line][var->col] != position[var->line][var->col + 3])
    {
      var->letter1 = my_getcharnbr(position[var->line][var->col]) - 1;
      var->nb1 = my_getcharnbr(position[var->line][var->col + 1]) - 1;
      var->last_var = my_getcharnbr(position[var->line][var->col + 3]) - 1;
      while (var->letter1 <= var->last_var)
	{
	  if ((map = shorcut_put_it2(map, position, var)) == NULL)
	    return (NULL);
	}
    }
  return (map);
}

char	**put_boat_on_map(char **av, int i)
{
  t_boat	var;
  char	**position;
  char	**map;

  var.line = 0;
  if ((position = boat_position(av, i)) == NULL)
    return (NULL);
  if ((map = create_map()) == NULL)
    {
      my_puterror("MALLOC ERROR\n");
      return (NULL);
    }
  while (position[var.line] != NULL)
    {
      var.letter1 = 0;
      var.nb1 = 0;
      var.last_var = 0;
      var.col = 2;
      if ((map = put_it(map, position, &var)) == NULL)
	return (NULL);
      var.line++;
    }
  free(position);
  return (map);
}
