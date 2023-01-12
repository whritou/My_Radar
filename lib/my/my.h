/*
** EPITECH PROJECT, 2022
** plib
** File description:
** lib
*/

#pragma once

int my_atoi(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
int my_putintstr (char c);
int my_put_nbr(int nb);
int my_intlenght(int value);
char **my_str_delim(char *str, int nb);
char **my_str_to_word_array(char *str);
char *my_int_to_str(int nb);
void free_all(char **tab);
