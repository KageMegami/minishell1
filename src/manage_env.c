/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** manage_env
*/

#include "../include/my.h"

char	**add_env(char **arg, char **env)
{
	char **tab = malloc(sizeof(char*) * (my_tab_len(env) + 2));
	char *tmp = NULL;
	int i = 0;

	if (!tab)
		return (NULL);
	for (; env[i]; i += 1)
		tab[i] = my_strdup(env[i]);
	tmp = my_strcat(arg[1], "=");
	if (!tmp)
		return (NULL);
	if (arg[2] == NULL)
		tab[i] = tmp;
	else {
		tab[i] = my_strcat(tmp, arg[2]);
		free(tmp);
	}
	tab[i + 1] = NULL;
	return (tab);
}

void	change_env(char *name, char *value, char **env)
{
	int i = 0;
	char *tmp = NULL;

	for (i = 0; env[i] && search_in_begin_of_array
		(name, env[i]) == 0; i += 1);
	if (!env[i])
		return;
	free(env[i]);
	tmp = my_strcat(name, "=");
	if (!tmp)
		return;
	if (value == NULL) {
		env[i] = tmp;
		return;
	}
	env[i] = my_strcat(tmp, value);
	free(tmp);
}

char	*find_in_env(char **env, char *name, int a)
{
	for (int i = 0; env[i]; i += 1) {
		if (search_in_begin_of_array(name, env[i])) {
			return (my_strdup(env[i] + my_strlen(name) + a));
		}
	}
	return (NULL);
}
