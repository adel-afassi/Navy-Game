/*
** navy.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:32:03 2017 John Doe
** Last update Sun Feb 19 16:05:06 2017 John Doe
*/

#include "my.h"

int		connexion_player1(char **map)
{
  struct sigaction	act;

  act.sa_flags = SA_SIGINFO;
  act.sa_sigaction = &player1_connected;
  my_putstr("my_pid:  ");
  my_putnbr(getpid());
  my_putchar('\n');
  my_putstr("waiting for enemy connexion...\n");
  if ((sigaction(12, &act, NULL)) < 0)
    {
      my_puterror("SIGACTION ERRROR\n");
      return (84);
    }
  pause();
  if ((xkill(g_var.pid_player, 10)) == 84)
    return (84);
  print_map(map, "my positions:\n");
  print_map(g_var.map_player, "enemy's positions:\n");
  return (0);
}

int		connexion_player2(char **map, char **av)
{
  struct sigaction	act;

  act.sa_flags = SA_SIGINFO;
  act.sa_sigaction = &player2_connected;
  my_putstr("my_pid:  ");
  my_putnbr(getpid());
  my_putchar('\n');
  g_var.pid_player = my_getnbr(av[1]);
  if ((xkill(g_var.pid_player, 12)) == 84)
    return (84);
  if ((sigaction(10, &act, NULL)) < 0)
    {
      my_puterror("SIGACTION ERROR\n");
      return (84);
    }
  pause();
  print_map(map, "my positions:\n");
  print_map(g_var.map_player, "enemy's positions:\n");
  return (0);
}

int	get_and_send_attack(int receive)
{
  char	*str_bin;

  if ((str_bin = get_gnl()) == NULL)
    return (84);
  if ((mini_send(str_bin, receive)) == 84)
    return (84);
  free(str_bin);
  if ((the_reply_attack()) == 84)
    return (84);
  return (0);
}

int	receive_and_reply_attack(char **map, int send)
{
  int	bin;
  char	*decimal_attack;
  char	*str;
  int	col;
  int	line;

  my_putstr("waiting for enemy's attack...\n");
  if ((pong(send, g_var.pid_player)) == 84)
    return (84);
  if ((str = copy_bin(2, 1997)) == NULL)
    return (84);
  bin = get_bin(str);
  if ((decimal_attack = int_to_char(bin)) == NULL)
    return (84);
  decimal_attack[0] = decimal_attack[0] + 16;
  col = cut_number(bin, 1) - 1;
  line = cut_number(bin, 2) - 1;
  if ((map = put_x_and_o(map, line, col, decimal_attack)) == NULL)
    return (84);
  return (0);
}
