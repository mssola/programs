#!/usr/bin/python
# Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
# This file is licensed under the MIT license.
# See the LICENSE file.

def partition(ary, left, right):
    pivot = ary[left]
    store = left

    ary[left], ary[right] = ary[right], ary[left]
    for i in range(left, right):
        if ary[i] < pivot:
            ary[i], ary[store] = ary[store], ary[i]
            store = store + 1
    ary[store], ary[right] = ary[right], ary[store]
    return store


def quicksort(ary, left, right):
    if left < right:
        pivot = partition(ary, left, right)
        quicksort(ary, left, pivot - 1)
        quicksort(ary, pivot + 1, right)


ary = [4, 65, 2, -31, 0, 99, 2, 83, 782, 1]
print(ary)

quicksort(ary, 0, len(ary) - 1)
print(ary)
