#!/usr/bin/python
# Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
# This file is licensed under the MIT license.
# See the LICENSE file.


def memoize(f):
    cache= {}
    def memf(*args, **kw):
        key = (args, tuple(sorted(kw.items())))
        if key not in cache:
            cache[key] = f(*args, **kw)
        return cache[key]
    return memf

# Equivalent to the memoize function.
class Memoize:
    def __init__(self, f):
        self.f = f
        self.cache = {}

    def __call__(self, *args, **kw):
        key = key = (args, tuple(sorted(kw.items())))
        if not key in self.cache:
            self.cache[key] = self.f(*args, **kw)
        return self.cache[key]


@memoize
def fib(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fib(n-2) + fib(n-1)

print(fib(10)) # => 55


from functools import wraps


def presence_of(*args, **kwargs):
    def wrap(func):
        @wraps(func)
        def inner(cls):
            for arg in args:
                if arg not in cls.data:
                    return 'Some parameters are missing'
            return func(cls)
        return inner
    return wrap


class Class(object):
    def __init__(self):
        self.data = []

    @presence_of('required')
    def thing(self):
        return 'Yeah!'

c = Class()
print(c.thing()) # => 'Some parameters are missing'
c.data = ['required']
print(c.thing()) # => 'Yeah!'
