/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** header
*/

#ifndef MY_H_
#define MY_H_

#include "printf.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct fonction_s
{
	char *name;
	char ** (*fonction)(char **arg, char **env);
} fonction_t;

char	*emergency_path(void);
char	**make_tab(char *str1, char *str2);
int	my_str_is_num(char *str);
char	**my_exit(char **arg, char **env);
char	**change_directory(char **arg, char **env);
char	**my_unsetenv(char **arg, char **env);
char	**find_fonction_shell(char **arg, char **env);
char	**my_setenv(char **arg, char **env);
char	**my_env(char **arg, char **env);
int	my_strcmp(char *s1, char *s2);
void	change_env(char *name, char *value, char **env);
char	**add_env(char **env, char **arg);
void	disp_prompt(char **env);
void	clear_tab(char **tab);
char	**my_str_to_word_array(char *str, char c, int opt);
char	**execute(char *buffer, char **env);
char	*get_next_line(int fd);
int	my_tab_len(char **tab);
char	**init_env(char **argenv);
char	*my_strdup(char *str);
char	*find_in_env(char **env, char *name, int a);
int	search_in_begin_of_array(char *str, char *str2);
char	*my_strcat_slash(char *str1, char *str2);
char	*my_strcat(char *str1, char *str2);

#endif /* MY_H_ */
