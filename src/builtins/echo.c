/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** echo.c
*/

#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

char *str_delimit(char *str, int first)
{
    char d = '"';
    int p = 0;
    int i = first;
    char *new_str = malloc(sizeof(char) * my_strlen(str) - 2);

    while (str[i] != 0) {
        if (str[i] != d) {
            new_str[p] = str[i];
            p++;
        }
        i++;
    }
    new_str[p + 1] = 0;
    return new_str;
}

void my_putstrb(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if (str[i] == '\\' && str[i + 1] == 'n') {
            my_putchar('\n');
            i = i + 1;
        }
        else
            my_putchar(str[i]);
        i++;
    }
}

int builtin_echo(int argc, char **argv, dictionary_t **env)
{
    char *str = "";
    char arg = 'a';

    if (argc >= 3 && my_strlen(argv[2]) >= 2)
        arg = argv[2][1];
    if (argc >= 2)
        str = argc > 2 ? argv[2] : argv[1];
    str = str_delimit(str, 0);
    if (arg == 'n') {
        my_printf("%s", str);
    }
    else if (arg == 'e')
        my_putstrb(str);
    else
        my_putstr(str);
    return 0;
}