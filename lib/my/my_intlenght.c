/*
** EPITECH PROJECT, 2022
** intlenght
** File description:
** lenght of an int
*/

int my_intlenght(int value)
{
    int len = 1;
    for (; 9 < value; len++)
        value /= 10;
    return (len);
}
