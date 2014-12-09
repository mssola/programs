/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 * This file is licensed under the MIT license.
 * See the LICENSE file.
 */

#include <stdio.h>

/**
 * Given a terrain, compute the maximum volume of water that would fit without
 * spilling.
 *
 * This is from a Twitter interview as explained here:
 * http://qandwhat.apps.runkite.com/i-failed-a-twitter-interview/
 */

int volume(int *land, int length)
{
	int l_max = 0, r_max = 0;
	int left = 0, volume = 0;
	int right = length - 1;

	while (left < right) {
		if (land[left] > l_max) {
			l_max = land[left];
		}
		if (land[right] > r_max) {
			r_max = land[right];
		}
		if (l_max >= r_max) {
			volume += r_max - land[right];
			right--;
		} else {
			volume += l_max - land[left];
			left++;
		}
	}
	return volume;
}

int main(int argc, char *argv[])
{
	int ary[] = {2, 5, 1, 2, 3, 4, 7, 7, 6};
	printf("%d\n", volume(ary, sizeof(ary) / sizeof(int)));
}

