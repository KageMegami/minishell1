/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** execute
*/

#include "../include/my.h"

char	**get_arg(char *buffer, alias_t *alias)
{
	char **arg = my_str_to_word_array(buffer, ' ', 0);

	arg = check_for_alias(arg, alias);
	return (arg);
}

void	check_return_signal(int lock)
{
	lock = WTERMSIG(lock);

	if (lock == 11)
		my_printf("Segmentation fault\n");
}

char	*get_path(char *bin, char **env)
{
	char *pathname = NULL;
	char *list_path = find_in_env(env, "PATH=", 0);
	char **tab_path = NULL;
	int i = -1;

	if (list_path == NULL)
		list_path =  emergency_path();
	tab_path = my_str_to_word_array(list_path, ':', 1);
	while (tab_path && tab_path[++i]) {
		pathname = my_strcat_slash(tab_path[i], bin);
		if (access(pathname, X_OK) == 0)
			break;
		free(pathname);
		pathname = NULL;
	}
	clear_tab(tab_path);
	free(list_path);
	if (access(bin, X_OK) == 0)
		pathname = my_strdup(bin);
	return (pathname);
}
void	execute_fonction(char *pathname, char **arg, char **env)
{
	int lock = 0;

	if (fork() == 0) {
		if (execve(pathname, arg, env) == -1)
			exit(0);
	}
	wait(&lock);
	free(pathname);
	check_return_signal(lock);
}

char	**execute(char *buffer, char **env, alias_t **alias)
{
	char *pathname = NULL;
	char **arg = get_arg(buffer, *alias);
	char **tmp = NULL;

	if (!arg || !arg[0])
		return (env);
	tmp = find_fonction_shell(arg, env, alias);
	if (tmp != NULL) {
		if (env != tmp)
			clear_tab(env);
		return (tmp);
	}
	pathname = get_path(arg[0], env);
	if (pathname == NULL) {
		my_printf("%s: Command not found.\n", arg[0]);
		return (env);
	}
	execute_fonction(pathname, arg, env);
	clear_tab(arg);
	return (env);
}
