/*
** my_strcmp.c for  in /home/adel.afassi/delivery/PSU_2016_minishell1
** 
** Made by adel afassi
** Login   <adel.afassi@epitech.net>
** 
** Started on  Sun Jan 22 21:17:30 2017 adel afassi
** Last update Fri Feb 17 17:00:54 2017 adel
*/

#include "my.h"

int	my_strcmp(char *str, char *str2)
{
  int	a;

  a = 0;
  if (my_strlen(str) != my_strlen(str2))
    return (1);
  while (str[a] != '\0')
    {
      if (str[a] != str2[a])
	return (1);
      a++;
    }
  return(0);
}
