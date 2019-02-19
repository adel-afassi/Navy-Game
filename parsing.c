/*
** parsing.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:32:17 2017 John Doe
** Last update Fri Feb 17 16:32:18 2017 John Doe
*/

#include "my.h"

int	parsing_and_check(char *buf, char **pos)
{
  int	ret;

  ret = 0;
  pos = restore_navy_file(pos);
  if ((ret = check_invalid_char(buf, pos)) == 10)
    return (10);
  if ((ret = check_invalid_boat_size(pos)) == 10)
    return (10);
  if ((ret = check_invalid_boat_position(pos)) == 10)
    return (10);
  if ((ret = check_invalid_boat_position2(pos)) == 10)
    return (10);
  if ((ret = check_invalid_char_position_bis(1, pos)) == 10)
    return (10);
  if ((ret = check_invalid_char_position_bis(4, pos)) == 10)
    return (10);
  if ((ret = check_invalid_char_position(2, pos)) == 10)
    return (10);
  if ((ret = check_invalid_char_position(5, pos)) == 10)
    return (10);
  if ((ret = check_invalid_int_position(3, pos)) == 10)
    return (10);
  if ((ret = check_invalid_int_position(6, pos)) == 10)
    return (10);
  return (0);
}
