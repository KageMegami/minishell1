/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** fonction_shell
*/

#include "../include/my.h"

fonction_t      *init_tab(void)
{
	fonction_t *tab = malloc(sizeof(fonction_t) * 4);

	tab[0].name = "cd";
	tab[0].fonction = &change_directory;
	tab[1].name = "setenv";
	tab[1].fonction = &my_setenv;
	tab[2].name = "unsetenv";
	tab[2].fonction = &my_unsetenv;
	tab[3].name = "env";
	tab[3].fonction = &my_env;
	return (tab);
}

char	**find_fonction_shell(char **arg, char **env)
{
	fonction_t *tab = init_tab();

	for (int i = 0; i < 4; i += 1) {
		if (my_strcmp(tab[i].name, arg[0]) == 0) {
			env = tab[i].fonction(arg, env);
			free(tab);
			return (env);
		}
	}
	free(tab);
	if (my_strcmp("exit", arg[0]) == 0)
		my_exit(arg, env);
	return (NULL);
}
