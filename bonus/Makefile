##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## libmy.a
##

SRC	=	src/main.c	\
		src/execute_buffer.c	\
		src/alias.c	\
		src/manage_alias.c	\
		../src/manage_env.c	\
		../src/prompt.c	\
		../src/init_env.c	\
		../src/my_env.c	\
		../src/setenv.c	\
		src/fonction_shell.c	\
		../src/unsetenv.c	\
		../src/change_directory.c	\
		../src/my_exit.c	\

OBJ	=	$(SRC:.c=.o)

MAKELIB =       make -C ../lib

NAME	=	mysh

CFLAGS	=	-Wall -Wextra -W

all:	MAKEMAIN

MAKEMAIN:	$(OBJ)
	$(MAKELIB)
	gcc -o $(NAME) $(SRC) $(CFLAGS) -L. ../lib/libmy.a -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	$(MAKELIB) fclean
	rm -f $(NAME)

re: 	fclean all
