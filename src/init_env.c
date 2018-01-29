/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** init_env
*/

#include "../include/my.h"

char    *emergency_path(void)
{
	return (my_strcat(my_strdup("PATH=/usr/local/sbin:/usr/local/bin"),
	my_strdup(":/usr/sbin:/usr/bin:/sbin:/bin")));
}

char	**emergency_env(void)
{
	char **env = malloc(sizeof(char*) * 3);

	env[0] = my_strcat("PWD=", getcwd(NULL, 512));
	env[1] = my_strcat(my_strdup("PATH=/usr/local/sbin:/usr/local/bin"),
	my_strdup(":/usr/sbin:/usr/bin:/sbin:/bin"));
	env[2] = NULL;
	return (env);
}

char	**init_env(char **argenv)
{
	char **env = NULL;
	int size = my_tab_len(argenv) + 1;
	int i = 0;

	if (!argenv || !argenv[0])
		return (emergency_env());
	if ((env = malloc(sizeof(char*) * size)) == NULL)
		return (NULL);
	for (i = 0; argenv[i]; i += 1) {
		env[i] = my_strdup(argenv[i]);
		if (!env[i])
			return (NULL);
	}
	env[i] = NULL;
	return (env);
}
