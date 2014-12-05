/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 * This file is licensed under the MIT license.
 * See the LICENSE file.
 */

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <unistd.h>

void handler(int s)
{
	switch (s) {
	case SIGUSR1:
		printf("SIGUSR1\n");
		break;
	case SIGALRM:
		printf("ALARM !!\n");
		return;
	}
	exit(0);
}

int main(int argc, char *argv[])
{
	printf("My PID: %i\n", getpid());

	signal(SIGALRM, handler);
	signal(SIGUSR1, handler);

	alarm(5);
	while (1) {
		pause();
	}
}
