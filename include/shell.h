/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell
*/

#ifndef SHELL_H_
#define SHELL_H_
#include "linked.h"
#include "tools.h"

#define OPERATOR_NONE 0
#define OPERATOR_OR 1
#define OPERATOR_AND 2
#define OPERATOR_NEWLINE 3

typedef struct expression {
    char *command;
    int argc;
    char **argv;
} expression_t;

int parse_input(char *command);
dictionary_t *env_init(char **envp);
char *env_get(dictionary_t *env_vars, char *var);
dictionary_t *env_set(dictionary_t *env_vars, char *index, char *value);
dictionary_t *env_del(dictionary_t *env_vars, char *index);
char **env_to_array(dictionary_t *env_vars);

#endif /* !SHELL_H_ */