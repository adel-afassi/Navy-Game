/*
** check_fonction.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:30:13 2017 John Doe
** Last update Fri Feb 17 16:30:14 2017 John Doe
*/

#include "my.h"

char	*xmalloc(int size)
{
  char	*str;

  if ((str = malloc(sizeof(char) * size)) == NULL)
    {
      my_puterror("MALLOC ERROR\n");
      return (NULL);
    }
  return (str);
}

int	xkill(pid_t pid, int sig)
{
  int	check;

  if ((check = kill(pid, sig)) == -1)
    {
      my_puterror("KILL ERROR\n");
      return (84);
    }
  return (0);
}

int	xpause()
{
  int	check;

  if ((check = pause()) == -1)
    {
      my_puterror("PAUSE ERROR\n");
      return (84);
    }
  return (0);
}

int	xusleep(useconds_t usec)
{
  int	check;

  if ((check = usleep(usec)) == -1)
    {
      my_puterror("USLEEP ERROR\n");
      return (84);
    }
  return (0);
}
