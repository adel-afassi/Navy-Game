/*
** fonction.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:29:57 2017 John Doe
** Last update Fri Feb 17 16:29:59 2017 John Doe
*/

#include "my.h"

int	get_bin(char *str)
{
  int	bin;

  bin = 0;
  bin = my_getnbr(str);
  bin = my_putnbr_base(bin);
  return (bin);
}

char	*get_gnl()
{
  char	*str_bin;

  my_putstr("attack: ");
  while ((check_wrong_attack(str_bin = get_next_line(0))) == 10)
    {
      my_putstr("Wrong position\n");
      my_putstr("attack: ");
      str_bin = NULL;
    }
  my_putstr(str_bin);
  my_putstr(": ");
  return (str_bin);
}

int	mini_send(char *str_bin, int receive)
{
  int	bin;
  int	col;
  int	line;

  str_bin = change_letter(str_bin);
  bin = my_getnbr(str_bin);
  col = cut_number(bin, 1) - 1;
  line = cut_number(bin, 2) - 1;
  put_in_his_map(col, line, 1997);
  free(str_bin);
  if ((str_bin = convert_base_char(bin, "01")) == NULL)
    return (84);
  if ((ping(str_bin, receive, g_var.pid_player)) == 84)
    return (84);
  return (bin);
}

void	my_putmessage(char *str, int i)
{
  if (i == 0)
    {
      my_putstr(str);
      my_putstr(" :hit\n\n");
    }
  else if (i == 1)
    {
      my_putstr(str);
      my_putstr(" :missed\n\n");
    }
}

char	**put_x_and_o(char **map, int line, int col, char *decimal_attack)
{
  if ((xusleep(100000)) == 84)
    return (NULL);
  if (map[line][col] >= '2' && map[line][col] <= '5')
    {
      map[line][col] = 'x';
      if ((xkill(g_var.pid_player, 10)) == 84)
	return (NULL);
      my_putmessage(decimal_attack, 0);
    }
  else if (map[line][col] != 'x')
    {
      map[line][col] = 'o';
      if ((xkill(g_var.pid_player, 12)) == 84)
	return (NULL);
      my_putmessage(decimal_attack, 1);
    }
  else if (map[line][col] == 'x')
    {
      if ((xkill(g_var.pid_player, 12)) == 84)
	return (NULL);
      my_putmessage(decimal_attack, 1);
    }
  return (map);
}
