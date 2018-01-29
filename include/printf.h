/*
** EPITECH PROJECT, 2018
** printf.h
** File description:
** header
*/

#ifndef PRINTF_H_
#define PRINTF_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	my_strlen(char *str);
void	my_putstr(char *str);
void	my_putchar(char c);
void	my_put_nbr(int nb);
void	my_printf(char *str, ...);

#endif /* PRINTF_H__ */
