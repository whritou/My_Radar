/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** display plane
*/

#include "my.h"
#include <SFML/Graphics.h>

void diplay_tower_suite(all_t *all, tower_t *node)
{
    if (all->sprite == 0) {
        node->position.x = node->x - 25;
        node->position.y = node->y - 25;
        sfSprite_setPosition(all->sprite_tower, node->position);
        sfRenderWindow_drawSprite(all->window, all->sprite_tower, NULL);
    }
}

void display_tower(all_t *all, tower_t *node)
{
    sfColor purple = {170, 0, 158, 255};
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setOutlineColor(circle, purple);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 1.5);
    while (node) {
        if (all->hitbox == 0) {
            node->position.x = node->x - node->radius;
            node->position.y = node->y - node->radius;
            sfCircleShape_setPosition(circle, node->position);
            sfCircleShape_setRadius(circle, node->radius);
            sfRenderWindow_drawCircleShape(all->window, circle, NULL);
        }
        diplay_tower_suite(all, node);
        node = node->next;
    }
    sfCircleShape_destroy(circle);
}
