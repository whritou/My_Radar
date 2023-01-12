/*
** EPITECH PROJECT, 2022
** my_revstr.c
** File description:
** reverse string
*/

#include "my.h"
#include <stdlib.h>

char *my_revstr(char *src)
{
    int i;
    int size = my_strlen(src) - 1;
    char *dest = malloc(sizeof(char) * (size + 2));
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[size--];
    dest[i] = '\0';
    return (dest);
}
