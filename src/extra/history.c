/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** history.c
*/

#include "shell.h"
#include <stdio.h>

int display_history(int argc, char **argv, dictionary_t **env)
{
    if(fopen(my_strconcat(dict_get(*env, "HOME"), "/.42sh_his"), "r") == NULL){
        perror("Display history");
        return 84;
    }
    my_printf(read_file(my_strconcat(dict_get(*env, "HOME"), "/.42sh_his")));
    return 0;
}