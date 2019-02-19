/*
** handle.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:30:46 2017 John Doe
** Last update Fri Feb 17 16:30:47 2017 John Doe
*/

#include "my.h"

void	player1_connected(int sig, siginfo_t *siginfo, void *context)
{
  (void)context;
  (void)sig;
  g_var.pid_player = siginfo->si_pid;
  my_putstr("enemy connected\n\n");
}

void	player2_connected(int sig, siginfo_t *siginfo, void *context)
{
  (void)siginfo;
  (void)sig;
  (void)context;
  my_putstr("successfully connected\n\n");
}

void	touch_boat(int sig, siginfo_t *siginfo, void *context)
{
  (void)context;
  (void)siginfo;
  put_in_his_map(0, 0, sig);
}

int		the_reply_attack()
{
  struct sigaction	act;

  act.sa_flags = SA_SIGINFO;
  act.sa_sigaction = &touch_boat;
  if ((sigaction(10, &act, NULL)) == -1)
    {
      my_puterror("SIGACTION ERROR\n");
      return (84);
    }
  if ((sigaction(12, &act, NULL)) == -1)
    {
      my_puterror("SIGACTION ERROR\n");
      return (84);
    }
  pause();
  act.sa_sigaction = &nothing;
  return (0);
}
