/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** destroy all
*/

#include "my.h"
#include <stdlib.h>

void destroy(plane_t *plane, tower_t *tower)
{
    for (plane_t *del_plane = plane; plane; del_plane = plane) {
        plane = plane->next;
        free(del_plane);
    }
    for (tower_t *del_tower = tower; tower; del_tower = tower) {
        tower = tower->next;
        free(del_tower);
    }
}
