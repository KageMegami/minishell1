/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** fonction_shell
*/

#include "../include/my.h"

fonction_t      *init_tab(void)
{
	fonction_t *tab = malloc(sizeof(fonction_t) * 7);

	tab[0].name = "cd";
	tab[0].fonction = &change_directory;
	tab[1].name = "setenv";
	tab[1].fonction = &my_setenv;
	tab[2].name = "unsetenv";
	tab[2].fonction = &my_unsetenv;
	tab[3].name = "env";
	tab[3].fonction = &my_env;
	tab[4].name = "setalias";
	tab[4].fonction = &my_setalias;
	tab[5].name = "unsetalias";
	tab[5].fonction = &my_unsetalias;
	tab[6].name = "alias";
	tab[6].fonction = &my_alias;
	return (tab);
}

char	**find_fonction_shell(char **arg, char **env, alias_t **alias)
{
	fonction_t *tab = init_tab();

	for (int i = 0; i < 7; i += 1) {
		if (my_strcmp(tab[i].name, arg[0]) == 0) {
			env = tab[i].fonction(arg, env, alias);
			free(tab);
			return (env);
		}
	}
	free(tab);
	if (my_strcmp("exit", arg[0]) == 0)
		my_exit(arg, env);
	return (NULL);
}
