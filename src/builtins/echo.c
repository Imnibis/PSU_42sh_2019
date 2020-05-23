/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** echo.c
*/

#include "shell.h"

int builtin_echo(int argc, char **argv)
{
    int i = 1;

    if (argc <= 1) {
        my_putstr("\n");
        return 0;
    }
    if (my_strcmp(argv[1], "-n") == 0)
        i = 2;
    for (i; i < argc; i++) {
        my_putstr(argv[i]);
        if (i < argc - 1) my_putstr(" ");
    }
    if (my_strcmp(argv[1], "-n") == 1) my_putstr("\n");
    return 0;
}