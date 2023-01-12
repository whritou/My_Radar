/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** error
*/

#include "my.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

char **get_data(char *str)
{
    int line = 1;
    int size = 1;
    struct stat *st = malloc(sizeof(struct stat));
    stat(str, st);
    char *buffer = malloc(sizeof(char) * st->st_size + 1);
    int folder = open(str, O_RDONLY);
    size = read(folder, buffer, st->st_size);
    buffer[size] = '\0';
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            line++;
    char **map = my_strdelim(buffer, line);
    close(folder);
    free(buffer);
    free(st);
    return (map);
}

int check_arguments(char *str)
{
    int i = 1;
    int j = 0;
    if (str[i] == '-')
        i++;
    for (; str[i] != '\0'; i++) {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' ||
        str[i] == '\t')
            j = 1;
        else {
            j = 0;
            return (j);
        }
    }
    return (j);
}

int size_a_t(char *str)
{
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] != ' ' && str[i] != '\t') && (str[i + 1] == ' ' ||
        str[i + 1] == '\t' || str[i + 1] == '\0'))
            size++;
    }
    return (size);
}

int check_size(char *str, int type)
{
    if (type == 0) {
        int a_size = size_a_t(str);
        if (a_size != 7)
            return (84);
        if (check_arguments(str) == 0)
            return (84);
    }
    if (type == 1) {
        int t_size = size_a_t(str);
        if (t_size != 4)
            return (84);
        if (check_arguments(str) == 0)
            return (84);
    }
    return (0);
}

int check_error_map(char *path)
{
    if (open(path, O_RDONLY) == -1)
        return (84);
    char **data = get_data(path);
    for (int i = 0; data[i]; i++) {
        if (data[i][0] != 'A' && data[i][0] != 'T' && data[i][0] != '\0' &&
        data[i][0] != '\n' && data[i][0] != '\t') {
            free(data);
            return (84);
        }
        if (data[i][0] == 'A' && check_size(data[i], 0) == 84) {
            free(data);
            return (84);
        }
        if (data[i][0] == 'T' && check_size(data[i], 1) == 84) {
            free(data);
            return (84);
        }
    }
    free_all(data);
    return (0);
}
