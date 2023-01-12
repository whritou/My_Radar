/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** game
*/

#include "my.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void game(all_t *all, plane_t **plane, tower_t *tower, char *path)
{
    plane_out_t *pla = malloc(sizeof(plane_out_t));
    pla->node = NULL;
    while (sfRenderWindow_isOpen(all->window)) {
        all->dtime = sfClock_restart(all->cl_plane);
        all->dt = sfTime_asSeconds(all->dtime);
        check_close(*plane);
        event_check(all, all->event, *plane);
        plane_action(*plane, pla, tower);
        if (all->time.microseconds >= all->seconds)
            load_plane(plane, path, all->time_current, 0);
        update_plane(all, plane);
        display(all, *plane, tower);
    }
    destroy_all(all, pla);
    destroy(*plane, tower);
}

int structure(char *path)
{
    int max_time = 0;
    if (check_error_map(path) == 84) {
        my_putstr("Bad map, retry with a valid map, or with '-h'.\n");
        return (84);
    }
    plane_t *plane = NULL;
    tower_t *tower = NULL;
    char **data = get_data(path);
    for (int i = 0; data[i]; i++) {
        if (data[i][0] == 'T')
            add_tower(&tower, data[i]);
        if (data[i][0] == 'A')
            max_time = add_plane(&plane, data[i], 0, max_time);
    }
    free_all(data);
    all_t *all = init_all();
    all->max_time = max_time;
    game(all, &plane, tower, path);
    return (0);
}
