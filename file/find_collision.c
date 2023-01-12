/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** destroy
*/

#include "my.h"
#include <math.h>

int plane_in_control(plane_t *plane, tower_t *tower)
{
    while (tower) {
        float x = plane->dep_x - (tower->x + 10);
        float y = plane->dep_y - (tower->y + 10);
        if (pow(x, 2) + pow(y, 2) <= pow(tower->radius,2)) {
            plane->control = 1;
            return (0);
        }
        tower = tower->next;
    }
    return (15);
}

void collision(plane_t *first, plane_t *second)
{
    float delta_x = fabs(first->dep_x - second->dep_x);
    float delta_y = fabs(first->dep_y - second->dep_y);
    sfVector2f delta = {delta_x, delta_y};

    if (delta.x <= 50 && delta.y <= 50) {
        first->close = 1;
        second->close = 1;
    }
    if (delta.x <= 25 && delta.y <= 25) {
        first->colision = 1;
        second->colision = 1;
    }
    if (delta.x <= 20 && delta.y <= 20) {
        first->destroy = 1;
        second->destroy = 1;
    }
}

void check_close(plane_t *plane)
{
    while (plane) {
        plane->colision = 0;
        plane->close = 0;
        plane->control = 0;
        plane = plane->next;
    }
}

void find_collision(plane_t *first, plane_t *second)
{
    while (first && second) {
        collision(first, second);
        second = second->next_out;
    }
}

void plane_action(plane_t *plane, plane_out_t *pla, tower_t *tower)
{
    while (plane) {
        if (plane_in_control(plane, tower) == 15) {
            plane->next_out = pla->node;
            pla->node = plane;
        }
        plane = plane->next;
    }
    while (pla->node) {
        while (pla->node->next_out) {
            find_collision(pla->node, pla->node->next_out);
            pla->node = pla->node->next_out;
        }
        pla->node = pla->node->next_out;
    }
}
