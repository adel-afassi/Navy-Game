/*
** fonction_bis.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:30:35 2017 John Doe
** Last update Fri Feb 17 17:29:48 2017 adel
*/

#include "my.h"

char	*open_read(char *str)
{
  char	*buf;
  int	fd;
  int	r;

  r = 0;
  fd = 0;
  if ((buf = malloc(sizeof(char) * 50)) == NULL)
    {
      my_puterror("MALLOC ERROR\n");
      return (NULL);
    }
  if ((fd = open(str, O_RDONLY)) == -1)
    {
      my_puterror("OPEN ERROR\n");
      return (NULL);
    }
  if ((r = read(fd, buf, 48)) == -1)
    {
      my_puterror("READ ERROR\n");
      return (NULL);
    }
  buf[r] = '\0';
  if ((close (fd)) == -1)
    return (NULL);
  return (buf);
}

char	**create_map()
{
  char	**map;
  int	line = 0;
  int	col = 0;

  if ((map = malloc(sizeof(char *) * 10)) == NULL)
    return (NULL);
  while (line < 8)
    {
      if ((map[line] = malloc(sizeof(char) * 10)) == NULL)
	return (NULL);
      while (col < 8)
	{
	  map[line][col] = '.';
	  col++;
	}
      map[line][col] = '\n';
      if (line == 7)
	map[line][col + 1]= '\0';
      col = 0;
      line++;
    }
  map[line] = NULL;
  return (map);
}

void	print_map(char **map, char *prompt)
{
  int	col;
  int	line;
  char	l;

  col = 0;
  line = 0;
  l = 49;
  my_putstr(prompt);
  my_putstr(" |A B C D E F G H\n-+---------------\n");
  while (map[line] != NULL)
    {
      my_putchar(l++);
      my_putchar('|');
      while (map[line][col] != '\n')
	{
	  my_putchar(map[line][col++]);
	  my_putchar(' ');
	}
      my_putchar('\n');
      col = 0;
      line++;
    }
  my_putstr("\n\n");
}

void	message_h()
{
  my_putstr("USAGE\n		");
  my_putstr("./navy [first_player_pid] navy_positions\n\n");
  my_putstr("DESCRIPTION\n");
  my_putstr("		first_player_pid");
  my_putstr("	only for the 2nd player. ");
  my_putstr("pid of the first player.\n");
  my_putstr("		navy_positions		file representing ");
  my_putstr("the positions of the ships.\n");;
}
