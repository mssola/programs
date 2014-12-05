#!/usr/bin/python
# Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
# This file is licensed under the MIT license.
# See the LICENSE file.

def merge(left, right):
    i, j = 0, 0
    result = []

    # Append items.
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    # Add remaining items and return.
    result.extend(left[i:])
    result.extend(right[j:])
    return result


def mergesort(ary):
    # Base case
    if len(ary) <= 1:
        return ary

    # Split
    mid = int(len(ary) / 2)
    left = mergesort(ary[:mid])
    right = mergesort(ary[mid:])

    # Return the merged array
    return merge(left, right)


ary = [4, 65, 2, -31, 0, 99, 2, 83, 782, 1]
print(ary)

ary = mergesort(ary)
print(ary)
