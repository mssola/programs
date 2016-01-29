/*
 * Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
 * This file is licensed under the MIT license.
 * See the LICENSE file.
 */

#include <stdio.h>
#include <string.h>
#include <transport.h>

int main(int argc, char *argv[])
{
	struct sockaddr_in server, client;
	char request[SIZE], reply[SIZE];
	int fd, n, length;

	/* Create the local socket. */
	if ((fd = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("Could not open socket.");
	}

	/* Bind local address. */
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(UDP_PORT);
	if (bind(fd, (SA) &server, sizeof(server)) < 0) {
		perror("Bind error.");
	}

	/* Listen. */
	for (;;) {
		/*
		 * Tell the kernel that we're listening for an UDP datagram. At this
		 * point the kernel will put this process to sleep. When the kernel
		 * detects an incoming datagram for this process, it will wake it.
		 */
		length = sizeof(client);
		if ((n = recvfrom(fd, request, SIZE, 0, (SA) &client, (socklen_t *) &length)) < 0) {
			perror("Error on recvfrom.");
		}

		/* Process the request... */
		printf("Received: %s, Length: %i\n", request, length);
		strcat(reply, "Hi there, dear client!");

		/* Finally send the processed reply to the same socket. */
		if (sendto(fd, reply, SIZE, 0, (SA) &client, sizeof(client)) != SIZE) {
			perror("Error on sento.");
		}
	}
	return 0;
}
