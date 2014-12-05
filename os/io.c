/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <err.h>
#include <unistd.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
    int count;
    int fd, fd1;
    char buffer[256];

    /*
     * Setting the umask value here. You can check the default value
     * at /etc/profile.
     */
    umask(0);

    /*
     * Opening this guys to do the reading & writing.
     */
    if ((fd = open("io.c", O_RDWR, 0)) < 0)
        err(1, "open");
    if ((fd1 = open("/tmp/thing.c", O_TRUNC | O_WRONLY | O_CREAT, 0666)) < 0)
        err(1, "open");

    /* Buffering: just doing a simple copy. */
    while ((count = read(fd, buffer, 256)) > 0)
        write(fd1, buffer, count);

    /* For some reason we want to print the first character of this file. */
    if (lseek(fd, 0, SEEK_SET) < 0)
        err(1, "lseek");
    if (read(fd, buffer, 1) != 1)
        err(1, "read");

    /* Let's use the dup syscall, just to show how it operates. */
    count = dup(1);
    sprintf(buffer, "The first character is: %c.\n", buffer[0]);
    write(count, buffer, strlen(buffer));

    /* Let's close everything and return a success status. */
    close(fd);
    close(fd1);
    close(count);
    return (EXIT_SUCCESS);
}
