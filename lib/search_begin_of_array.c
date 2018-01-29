/*
** EPITECH PROJECT, 2018
** lib
** File description:
** search_in_begin_of_array
*/

#include "../include/my.h"

int	search_in_begin_of_array(char *str, char *str2)
{
	int i = 0;

	for (i = 0; str[i]; i += 1) {
		if (str[i] != str2[i])
			return (0);
	}
	return (1);
}
