/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** cd.c
*/

#include "tools.h"
#include "linked.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int cdir(char *address_to_go, dictionary_t *env)
{
    char *old_dir = dict_get(env, "OLDPWD");

    if (my_strcmp(address_to_go, "-") == 0) {
        if (chdir(old_dir) != 0) {
            perror("cd");
            return errno;
        }
        return 0;
    } else if (my_strcmp(address_to_go, "~") == 0) {
        if (chdir(dict_get(env, "HOME")) != 0) {
            perror("cd");
            return errno;
        }
        return 0;
    }
    if (chdir(address_to_go) != 0) {
        perror("cd");
        return errno;
    }
    return 0;
}