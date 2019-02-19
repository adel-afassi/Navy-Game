/*
** my.h for  in /home/adel.afassi/delivery/PSU_2016_navy_bootstrap
**
** Made by adel afassi
** Login   <adel.afassi@epitech.net>
**
** Started on  Tue Jan 31 12:17:00 2017 adel afassi
** Last update Fri Feb 17 17:30:47 2017 adel
*/

#ifndef MY_H_
# define MY_H_

#include "gnl.h"
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

extern struct s_globe	g_var;

struct	s_globe
{
  pid_t	pid_player;
  char	**map_player;
};

typedef struct	s_wordtab
{
  char		**tab;
  int		i;
  int		line;
  int		col;
}		t_wordtab;

typedef struct	s_boat
{
  int		line;
  int		col;
  int		letter1;
  int		nb1;
  int		last_var;
}		t_boat;

typedef struct	s_check
{
  char		*buf;
  char		**pos;
  int		a;
  int		b;
  int		c;
  int		d;
  int		i;
}		t_check;

void	message_h();
int	my_strcmp(char *str, char *str2);
char	**restore_organization(char **pos);
char	**lowercase_to_uppercase(char **pos);
char	**my_swap(char **pos, int line, int a, int b);  
int	line_count(char *s);
void	my_putchar_error(char c);
char	*eightbit(char *str);
char	**boat_position(char **av, int i);
char	**put_it(char **map, char **position, t_boat *var);
char	**position_clean(char **position);
void	my_putmessage(char *str, int i);
char	**shorcut_put_it(char **map, char **position, t_boat *var);
char	**shorcut_put_it2(char **map, char **position, t_boat *var);
int	navy_shorcut(char **map);
int	navy_shorcut2(char **map);
char	*xmalloc(int size);
int	xkill(pid_t pid, int sig);
int	xusleep(useconds_t usec);
int	xpause();
char	**put_it(char **map, char **position, t_boat *var);
char	**put_x_and_o(char **map, int line, int col, char *decimal_attack);
int	ping(char *bin, int receive, pid_t pid);
int	pong(int send, pid_t pid);
int	get_bin(char *str);
int	check_victory(char **map);
int	victory(char **his_map, char **my_map);
int	victory2(char **his_map, char **my_map);
int	my_getnbr(char *str);
int	my_strlen(char *str);
int	my_getcharnbr(char c);
void	my_putchar(char c);
int	my_puterror(char *str);
int	my_putnbr(int nb);
int	my_putstr(char *str);
char	**my_str_to_wordtab(char *str);
char	*open_read(char *str);
char	**create_map();
char	**put_boat_on_map (char **av, int i);
int	check_invalid_char(char *buffer, char **pos);
int	check_size_navy_file(char *buffer);
int	check_invalid_boat_size(char **pos);
int	check_invalid_boat_position(char **pos);
int	check_invalid_boat_position2(char **pos);
int	check_invalid_boat_position3(int line, char **pos);
int	invalid_navy_file(char *buf, char **position);
int	navy();
void	print_map(char **map, char *prompt);
int	navy_player1(char **map);
int	navy_player2(char **map, char **av);
char	*my_realloc(char *s, int size);
int	check_wrong_attack(char *ptr);
char	*change_letter(char *ptr);
char	*convert_base_char(int bin, char *base);
int	send_bin(char *bin, int send, int receive, pid_t pid);
int	my_putnbr_base(int nb);
void	player1_connected(int sig, siginfo_t *siginfo, void *context);
void	player2_connected(int sig, siginfo_t *siginfo, void *context);
void	touch_boat(int sig, siginfo_t *siginfo, void *context);
int	receive_bin(int send, int receive, pid_t pid);
int	get_and_send_attack(int receive);
int	receive_and_reply_attack(char **map, int send);
int	cut_number(int nb, int i);
int	connexion_player1(char **map);
int	connexion_player2(char **map, char **av);
void	nothing(int sig, siginfo_t *siginfo, void *context);
int	parsing_and_check(char *buf, char **pos);
char	*int_to_char(int nb);
int	check_invalid_char_position_bis(int col, char **pos);
int	check_invalid_char_position(int col, char **pos);
int	check_invalid_int_position(int col, char **pos);
char	**restore_navy_file(char **pos);
char	*restore_attack_position(char *pos);
char	*restore_orga(char *pos);
char	*lower_to_upper(char *pos);
char	*swap(char *pos, int a, int b);
char	*get_gnl();
int	mini_send(char *str_bin, int receive);
char	*copy_bin(int x, int sig);
void	copy_the_bin(int sig, siginfo_t *siginfo, void *context);
int	the_reply_attack();
int	put_in_his_map(int col, int line, int sig);
char	*change_nb(char *position);

#endif /*MY_H_*/
