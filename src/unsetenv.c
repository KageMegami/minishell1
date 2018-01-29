/*
** EPITECH PROJECT, 2018
** minshell1
** File description:
** unsetenv
*/

#include "../include/my.h"

int	test_for_multiple_delete(char *test, char **arg, int j)
{
	while (arg[++j]) {
		if (my_strcmp(test, arg[j]) == 0)
			return (1);
	}
	return (0);
}

int	get_nbr_of_delete(char **arg, char **env)
{
	int i = 0;
	int j = 1;
	int nbr = -1;

	for (; arg[j]; j +=1) {
		for (i = 0; env[i] && search_in_begin_of_array
			(arg[j], env[i]) == 0; i += 1);
		if (env[i] && test_for_multiple_delete(arg[j], arg, j) == 0)
			nbr += 1;
	}
	return (nbr);
}

char	**cp_tab_with_delete(int nbr, char **arg, char **env)
{
	char **tab = NULL;
	int i = -1;
	int j = 0;
	int a = -1;

	tab = malloc(sizeof(char*) * (my_tab_len(env) - nbr));
	while (env[++i]) {
		for (j = 0; arg[j] && search_in_begin_of_array
			(arg[j], env[i]) == 0; j += 1);
		if (arg[j])
			continue;
		tab[++a] = my_strdup(env[i]);
	}
	tab[++a] = NULL;
	return (tab);
}

char	**my_unsetenv(char **arg, char **env)
{
	int nbr = 0;
	char **tab = NULL;

	if (my_tab_len(arg) == 1) {
		my_printf("unsetenv: Too few arguments.\n");
		return (env);
	}
	nbr = get_nbr_of_delete(arg, env);
	if (nbr == -1)
		return (env);
	tab = cp_tab_with_delete(nbr, arg, env);
	return (tab);
}
