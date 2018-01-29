/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** exit
*/

#include "../include/my.h"

char	**my_exit(char **arg, char **env)
{
	int nbr = 0;
	int i = -1;

	if (my_tab_len(arg) > 2 || (arg[1] && my_str_is_num(arg[1]) == 0)) {
		my_printf("exit: Expression Syntax.\n");
		return (env);
	}
	if (arg[1]) {
		if (arg[1][0] == '-')
			i += 1;
		while (arg[1][++i])
			nbr = nbr * 10 + arg[1][i] - 48;
	}
	if (arg[1] && arg[1][0] == '-')
		nbr *= -1;
	clear_tab(arg);
	clear_tab(env);
	my_printf("exit\n");
	exit(nbr);
	return (NULL);
}
