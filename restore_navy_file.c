/*
** restore_navy_file.c for  in /home/adel/PSU_2016_navy/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 17 16:32:38 2017 John Doe
** Last update Fri Feb 17 16:33:14 2017 John Doe
*/

#include "my.h"

char	**my_swap(char **pos, int line, int a, int b)
{
  char	save;

  save = pos[line][a];
  pos[line][a] = pos[line][b];
  pos[line][b] = save;
  return (pos);
}

char		**lowercase_to_uppercase(char **pos)
{
  t_check	var;

  var.a = 0;
  var.i = 0;
  while (pos[var.i] != NULL)
    {
      while (pos[var.i][var.a] != '\0')
	{
	  if (pos[var.i][var.a] >= 'a' && pos[var.i][var.a] <= 'z')
	    pos[var.i][var.a] = pos[var.i][var.a] - 32;
	  var.a++;
	}
      var.i++;
      var.a = 0;
    }
  return (pos);
}

char		**restore_organization(char **pos)
{
   t_check	var;

  var.i = 0;
  while (pos[var.i] != NULL)
    {
      if (pos[var.i][2] >= '0' && pos[var.i][2] <= '9')
	pos = my_swap(pos, var.i, 2, 3);
      if (pos[var.i][5] >= '0' && pos[var.i][5] <= '9')
	pos = my_swap(pos, var.i, 5, 6);
      var.i++;
    }
  var.i = 0;
  while (pos[var.i] != NULL)
    {
      if (pos[var.i][3] > pos[var.i][6])
	{
	  pos = my_swap(pos, var.i, 3, 6);
	  pos = my_swap(pos, var.i, 2, 5);
	}
      var.i++;
    }
  return (pos);
}

char	**restore_organization_bis(char **pos)
{
  t_check	var;

  var.i = 0;
  while (pos[var.i] != NULL)
    {
      if (pos[var.i][2] > pos[var.i][5])
	pos = my_swap(pos, var.i, 2, 5);
      var.i++;
    }
  return (pos);
}

char	**restore_navy_file(char **pos)
{
  pos = lowercase_to_uppercase(pos);
  pos = restore_organization(pos);
  pos = restore_organization_bis(pos);
  return (pos);
}
