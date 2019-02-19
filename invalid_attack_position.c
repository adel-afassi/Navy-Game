/*
** invalid_attack_position.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:30:54 2017 John Doe
** Last update Fri Feb 17 16:30:55 2017 John Doe
*/

#include "my.h"

int	check_wrong_attack(char *ptr)
{
  if (ptr == NULL)
    {
      my_putchar('\n');
      return (10);
    }
  if (my_strlen(ptr) != 2)
    return (10);
  ptr = restore_attack_position(ptr);
  if (ptr[0] < 'A' || ptr[0] > 'H')
    return (10);
  if (ptr[1] < '1' || ptr[1] > '8')
    return (10);
  return (0);
}

char	*change_letter(char *position)
{
  int	i;

  i = 0;
  while (position[i] != '\0')
    {
      if (position[i] >= 65 && position[i] <= 72)
	position[i] = position[i] - 16;
      i++;
    }
  return (position);
}

char	*int_to_char(int nb)
{
  int	save;
  char	*str;
  int	i;
  char	c;

  i = 0;
  if ((str = xmalloc(3)) == NULL)
    return (NULL);
  save = nb;
  while (nb > 0)
    {
      save = nb % 10;
      str[i++] = save + 48;
      nb = nb / 10;
    }
  str[2] = '\0';
  c = str[0];
  str[0] = str[1];
  str[1] = c;
  return (str);
}

char	*change_nb(char *position)
{
  if (position[0] >= '1' && position[0] <= '8')
    position[0] = position[0] + 16;
  return (position);
}
