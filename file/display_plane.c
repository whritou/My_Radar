/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** display plane
*/

#include "my.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

void hitbox_plane(plane_t *node, sfRectangleShape *rect)
{
    sfVector2f size = {20, 20};
    sfColor orange = {255, 167, 26, 255};
    sfVector2f ori = {10.0, 10.0};
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, node->position);
    sfRectangleShape_setOutlineColor(rect, sfCyan);
    sfRectangleShape_setOrigin(rect, ori);
    sfRectangleShape_setRotation(rect, node->angle);
    if (node->close == 1)
        sfRectangleShape_setOutlineColor(rect, orange);
    if (node->colision == 1)
        sfRectangleShape_setOutlineColor(rect, sfRed);
    if (node->control == 1)
        sfRectangleShape_setOutlineColor(rect, sfGreen);
}

void rotate_plane(all_t *all, plane_t *node)
{
    node->position.x = node->dep_x - 10;
    node->position.y = node->dep_y - 10;
    sfSprite_setPosition(all->plane_sprite, node->position);
    sfVector2f ori = {10.0, 10.0};
    sfSprite_setOrigin(all->plane_sprite, ori);
    sfSprite_setRotation(all->plane_sprite, node->angle);
    sfRenderWindow_drawSprite(all->window, all->plane_sprite, NULL);
}

void display_plane(all_t *all, plane_t *node)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    while (node) {
        if (all->sprite == 0)
            rotate_plane(all, node);
        if (all->hitbox == 0) {
            node->position.x = node->dep_x - 10;
            node->position.y = node->dep_y - 10;
            hitbox_plane(node, rect);
            sfRenderWindow_drawRectangleShape(all->window, rect, NULL);
        }
        node->next_out = NULL;
        node = node->next;
    }
    sfRectangleShape_destroy(rect);
}

void display(all_t *all, plane_t *plane, tower_t *tower)
{
    sfRenderWindow_drawSprite(all->window, all->wallpaper_sprite, NULL);
    display_tower(all, tower);
    display_plane(all, plane);
    time_set(all);
    sfRenderWindow_display(all->window);
}
