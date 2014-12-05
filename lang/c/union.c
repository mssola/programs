/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 */

#include <stdio.h>

union Thing {
	struct Bits {
		unsigned char first : 1;
		unsigned char second : 1;
		unsigned char third : 1;
		unsigned char fourth : 1;
		unsigned char fifth : 1;
		unsigned char sixth : 1;
		unsigned char seventh : 1;
		unsigned char eighth : 1;
	} bits;
	char byte;
};

void print_bin(unsigned int value)
{
	union Thing thing;

	thing.byte = value;
	printf("Original value: %i", value);
	printf(" Binary: %i%i%i%i%i%i%i%i\n", thing.bits.eighth, thing.bits.seventh,
			thing.bits.sixth, thing.bits.fifth, thing.bits.fourth,
			thing.bits.third, thing.bits.second, thing.bits.first);
}

int main()
{
	union Thing thing;

	print_bin(3);
	print_bin(5);
	print_bin(7);
	print_bin(8);
	print_bin(14);
}

