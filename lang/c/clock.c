/*
 * Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
 * This file is licensed under the MIT license.
 * See the LICENSE file.
 */

/*
 * This file is not that interesting. It's more a rendition of a program
 * that I did in the EC1 course.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wait(int seconds)
{
	clock_t endwait;

	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait);
}

int main(int argc, char *argv[])
{
	int n, sec;
	char *a = "Aquest programa funciona";

	sec = (argc == 2) ? atoi(argv[1]) : 1;
	for (; *a; ++a) {
		wait(sec);
		printf("%c",*a);
		fflush(stdout);
	}
	printf("\n");
	return 0;
}
