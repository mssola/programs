/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 */

#include <stdio.h>

/*
 * Computing a**n with a divide and conquer algorithm.
 */
int power(unsigned int a, unsigned int n)
{
	if (n == 0) {
		return 1;
	}

	if ((n % 2) == 0) {
		return power(a*a, n/2);
	}
	return a * power(a*a, n/2);
}

int main(int argc, char *argv[])
{
	printf("%d\n", power(2, 4));
	printf("%d\n", power(2, 3));
	printf("%d\n", power(3, 3));
}

