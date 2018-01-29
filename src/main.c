/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** main
*/

#include "../include/my.h"

int	main(int ac, char **av, char **argenv)
{
	char *buffer = NULL;
	char **env = init_env(argenv);

	if (env == NULL)
		return (84);
	if (ac != 1) {
		my_printf("%s: No such file or directory.\n", av[1]);
		return (1);
	}
	while (1) {
		if (isatty(0))
			disp_prompt(env);
		buffer = get_next_line(0);
		if (buffer == NULL && isatty(0) == 0)
			return (0);
		if (buffer == NULL)
			my_exit(make_tab("0", NULL), env);
		env = execute(buffer, env);
		free(buffer);
	}
}
