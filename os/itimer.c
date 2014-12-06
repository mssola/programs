/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 * This file is licensed under the MIT license.
 * See the LICENSE file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <sys/time.h>

// The same example as the one in `signal.c`, but we're using the setitimer
// system call this time instead of alarm.

void handler(int s)
{
	if (s != SIGALRM) {
		printf("Received unhandled signal %d\n", s);
		exit(1);
	}

	printf("Alarm!\n");
	signal(SIGALRM, handler);
}

int main(int argc, char *argv[])
{
	// With this configuration, we aim to fire up the SIGALRM signal twice per
	// second.
	struct itimerval t;
	t.it_interval.tv_sec = 0;
	t.it_interval.tv_usec = 500000;
	t.it_value.tv_sec = 0;
	t.it_value.tv_usec = 500000;

	signal(SIGALRM, handler);
	setitimer(ITIMER_REAL, &t, NULL);

	for (;;) {
	}
}

