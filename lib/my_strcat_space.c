/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_strcat_slash
*/

#include "../include/my.h"

char	*my_strcat_space(char *str1, char *str2)
{
	char *new = malloc(sizeof(char) *
	(my_strlen(str1) + my_strlen(str2) + 2));
	int i = -1;
	int j = -1;

	while (str1 && str1[++i])
		new[i] = str1[i];
	if (str1)
		new[i] = ' ';
	while (str2 && str2[++j])
		new[++i] = str2[j];
	new[++i] = 0;
	return (new);
}
