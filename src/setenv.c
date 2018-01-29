/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** my_setenv
*/

#include "../include/my.h"

char	**my_setenv(char **arg, char **env)
{
	int i = 0;

	if (my_tab_len(arg) > 3)
		return (env);
	if (arg[1] == NULL)
		return (my_env(arg, env));
	if (arg[1][0] < 'A'  || (arg[1][0] > 'Z' && arg[1][0] < 'a')
		|| arg[1][0] > 'z') {
		return (env);
	}
	for (i = 0; env[i] && search_in_begin_of_array
		(arg[1], env[i]) == 0; i += 1);
	if (env[i])
		change_env(arg[1], arg[2], env);
	else
		env = add_env(arg, env);
	return (env);
}
