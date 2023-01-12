/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** alloc_destroy
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void destroy_all(all_t *all, plane_out_t *plane)
{
    sfClock_destroy(all->clock);
    sfClock_destroy(all->cl_plane);
    sfText_destroy(all->text);
    sfFont_destroy(all->font);
    sfTexture_destroy(all->texture_tower);
    sfTexture_destroy(all->plane_texture);
    sfTexture_destroy(all->wallpaper_texture);
    sfSprite_destroy(all->plane_sprite);
    sfSprite_destroy(all->sprite_tower);
    sfSprite_destroy(all->wallpaper_sprite);
    sfRenderWindow_destroy(all->window);
    free(plane);
    free(all);
}

void create_window(all_t *all)
{
    all->window = NULL;
    all->mode.width = 1920;
    all->mode.height = 1080;
    all->mode.bitsPerPixel = 32;
    sfContextSettings settings = {0, 0, 8, 0, 0, 0, 0};
    all->window = sfRenderWindow_create(all->mode, "My_Radar",
    sfClose, &settings);
    sfRenderWindow_setFramerateLimit(all->window, 60);
    sfRenderWindow_setIcon(all->window, 512, 512,
    sfImage_getPixelsPtr(sfImage_createFromFile("doc/radar.png")));
}

void init_text(all_t *all)
{
    all->text = sfText_create();
    all->font = sfFont_createFromFile("doc/DS-DIGII.TTF");
    sfText_setColor(all->text, sfGreen);
    sfText_setCharacterSize(all->text, 100);
    sfText_setFont(all->text, all->font);
    sfVector2f position = {1650, 10};
    sfText_setPosition(all->text, position);
}

void init_sprite(all_t *all)
{
    all->sprite = 0;
    all->hitbox = 0;
    all->switch_hitbox = true;
    all->switch_sprite = true;
    all->time_current = 0;
    all->time_chrono = 0;
    all->minutes = 0;
    all->seconds = 1000000;
    all->plane_texture = sfTexture_createFromFile("doc/plane.png", NULL);
    all->plane_sprite = sfSprite_create();
    sfSprite_setTexture(all->plane_sprite, all->plane_texture, sfTrue);
    all->wallpaper_texture = sfTexture_createFromFile("doc/map.jpg", NULL);
    all->wallpaper_sprite = sfSprite_create();
    sfSprite_setTexture(all->wallpaper_sprite, all->wallpaper_texture, sfTrue);
    all->texture_tower = sfTexture_createFromFile("doc/tower.png", NULL);
    all->sprite_tower = sfSprite_create();
    sfSprite_setTexture(all->sprite_tower, all->texture_tower, sfTrue);
}

all_t *init_all(void)
{
    all_t *all = malloc(sizeof(all_t));
    all->event = malloc(sizeof(sfEvent));
    all->clock = sfClock_create();
    all->time.microseconds = 0;
    all->cl_plane = sfClock_create();
    all->ti_plane.microseconds = 0;
    create_window(all);
    init_sprite(all);
    init_text(all);
    return (all);
}
