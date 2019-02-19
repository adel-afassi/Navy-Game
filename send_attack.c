/*
** send_attack.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:33:22 2017 John Doe
** Last update Fri Feb 17 16:33:24 2017 John Doe
*/

#include "my.h"

int	mini_ping(char *bin, pid_t pid, int i)
{
  if (bin[i] == '0')
    {
      if ((xkill(pid, SIGUSR1)) == 84)
	return (84);
    }
  else if (bin[i] == '1')
    {
      if ((xkill(pid, SIGUSR2)) == 84)
	return (84);
    }
  return (0);
}

int		ping(char *bin, int receive, pid_t pid)
{
  int		i;
  struct sigaction	act;

  i = 0;
  act.sa_flags = SA_SIGINFO;
  act.sa_sigaction = &nothing;
  if ((xusleep(200000)) == 84)
    return (84);
  if ((sigaction(receive, &act, NULL)) == -1)
    {
      my_puterror("SIGACTION ERROR\n");
      return (84);
    }
  while (bin[i] != '\0')
    {
      if ((mini_ping(bin, pid, i)) == 84)
	return (84);
      pause();
      i++;
    }
  return (0);
}
