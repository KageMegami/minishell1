/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_strdup
*/

#include "../include/my.h"

char *my_strdup(char *str)
{
	char *cp = NULL;
	int i = 0;

	if (str == NULL)
		return (NULL);
	cp = malloc(sizeof(char) * (my_strlen(str) + 1));
	if (cp == NULL)
		return (NULL);
	for (i = 0; str[i]; i += 1)
		cp[i] = str[i];
	cp[i] = 0;
	return (cp);
}
