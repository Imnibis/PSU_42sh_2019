/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** pipe.c
*/

#include "shell.h"

int count_pipes(int argc, char **argv, dictionary_t *env)
{
    int pipes_number = 0;

    for(int i = 0; argv[i]; i++){
        if (!my_strcmp("|", argv[i]))
            pipes_number++;
    }
    return pipes_number;
}