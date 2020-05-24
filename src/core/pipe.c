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

    UNUSED(env);
    UNUSED(argc);
    for(int i = 0; argv[i]; i++){
        if (!my_strcmp("|", argv[i]))
            pipes_number++;
    }
    return pipes_number;
}

int pipes(int argc, char **argv, dictionary_t *env)
{
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        perror("Pipe error");
        return 84;
    }
    return 0;
}