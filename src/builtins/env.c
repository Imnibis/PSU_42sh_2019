/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** env.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "tools.h"

char *get_name(char *arg)
{
    int i = 0;
    int p = 0;
    char *name;

    while (arg[i] != ' ')
        i++;
    name = malloc(sizeof(char) * i);
    while (p != i) {
        name[p] = arg[p];
        p++;
    }
    name[p] = '\0';
    return name;
}

char *get_value(char *arg)
{
    int i = 0;
    int p = 0;
    char *value;

    while (arg[i] != '=')
        i++;
    while (arg[i] == ' ' || arg[i] == '=')
        i++;
    value = malloc(sizeof(char) * my_strlen(arg) - i);
    while (arg[i]) {
        value[p] = arg[i];
        p++;
        i++;
    }
    value[p + 1] = 0;
    return value;
}

int sset_env(char *arg)
{
    char *name = get_name(arg);
    char *value = get_value(arg);

    if (setenv(name, value, 0) == -1) {
        my_putstr("Error, no enought argument");
        return 84;
    }
    else
        return 0;
}

int unset_env(char *name)
{
    if (unsetenv(name) == 0) {
        my_putstr("succes\n");
        return 0;
    }
    else {
        return 84;
    }
}
