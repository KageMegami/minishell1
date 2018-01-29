/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** my_env
*/

#include "../include/my.h"

char	**my_env(char **arg, char **env)
{
	if (my_tab_len(arg) != 1)
		return (env);
	for (int i = 0; env[i]; i += 1)
		my_printf("%s\n", env[i]);
	return (env);
}
