/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** redirection
*/

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *find_file(char *str)
{
    int i = 0;
    char *file = malloc(sizeof(char) * my_strlen(str));

    while (str[i] != '>') 
        i++;
    i++;
    while (str[i] == ' ')
        i++;
    for (int p = 0; str[i]; i++, p++)
        file[p] = str[i];
    return file;
}

int find_arg(char *cmd_line)
{
    int i = 0;

    while (cmd_line[i] != '>')
        i++;
    return i;
}

int parcour_str(char *str)
{
    int i = find_arg(str);
    char *file = find_file(str);
    int fd = 0;

    if (str[i] == '>') {
        fd = open(file , O_CREAT | O_WRONLY | O_TRUNC, 0664);
        dup2(fd, 1);
    }
    if (str[i] == '>' && str[i + 1] == '>') {
        fd = open(file , O_CREAT | O_WRONLY | O_TRUNC, 0664);
        dup2(fd, 1);
    }
    if (fd < 0) 
        return (-1);
}

int write_file(char *str, char *file_name)
{
    int fd = open(file_name, O_RDWR|O_CREAT|O_TRUNC, S_IRWXU);

    dup2(fd, 1);
    printf("%s", str);
    close(fd);
    return 0;
}

int add_to_file(char *str, char *file_name)
{
    int fd = open(file_name, O_RDWR|O_CREAT|O_TRUNC, S_IRWXU);
    
    dup2(fd, 0);
    fprintf("%s", str);
    close(fd);
    return(0);
}