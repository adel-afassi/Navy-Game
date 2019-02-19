##
## Makefile for  in /home/adel/PSU_2016_navy/
##
## Made by John Doe
## Login   <login_x@epitech.eu>
##
## Started on  Fri Feb 17 16:28:28 2017 John Doe
## Last update Fri Feb 17 17:02:18 2017 adel
##

CC	=	gcc -Wextra -Wall

RM	=	rm -f

LIBS 	= 	-L. -lgnl

INCL 	= 	-I.

NAME	=	navy

SRC	=	my_strcmp.c			\
		boat.c				\
		boat_bis.c			\
		my_putstr.c			\
		my_getnbr.c			\
		my_str_to_wordtab.c		\
		restore_attack_position.c	\
		invalid_navy_file.c		\
		invalid_navy_file_bis.c		\
		navy.c				\
		main.c				\
		fonction_bis.c			\
		convert_base.c			\
		send_attack.c			\
		victory.c			\
		receive_attack.c		\
		handle.c			\
		restore_navy_file.c		\
		parsing.c			\
		fonction.c			\
		skirt_handle.c			\
		check_fonction.c		\
		navy_shorcut.c			\
		invalid_attack_position.c

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
