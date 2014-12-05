#!/usr/bin/python
# Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
# This file is licensed under the MIT license.
# See the LICENSE file.

def insertsort(lst):
    for i in range(1, len(lst)):
        value = lst[i]
        j = i
        while j > 0 and value < lst[j - 1]:
            lst[j] = lst[j - 1]
            j -= 1
        lst[j] = value


ary = [4, 65, 2, -31, 0, 99, 2, 83, 782, 1]
print(ary)

insertsort(ary)
print(ary)
