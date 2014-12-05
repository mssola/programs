/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 * This file is licensed under the MIT license.
 * See the LICENSE file.
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * This is an exercise from the book "The Linux Programming Interface".
 * It consists on creating a file in append mode and then try to see what
 * happens if we lseek back to another position and write to this file.
 *
 * This example will create a file if it doesn't exist. Opening a file
 * with O_APPEND mode has the side effect that the file offset will be changed
 * to the end * of the file before writing. This explains the following points:
 *
 *  1. The first lseek is useless. Even if we put the file offset to the
 *     beginning of the file, the following write call will put it back to
 *     the end of the file before doing the actual write.
 *  2. The first read will return 0 bytes. The file offset is at the end of
 *     the file because of the last call to write. Therefore, there's nothing
 *     to be read.
 *  3. The last read will perform as expected: it will read the contents that
 *     we've written to the file.
 */

int main(int argc, char *argv[])
{
	int fd, aux;
	char buffer[16];

	/* Let's write some data. */
	if ((fd = open("/tmp/file.txt", O_CREAT | O_APPEND | O_RDWR, 0777)) < 0) {
		perror("open");
	}
	write(fd, "Hello", 5);
	lseek(fd, 0, SEEK_SET);
	write(fd, " World", 6);

	/* Being naive. */
	aux = read(fd, buffer, 11);
	buffer[aux] = '\0';
	printf("String: %s\n", buffer);

	/* The proper way to read. */
	lseek(fd, 0, SEEK_SET);
	aux = read(fd, buffer, 11);
	buffer[aux] = '\0';
	printf("String: %s\n", buffer);

	close(fd);
	exit(EXIT_SUCCESS);
}
