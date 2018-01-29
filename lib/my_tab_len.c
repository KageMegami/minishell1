/*
** EPITECH PROJECT, 2018
** lib
** File description:
** my_tab_len
*/

int	my_tab_len(char **tab)
{
	int i = 0;

	for (; tab && tab[i]; i += 1);
	return (i);
}
