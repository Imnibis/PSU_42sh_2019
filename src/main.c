/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "tools.h"
#include "linked.h"

int main(void)
{
    dictionary_t *env = 0;
    char *command_line;
    int var = 1;

    while (var == 1) {
        display_prompt(env);
        command_line = get_command_line(env);
        parse_input(command_line);
    }
    return 0;
}