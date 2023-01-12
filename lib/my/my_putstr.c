/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** dysplay one a one character
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (i);
}
