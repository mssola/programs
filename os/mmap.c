/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 * This file is licensed under the MIT license.
 * See the LICENSE file.
 */

#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;
	char *file;

	if ((fd = open("mmap.c", O_RDWR, 0)) < 0) {
		err(1, "open");
	}


	// This will map this file into memory. We don't share it and it's
	// write-protected, so any modifications by other processes will not affect
	// the contents of this file. In this example the child process will append
	// a string to the original contents, but this modification won't be
	// performed into the original file. Therefore, the child and the parent
	// processes will print different things. This whole thing changes if we
	// would've passed MAP_SHARED instead of MAP_PRIVATE. In this case the
	// child process would efectively changed this file.
	file = (char *) mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
	if (file == MAP_FAILED) {
		err(1, "map");
	}

	switch (fork()) {
	case -1:
		err(1, "fork");
	case 0:
		strcat(file, "!!!MODIFIED!!!\n");
		printf("Child says!\n%s", file);
		munmap(file, 4096);
		return (EXIT_SUCCESS);
	}
	printf("Parent says!\n%s", file);
	munmap(file, 4096);
	close(fd);
	return (EXIT_SUCCESS);
}
