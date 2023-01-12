/*
** EPITECH PROJECT, 2022
** intlenght
** File description:
** lenght of an int
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int i = 0;
    if (nb >= 10) {
        i += my_put_nbr(nb / 10);
        i += my_putintstr(48 + nb % 10);
    } else
        i += my_putintstr(48 + nb);
    return (i);
}
