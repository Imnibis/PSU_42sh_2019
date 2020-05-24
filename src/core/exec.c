/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec
*/

#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>

int exec(char *binary, char **argv, dictionary_t *env)
{
    int child;
    int exit_status;

    if ((child = fork())) {
        wait(&exit_status);
        return WEXITSTATUS(exit_status);
    } else {
        execve(binary, argv, env_to_array(env));
        return 0;
    }
}