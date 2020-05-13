/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** cd.c
*/

#include "tools.h"
#include "linked.h"

int cdir(char *address_to_go, dictionary_t *env)
{
    char *old_dir = dict_get(env, "OLDPWD");

    if (chdir(address_to_go) != 0)
        perror("cd to ", address_to_go, "failed");
}