/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 * This file is licensed under the MIT license.
 * See the LICENSE file.
 */

#include <stdio.h>

int power_of_two(unsigned int a)
{
	if (a < 2) {
		return 0;
	}
	return (a & (a - 1)) == 0;
}

int main(int argc, char *argv[])
{
	printf("1 power of two: %d\n", power_of_two(1));
	printf("8 power of two: %d\n", power_of_two(8));
	printf("9 power of two: %d\n", power_of_two(9));
}

