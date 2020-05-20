/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** parse
*/

#include "shell.h"
#include "string.h"
#include <stdlib.h>

linked_list_t *create_command_list(char *str)
{
    char *beginning = str;
    int i;
    linked_list_t *list = 0;
    char *which;

    if (!str) return 0;
    for (i = 0; str[i]; i++) {
        if (str[i] != ';' && !my_str_startswith(str + i, "&&") &&
            !my_str_startswith(str + i, "||")) continue;
        which = str[i] == ';' ? ";" : (my_str_startswith(str + i, "&&") ? "&&"
            : "||");
        str[i] = '\0';
        list = ll_append(list, my_strdup(beginning));
        list = ll_append(list, my_strdup(which));
        beginning = str + i + 1 + (which[0] != ';');
        if (which[0] != ';') i++;
    }
    if (beginning != str + i) list = ll_append(list, my_strdup(beginning));
    return list;
}

linked_list_t *create_word_list(char *str)
{
    char *beginning = str;
    int i;
    linked_list_t *list = 0;

    if (!str) return 0;
    for (i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') continue;
        if (beginning == str + i) {
            beginning = str + i + 1;
            continue;
        }
        str[i] = '\0';
        list = ll_append(list, beginning);
        beginning = str + i + 1;
    }
    if (beginning != str + i)
        list = ll_append(list, beginning);
    return list;
}

int parse_command(char *command, dictionary_t *env_vars, dictionary_t *builtins)
{
    linked_list_t *word_list = create_word_list(command);

    UNUSED(env_vars);
    UNUSED(builtins);
    command = word_list->data;
    word_list = word_list->next;
    my_printf("%s/", command);
    for (linked_list_t *i = word_list; i; i = i->next)
        my_printf("%s/", i->data);
    // TODO: exec program/builtin
    my_printf("\n");
    return 0;
}

int parse_input(char *command, dictionary_t *env_vars, dictionary_t *builtins)
{
    linked_list_t *command_list = create_command_list(command);
    int return_value = 0;
    int operator = OPERATOR_NONE;

    if (!command || !my_strcmp(command, "")) return 0;
    for (linked_list_t *i = command_list; i; i = i->next) {
        if (!my_strcmp(i->data, ";") || !my_strcmp(i->data, "&&") ||
            !my_strcmp(i->data, "||")) {
            operator = !my_strcmp(i->data, ";") ? OPERATOR_NEWLINE :
                (!my_strcmp(i->data, "&&") ? OPERATOR_AND : OPERATOR_OR);
            my_printf("%s\n", i->data);
            continue;
        }
        if (operator == OPERATOR_NONE || operator == OPERATOR_NEWLINE ||
            (operator == OPERATOR_AND && return_value) ||
            (operator == OPERATOR_OR && !return_value)) {
            return_value = parse_command(i->data, env_vars, builtins);
        }
    }
    ll_free(command_list, free);
    return return_value;
}