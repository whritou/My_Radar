/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** add_tower
*/

#include "my.h"
#include <math.h>
#include <stdlib.h>

void speed(plane_t *node, char **tab)
{
    float d_x = node->arr_x - node->dep_x;
    float d_y = node->arr_y - node->dep_y;
    node->angle = atan2(d_y, d_x) * 180 / M_PI;
    node->speed_y = (fabs(d_y / sqrt(pow(d_x, 2) + pow(d_y, 2))) *
    my_atoi(tab[5]));
    node->speed_x = (fabs(d_x / sqrt(pow(d_x, 2) + pow(d_y, 2))) *
    my_atoi(tab[5]));
    if (node->arr_x < node->dep_x) {
        node->way_x = 1;
        node->speed_x *= -1;
    }
    if (node->arr_y < node->dep_y) {
        node->way_y = 1;
        node->speed_y *= -1;
    }
}

void init_plane(plane_t **plane, char **tab)
{
    plane_t *node = NULL;
    node = malloc(sizeof(plane_t));
    node->dep_x = my_atoi(tab[1]) + 10;
    node->dep_y = my_atoi(tab[2]) + 10;
    node->arr_x = my_atoi(tab[3]) + 10;
    node->arr_y = my_atoi(tab[4]) + 10;
    node->dep_time = my_atoi(tab[6]);
    node->way_x = 0;
    node->way_y = 0;
    node->destroy = 0;
    node->colision = 0;
    node->close = 0;
    node->control = 0;
    speed(node, tab);
    node->next = NULL;
    node->next_out = NULL;
    if (*plane)
        node->next = *plane;
    *plane = node;
}

int add_plane(plane_t **plane, char *data, int time, int max_time)
{
    char **tab = my_str_to_word_array(data);
    int time_plane = my_atoi(tab[6]);
    if (max_time < time_plane)
        max_time = time_plane;
    if (time == time_plane)
        init_plane(plane, tab);
    free_all(tab);
    return (max_time);
}

void load_plane(plane_t **plane, char *path, int time, int max_time)
{
    FILE *file = fopen(path, "r");
    size_t size;
    char *data_2 = 0;
    char **data = get_data(path);
    for (int i = 0; getline(&data_2, &size, file) != -1; i++)
        if (data[i][0] == 'A')
            add_plane(plane, data[i], time, max_time);
    fclose(file);
    free(data_2);
    free_all(data);
}

void add_tower(tower_t **tower, char *data)
{
    tower_t *node = malloc(sizeof(tower_t));
    char **tab = my_str_to_word_array(data);
    node->x = my_atoi(tab[1]);
    node->y = my_atoi(tab[2]);
    node->radius = ((my_atoi(tab[3]) * 1920) / 100);
    node->next = NULL;
    if (*tower)
        node->next = *tower;
    *tower = node;
    free_all(tab);
}
