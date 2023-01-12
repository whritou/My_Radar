/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** timer
*/

#include "my.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

char *time_suite(all_t *all, char *str)
{
    str[0] = '\0';
    if (all->minutes >= 60)
        all->minutes = 0;
    if (all->minutes < 10)
        my_strcat(str, "0");
    my_strcat(str, my_int_to_str(all->minutes));
    my_strcat(str, ":");
    if (all->time_chrono < 10)
        my_strcat(str, "0");
    my_strcat(str, my_int_to_str(all->time_chrono));
    return (str);
}

void time_set(all_t *all)
{
    char *string = malloc(sizeof(char) * 6);
    all->time = sfClock_getElapsedTime(all->clock);
    if (all->time.microseconds >= all->seconds) {
        sfClock_restart(all->clock);
        all->switch_hitbox = true;
        all->switch_sprite = true;
        all->time_current++;
        all->time_chrono++;
        if (all->time_chrono >= 60) {
            all->time_chrono = 0;
            all->minutes++;
        }
    }
    string = time_suite(all, string);
    sfText_setString(all->text, string);
    sfText_setOutlineColor(all->text, sfBlack);
    sfText_setOutlineThickness(all->text, 1);
    sfRenderWindow_drawText(all->window, all->text, NULL);
    free(string);
}
