/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** move plane
*/

#include "my.h"
#include <stdlib.h>

int find_landing(plane_t **nod)
{
    if ((*nod)->way_x == 1 && (*nod)->way_y == 1)
        if ((*nod)->dep_x <= (*nod)->arr_x && (*nod)->dep_y <= (*nod)->arr_y)
            return (15);
    if ((*nod)->way_x == 1 && (*nod)->way_y == 0)
        if ((*nod)->dep_x <= (*nod)->arr_x && (*nod)->dep_y >= (*nod)->arr_y)
            return (15);
    if ((*nod)->way_x == 0 && (*nod)->way_y == 1)
        if ((*nod)->dep_x >= (*nod)->arr_x && (*nod)->dep_y <= (*nod)->arr_y)
            return (15);
    if ((*nod)->way_x == 0 && (*nod)->way_y == 0)
        if ((*nod)->dep_x >= (*nod)->arr_x && (*nod)->dep_y >= (*nod)->arr_y)
            return (15);
    return (0);
}

void move_plane(all_t *all, plane_t **node)
{
    (*node)->dep_x = ((*node)->speed_x * all->dt) + (*node)->dep_x;
    (*node)->dep_y = ((*node)->speed_y * all->dt) + (*node)->dep_y;
}

void del_plane2(plane_t **node, plane_t **prev_plane)
{
    (*prev_plane)->next = (*node)->next;
    free(*node);
    (*node) = (*prev_plane)->next;
}

void del_plane(plane_t **node, plane_t **plane_bu)
{
    *plane_bu = (*node)->next;
    free(*node);
    (*node) = *plane_bu;
}

void update_plane(all_t *all, plane_t **plane)
{
    plane_t *plane_bu = *plane;
    plane_t *prev_plane = NULL;
    for (int i = 0; *plane; i = 0) {
        move_plane(all, plane);
        int res = find_landing(plane);
        if ((res == 15 || (*plane)->destroy != 0) && prev_plane == NULL) {
            del_plane(plane, &plane_bu);
            i++;
        }
        if ((res == 15 || (*plane)->destroy != 0) && prev_plane != NULL) {
            del_plane2(plane, &prev_plane);
            i++;
        }
        if (i == 0) {
            prev_plane = *plane;
            *plane = (*plane)->next;
        }
    }
    *plane = plane_bu;
}
