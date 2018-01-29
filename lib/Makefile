##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Basic Makfile
##

SRC	=	printf.c	\
		printf_fonction.c	\
		get_next_line.c	\
		my_tab_len.c	\
		my_strcat_slash.c	\
		my_strcat_space.c	\
		my_strdup.c	\
		my_str_to_word_array.c	\
		search_begin_of_array.c	\
		clear_tab.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_str_is_num.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wall -Wextra -W

all:	MAKEMAIN

MAKEMAIN:	$(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
