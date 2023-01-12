/*
** EPITECH PROJECT, 2022
** my_str_delim
** File description:
** strdelim
*/

#include <stdlib.h>
#include "my.h"

char **my_strdelim(char *str, int nb)
{
    int line = 0;
    int col = 0;
    int len = 0;
    char **tab = malloc(sizeof(char*) * (nb + 1));
    for (int i = 0; line < nb; line++, i++) {
        for (len = 0; str[len + i] != '\n' && str[len + i] != '\0'; len++);
        tab[line] = malloc(sizeof(char) * len + 1);
        for (col = 0; str[i] != '\0' && str[i] != '\n'; i++, col++)
            tab[line][col] = str[i];
        tab[line][col] = '\0';
    }
    tab[line] = NULL;
    return (tab);
}
