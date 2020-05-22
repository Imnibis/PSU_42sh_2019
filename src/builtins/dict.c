/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** dict
*/

#include "shell.h"

dictionary_t *builtin_init()
{
    dictionary_t *builtins = dict_add(0, "cd", cdir);

    builtins = dict_add(builtins, "echo", echo);
    builtins = dict_add(builtins, "echo", exit_shell);
    return builtins;
}