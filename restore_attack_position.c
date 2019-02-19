/*
** restore_attack_position.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:32:30 2017 John Doe
** Last update Fri Feb 17 16:32:32 2017 John Doe
*/

#include "my.h"

char	*swap(char *pos, int a, int b)
{
  char	save;

  save = pos[a];
  pos[a] = pos[b];
  pos[b] = save;
  return (pos);
}

char	*lower_to_upper(char *pos)
{
  t_check	var;

  var.i = 0;
  while (pos[var.i] != '\0')
    {
      if (pos[var.i] >= 'a' && pos[var.i] <= 'z')
	pos[var.i] = pos[var.i] - 32;
      var.i++;
    }
  return (pos);
}

char	*restore_orga(char *pos)
{
  t_check	var;

  var.i = 0;
  if (pos[0] >= '0' && pos[0] <= '9')
    pos = swap(pos, 0, 1);
  while (pos[var.i] != '\0')
    {
      if (pos[var.i] >= 'a' && pos[var.i] <= 'z')
	pos[var.i] = pos[var.i] - 32;
      var.i++;
    }
  return (pos);
}

char	*restore_attack_position(char *pos)
{
  pos = lower_to_upper(pos);
  pos = restore_orga(pos);
  return (pos);
}
