/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** exec
*/

#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

volatile __sig_atomic_t interrupt = 0;

void signal_handler(int sig)
{
    interrupt = 1;
}

void check_signal(int child)
{
    if (interrupt) {
        kill(child, SIGINT);
        interrupt = 0;
    }
}

int wait_loop(int child)
{
    int exit_status;
    int is_alive;

    while (1) {
        is_alive = waitpid(child, &exit_status, WNOHANG);
        if (is_alive == 0) {
            check_signal(child);
        } else
            return WEXITSTATUS(exit_status);
    }
}

int exec(char *binary, char **argv, dictionary_t *env)
{
    int child;
    int return_value;
    struct sigaction sa;
    struct sigaction old_sa;

    sa.sa_handler = signal_handler;
    if ((child = fork())) {
        sigaction(SIGINT, &sa, &old_sa);
        return_value = wait_loop(child);
        sigaction(SIGINT, &old_sa, NULL);
    } else {
        execve(binary, argv, env_to_array(env));
        return 0;
    }
}