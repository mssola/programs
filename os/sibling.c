/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <err.h>


int main(int argc, char *argv[])
{
    pid_t pid1, pid2;
    int pd[2];

    pipe(pd);
    switch (pid1 = fork()) {
        case -1:
            err(1, "fork");
        case 0:
            if (read(pd[0], &pid2, sizeof(pid_t)) > 0) {
                printf("My sibling has the following PID: %d\n", pid2);
                exit(0);
            }
    }
    switch (pid2 = fork()) {
        case -1:
            err(1, "fork");
        case 0:
            pid2 = getpid();
            printf("I'm: %d. Let's send my PID through a pipe.\n", pid2);
            write(pd[1], &pid2, sizeof(pid_t));
    }
    return (EXIT_SUCCESS);
}