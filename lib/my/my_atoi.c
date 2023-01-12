/*
** EPITECH PROJECT, 2022
** my_atoi
** File description:
** atoi
*/

#include "my.h"

int my_atoi(char const *str)
{
    int i;
    int nb = 0;
    int neg = 0;
    for (i = 0; str[i] == '-' || str[i] == '+'; i++)
        if (str[i] == '-')
            neg = -1;
    for (;str[i] >= 48 && str[i] <= 57; i++) {
        nb *= 10;
        nb += (str[i] - 48);
        if (nb * neg < -2147483647 || nb > 2147483647)
            return (0);
    }
    if (neg == -1)
        nb *= neg;
    return (nb);
}
