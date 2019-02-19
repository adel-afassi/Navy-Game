/*
** my_str_to_wordtab.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:31:55 2017 John Doe
** Last update Fri Feb 17 16:31:57 2017 John Doe
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	line_count(char *s)
{
  int	i;
  int	line;

  i = 0;
  line = 0;
  if (s == NULL || s[0] == '\0')
    return (10);
  while (s[i] != '\0')
    {
      if (s[i] == '\n')
	line++;
      i++;
    }
  line = line + 2;
  return (line);
}

char		**my_str_to_wordtab(char *str)
{
  t_wordtab	v;

  v.i = 0;
  v.line = 0;
  v.col = 0;
  if (str == NULL || str[0] == '\0')
    return (NULL);
  if ((v.tab = malloc(sizeof(char*) * (line_count(str)))) == NULL)
    return (NULL);
  while (str[v.i])
    {
      if ((v.tab[v.line] = malloc(sizeof(char) * (my_strlen(str)))) == NULL)
	return (NULL);
      while (str[v.i] != '\n' && str[v.i] != '\0')
	v.tab[v.line][v.col++] = str[v.i++];
      v.tab[v.line][v.col] = '\0';
      v.i++;
      v.col = 0;
      v.line++;
    }
  v.tab[v.line] = NULL;
  return (v.tab);
}
