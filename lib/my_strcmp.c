/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_strcmp
*/

#include "../include/my.h"

int     my_strcmp(char *s1, char *s2)
{
	int i = 0;

	if (my_strlen(s1) != my_strlen(s2))
		return (1);
	while (s1[i]) {
		if (s1[i] != s2[i])
			return (1);
		i += 1;
	}
	return (0);
}
