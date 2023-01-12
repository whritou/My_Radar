/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** event
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdio.h>

void switch_hitbox(all_t *all)
{
    if (all->hitbox == 0)
        all->hitbox = 1;
    else
        all->hitbox = 0;
}

void switch_sprite(all_t *all)
{
    if (all->sprite == 0)
        all->sprite = 1;
    else
        all->sprite = 0;
}

void event_check(all_t *all, sfEvent *event, plane_t *plane)
{
    if (all->time_current > all->max_time && !plane)
        sfRenderWindow_close(all->window);
    while (sfRenderWindow_pollEvent(all->window, event)) {
        if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
            sfRenderWindow_close(all->window);
        if (event->key.code == sfKeyL && all->switch_hitbox) {
            switch_hitbox(all);
            all->switch_hitbox = false;
        }
        if (event->key.code == sfKeyS && all->switch_sprite) {
            switch_sprite(all);
            all->switch_sprite = false;
        }
    }
}
