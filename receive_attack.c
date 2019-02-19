/*
** receive_attack.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:32:24 2017 John Doe
** Last update Fri Feb 17 16:32:26 2017 John Doe
*/

#include "my.h"

void	nothing(int sig, siginfo_t *siginfo, void *context)
{
  (void)siginfo;
  (void)sig;
  (void)context;
}

void	copy_the_bin(int sig, siginfo_t *siginfo, void *context)
{
  (void)siginfo;
  (void)context;
  copy_bin(1, sig);
}

int		pong(int send, pid_t pid)
{
  struct sigaction	act;
  int		z;

  z = 0;
  act.sa_flags = SA_SIGINFO;
  act.sa_sigaction = &copy_the_bin;
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
  while (z < 8)
    {
      pause();
      if ((xkill(pid, send)) == 84)
	return (84);
      z++;
    }
  return (0);
}
