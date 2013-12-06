#!/usr/bin/python
#
# Copyright (C) 2013 Miquel Sabaté Solà <mikisabate@gmail.com>
#

import os


# The with statement automatically closes the file.
file = os.path.abspath(__file__)
with open(file, 'r') as f:
    print(f.read())


class Thing:
    def __enter__(self):
        print('Enter')
        return 0

    def __exit__(self, type, value, traceback):
        print('Exit')
        return 1

for i in range(2):
    with Thing():
        print('Inside')

