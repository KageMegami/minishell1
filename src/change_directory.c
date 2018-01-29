/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** change_directory
*/

#include "../include/my.h"

char	**make_tab(char *str1, char* str2)
{
	char **tab = malloc(sizeof(char*) * 4);

	tab[0] = my_strdup("setenv");
	tab[1] = my_strdup(str1);
	tab[2] = str2;
	tab[3] = NULL;
	return (tab);
}

char	**go_dest(char **env, char **arg, char **oldpwd)
{
	struct stat stat_file;
	char **tab = NULL;

	if (access(arg[1], F_OK) == -1 || lstat(arg[1], &stat_file) == -1) {
		my_printf("%s: No such file or directory.\n", arg[1]);
		return (env);
	}
	if ((stat_file.st_mode & S_IFMT) != S_IFDIR) {
		my_printf("%s: Is no a directory.\n", arg[1]);
		return (env);
	}
	free(*oldpwd);
	*oldpwd = getcwd(NULL, 512);
	chdir(arg[1]);
	tab = make_tab("PWD", getcwd(NULL, 512));
	env = my_setenv(tab, env);
	clear_tab(tab);
	return (env);
}

char	**go_back(char **env, char **oldpwd)
{
	char *tmp = *oldpwd;
	char **tab = NULL;

	if (*oldpwd[0] == 0) {
		my_putstr(": No such file or directory.\n");
		return (env);
	}
	*oldpwd = getcwd(NULL, 512);
	chdir(tmp);
	free(tmp);
	tab = make_tab("PWD", getcwd(NULL, 512));
	env = my_setenv(tab, env);
	clear_tab(tab);
	return (env);
}

char	**go_home(char **env, char **oldpwd)
{
	char *home = find_in_env(env, "HOME=", 0);
	struct stat stat_file;
	char **tab = NULL;

	if (home == NULL) {
		my_printf("cd: No home directory.\n");
		return (env);
	}
	if (access(home, F_OK) == -1 || lstat(home, &stat_file) == -1 ||
		(stat_file.st_mode & S_IFMT) != S_IFDIR) {
		my_printf("cd: Can't change to home directory.\n");
		return (env);
	}
	free(*oldpwd);
	*oldpwd = getcwd(NULL, 512);
	chdir(home);
	tab = make_tab("PWD", getcwd(NULL, 512));
	env = my_setenv(tab, env);
	clear_tab(tab);
	return (env);
}

char	**change_directory(char **arg, char **env)
{
	static char *oldpwd = NULL;

	if (!oldpwd) {
		oldpwd = malloc(1);
		oldpwd[0] = 0;
	}
	if (my_tab_len(arg) > 2) {
		my_printf("cd: Too many arguments.\n");
		return (env);
	}
	if (!arg[1] || my_strcmp(arg[1], "~") == 0 ||
		my_strcmp(arg[1], "--") == 0) {
		return (go_home(env, &oldpwd));
	}
	if (my_strcmp(arg[1], "-") == 0)
		return (go_back(env, &oldpwd));
	return (go_dest(env, arg, &oldpwd));
}
