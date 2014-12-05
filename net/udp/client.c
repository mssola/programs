/*
 * Copyright (C) 2013-2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 */

#include <stdio.h>
#include <string.h>
#include <transport.h>


int main(int argc, char *argv[])
{
    struct sockaddr_in server;
    char request[SIZE], reply[SIZE];
    int fd, n;

    /* Create the local socket. */
    if ((fd = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
        perror("Could not open socket.");

    /* Bind local address. */
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(UDP_PORT);

    /* Send a request to the server. */
    strcat(request, "Hello world!");
    if (sendto(fd, request, SIZE, 0, (SA) &server, sizeof(server)) != SIZE)
        perror("Error on sendto.");

    /*
     * At this point, the kernel will put to sleep this process. When the
     * reply has been received, the kernel will wake up this process again.
     */
    if ((n = recvfrom(fd, reply, SIZE, 0, (SA) NULL, (socklen_t *) NULL)) < 0)
        perror("Error on recvfrom.");

    /* Process the request... */
    printf("Reply: %s\n", reply);
    return 0;
}
