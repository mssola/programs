/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 * This file is licensed under the MIT license.
 * See the LICENSE file.
 */

#include <stdio.h>

unsigned long hash(char *name)
{
	unsigned long h = 0, g;

	while (*name) {
		h = (h << 4) + *name++;
		g = h & 0xF0000000;
		if (g) {
			h ^= g >> 24;
		}
		h &= ~g;
	}
	return h;
}

int main(int argc, char *argv[])
{
	printf("%lu\n", hash("and"));
}
