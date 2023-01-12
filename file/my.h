/*
** EPITECH PROJECT, 2022
** plib
** File description:
** lib
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdio.h>

int my_atoi(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
int my_putintstr (char c);
int my_put_nbr(int nb);
int my_intlenght(int value);
char **my_strdelim(char *str, int nb);
char **my_str_to_word_array(char *str);
char *my_int_to_str(int nb);
void free_all(char **tab);

typedef struct plane {
    float dep_x;
    float dep_y;
    int arr_x;
    int arr_y;
    float speed_x;
    float speed_y;
    float dep_time;
    float angle;
    int way_x;
    int way_y;
    int colision;
    int close;
    int control;
    sfVector2f position;
    int destroy;
    struct plane *next_out;
    struct plane *next;
} plane_t;

typedef struct tower {
    int x;
    int y;
    int radius;
    sfVector2f position;
    struct tower *next;
} tower_t;

typedef struct all{
    sfRenderWindow *window;
    sfVideoMode mode;
    sfText *text;
    sfFont *font;
    sfEvent *event;
    sfTexture *plane_texture;
    sfSprite *plane_sprite;
    sfTexture *texture_tower;
    sfSprite *sprite_tower;
    sfTexture *wallpaper_texture;
    sfSprite *wallpaper_sprite;
    sfClock *clock;
    sfTime time;
    sfClock *cl_plane;
    sfTime ti_plane;
    char *filepath;
    int hitbox;
    int sprite;
    bool switch_sprite;
    bool switch_hitbox;
    int time_current;
    int time_chrono;
    int minutes;
    int max_time;
    int seconds;
    sfTime dtime;
    float dt;
} all_t;

typedef struct plane_out {
    plane_t *node;
} plane_out_t;

char **get_data(char *str);

all_t *init_all(void);
void init_sprite(all_t *all);
void init_text(all_t *all);
void destroy_all(all_t *all, plane_out_t *plane);

void update_plane(all_t *all, plane_t **plane);
void load_plane(plane_t **plane, char *path, int time, int max_time);
int add_plane(plane_t **plane, char *data, int time, int max_time);
void add_tower(tower_t **tower, char *data);

void plane_action(plane_t *plane, plane_out_t *pla, tower_t *tower);
int plane_in_control(plane_t *plane, tower_t *tower);

void collision(plane_t *first, plane_t *second);

void display(all_t *all, plane_t *plane, tower_t *tower);
void display_plane(all_t *all, plane_t *plane);
void display_tower(all_t *all, tower_t *tower);
void event_check(all_t *all, sfEvent *event, plane_t *plane);
void time_set(all_t *all);

int structure(char *path);
void destroy(plane_t *plane, tower_t *tower);
int check_error_map(char *path);
void check_close(plane_t *plane);
