/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** cd.c
*/

int cdir(char *address)
{
    if (chdir(address) != 0)
        perror("cd to ", address, "failed");
}