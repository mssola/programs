/*
 * Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
 * This file is licensed under the MIT license.
 * See the LICENSE file.
 */

#include <stdio.h>

void heapify(int *heap, int start, int end)
{
	int last = ((end + 1) >> 1);
	int lson, rson, largest, tmp;

	while (start < last) {
		lson = (start << 1) + 1;
		rson = lson + 1;

		if (rson <= end) {
			largest = (heap[lson] < heap[rson]) ? rson : lson;
		} else {
			largest = lson;
		}

		if (heap[largest] > heap[start]) {
			tmp = heap[start];
			heap[start] = heap[largest];
			heap[largest] = tmp;
			start = largest;
		} else {
			break;
		}
	}
}

void heapsort(int *heap, int n)
{
	int i, tmp;

	// First step: build the heap.
	for (i= (n - 1)/2; i >= 0; i--)
		heapify(heap, i, n - 1);

	// Second step: remove, insert and reconstruct.
	for (i = n - 1; i > 0; i--) {
		tmp = heap[0];
		heap[0] = heap[i];
		heap[i] = tmp;
		heapify(heap, 0, i - 1);
	}
}

int main(int argc, char *argv[])
{
	int v[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
	int i, size = sizeof(v) / sizeof(v[0]);

	heapsort(v, size);

	for (i = 0; i < size; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}
