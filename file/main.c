/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** main
*/

#include "my.h"

void helper(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr(" ./my_radar [OPTIONS] path_to_script\n");
    my_putstr(" path_to_script\tThe path to the script file.\n\n");
    my_putstr("OPTIONS\n");
    my_putstr(" -h\t\tprint the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" ‘L’ key\tenable/disable hitboxes and areas.\n");
    my_putstr(" ‘S’ key\tenable/disable sprites.\n\n");
    my_putstr("When a plane is in a control tower zone the hitbox is green.\n");
    my_putstr("When a plane is not in control, and not close to another");
    my_putstr(" aircraft the hitbox is blue.\n");
    my_putstr("When a plane is not in control, and close to another");
    my_putstr(" aircraft the hitbox is orange.\n");
    my_putstr("When a plane is not in control, and really close to another");
    my_putstr(" aircraft the hitbox is red.\n");
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        my_putstr("./my_radar: bad arguments: ");
        my_put_nbr(argc - 1);
        my_putstr(" given but 1 is required\nRetry with -h\n");
        return (84);
    } else if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
        helper();
        return (0);
    } else {
        if (structure(argv[1]) == 84)
            return (84);
    }
    return (0);
}
