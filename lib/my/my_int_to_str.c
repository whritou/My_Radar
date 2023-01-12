/*
** EPITECH PROJECT, 2022
** my_int_to_str
** File description:
** int to char
*/

#include "my.h"
#include <stdlib.h>

char *my_int_to_str(int nb)
{
    int len = my_intlenght(nb) + 2;
    char *str = malloc(sizeof(char) * len);
    int i;
    if (nb == 0) {
        free(str);
        return ("0");
    }
    for (i = 0; nb != 0; i++) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}
