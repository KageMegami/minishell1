/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** bonus alias
*/

#include "../include/my.h"

char	**my_alias(char **arg, char **env, alias_t **alias)
{
	alias_t *tmp = *alias;

	while (tmp) {
		my_printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
	return (env);
}

char	**my_setalias(char **arg, char **env, alias_t **alias)
{
	alias_t *tmp = *alias;

	if (my_tab_len(arg) < 3)
		return (env);
	while (tmp && my_strcmp(tmp->name, arg[1]))
		tmp = tmp->next;
	if (tmp) {
		free(tmp->value);
		tmp->value = my_strdup(arg[2]);
	} else
		*alias = add_alias(*alias, arg[1], arg[2]);
    	return (env);
}

char	**my_unsetalias(char **arg, char **env, alias_t **alias)
{
	alias_t *tmp = *alias;
	alias_t *tmp2 = NULL;

	if (arg[1]) {
		if (tmp && my_strcmp(tmp->name, arg[1])== 0) {
			free(tmp->name);
			free(tmp->value);
			*alias = tmp->next;
			free(tmp);
			return (env);
		}
		while (tmp && my_strcmp(tmp->name, arg[1])) {
			tmp2 = tmp;
			tmp = tmp->next;
		}
		if (tmp)
			tmp2->next = tmp->next;
	}
	return (env);
}
