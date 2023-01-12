/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** print one character
*/

#include <unistd.h>

int my_putintstr(char c)
{
    write(1, &c, 1);
    return (1);
}
