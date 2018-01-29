/*
** EPITECH PROJECT, 2018
** lib
** File description:
** str is num
*/

int	my_str_is_num(char *str)
{
	int i = -1;

	if (str[0] == '-')
		i += 1;
	while (str && str[++i]) {
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
