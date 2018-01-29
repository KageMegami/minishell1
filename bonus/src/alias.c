/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** bonus alias
*/

#include "../include/my.h"

char	**check_for_alias(char **arg, alias_t *alias)
{
	int i = 0;
	alias_t *tmp = alias;
	char *buffer = NULL;

	for (i = 0; arg[i]; i += 1) {
		while (alias && my_strcmp(arg[0], "setalias") == 1
			&& my_strcmp(arg[0], "unsetalias") == 1) {
			arg[i] = my_strcmp(arg[i], alias->name) == 0 ?
			my_strdup(alias->value) : arg[i];
			alias = alias->next;
		}
		alias = tmp;
	}
	for (i = 0; arg[i]; i += 1)
		buffer = my_strcat_space(buffer, arg[i]);
	clear_tab(arg);
	return (my_str_to_word_array(buffer, ' ', 1));
}

alias_t	*add_alias(alias_t *alias, char *name, char *value)
{
	alias_t *new = malloc(sizeof(alias_t));

	if (new == NULL)
		return (alias);
	new->name = name;
	new->value = value;
	new->next = alias;
	return (new);
}

char	**test_line(char *line)
{
	int i = -1;
	char **tab = malloc(sizeof(char*) * 2);

	if (search_in_begin_of_array("alias ", line) == 0)
		return (NULL);
	line += 6;
	while (line[++i] && line[i] != '=');
	tab[0] = malloc(sizeof(char) * i);
	i = -1;
	while (line[++i] && line[i] != '=')
		tab[0][i] = line[i];
	tab[0][i] = 0;
	line += i + 1;
	i = -1;
	while (line[++i]);
	tab[1] = malloc(sizeof(char) * i);
	i = -1;
	while (line[++i])
		tab[1][i] = line[i];
	tab[1][i] = 0;
	return (tab);
}

alias_t	*get_alias(void)
{
	alias_t *alias = NULL;
	char *line = NULL;
	int fd = open(".alias", O_RDONLY);
	char **tab = NULL;

	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line) {
		if ((tab = test_line(line)) != NULL) {
			alias = add_alias(alias, tab[0], tab[1]);
			free(tab);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	get_next_line(-1);
	return (alias);
}
