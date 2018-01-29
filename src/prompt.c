/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** prompt
*/

#include "../include/my.h"

void	disp_prompt(char **env)
{
	char *host = find_in_env(env, "HOST=", 0);
	char *home = find_in_env(env, "HOME=", 0);
	char *pwd = find_in_env(env, "PWD=", 0);
	int i = 0;

	if (!pwd)
		pwd = getcwd(NULL, 512);
	if (access(home, F_OK) == 0 && search_in_begin_of_array(home, pwd)) {
		i = my_strlen(home) - 1;
		pwd += i;
		pwd[0] = '~';
	}
	my_printf("%s:%s> ", host, pwd);
	pwd -= i;
	free(pwd);
	free(host);
	free(home);
	return;
}
