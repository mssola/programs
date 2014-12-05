/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 * This file is licensed under the MIT license.
 * See the LICENSE file.
 */

#include <stdio.h>

void insertsort(int *v, int size)
{
	int i, j, value;

	for (i = 0; i < size; i++) {
		value = v[i];
		for (j = i; j > 0 && value < v[j - 1]; j--) {
			v[j] = v[j - 1];
		}
		v[j] = value;
	}
}

int main(int argc, char *argv[])
{
	int i;
	int v[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
	int size = sizeof(v) / sizeof(v[0]);

	for (i = 0; i < size; i++) {
		printf("%i ", v[i]);
	}
	printf("\n");

	insertsort(v, size);

	for (i = 0; i < size; i++) {
		printf("%i ", v[i]);
	}
	printf("\n");
	return 0;
}
