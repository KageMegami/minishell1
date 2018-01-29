/*
** EPITECH PROJECT, 2018
** printf
** File description:
** print fonction
*/

#include "../include/printf.h"

int     my_strlen(char *str)
{
	int i = 0;

	for (; str && str[i]; i += 1);
	return (i);
}

void	my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_put_nbr(int nb)
{
	char c = 0;

	if (nb == -2147483648) {
		my_putstr("-2147483648");
		return;
	}
	if (nb < 0) {
		my_putchar('-');
		nb *= -1;
	}
	c = nb % 10 + 48;
	nb /= 10;
	if (nb != 0)
		my_put_nbr(nb);
	my_putchar(c);
}
