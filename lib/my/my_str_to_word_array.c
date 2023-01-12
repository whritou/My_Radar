/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** compare string
*/

#include <stdlib.h>
#include "my.h"

char **my_str_to_word_array(char *str)
{
    int i = 0;
    int line = 0;
    int count = 1;
    char **tab = 0;
    for (int j = 0; str[j] != '\0'; j++)
        if ((str[j] != ' ' && str[j] != '\t') && (str[j + 1] == ' ' ||
        str[j + 1] == '\t' || str[j + 1] == '\0'))
            count++;
    tab = malloc(sizeof(char*) * (count + 1));
    for (int col = 0; str[i] != '\0'; line++) {
        tab[line] = malloc(sizeof(char) * (my_strlen(str) + 1));
        for (; str[i] == ' ' || str[i] == '\t'; i++, col = 0);
        for (; str[i] != '\0' && str[i] != ' ' && str[i] != '\t'; i++, col++)
            tab[line][col] = str[i];
        tab[line][col] = '\0';
    }
    tab[line] = NULL;
    return (tab);
}
