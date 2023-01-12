/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** copy string
*/

char *my_strcpy (char *dest, char const *src)
{
    int result;
    for (result = 0; src[result] != '\0'; result++)
        dest[result] = src[result];
    dest[result] = '\0';
    return (dest);
}
