/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int gt = 0;
    char *wec;
    wec = malloc(my_strlen(src));
    while (src[gt] != '\0') {
        wec[gt] = src[gt];
        gt++;
    }
    return (wec);
}
