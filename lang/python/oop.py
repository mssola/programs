#!/usr/bin/python
#
# Copyright (C) 2013 Miquel Sabaté Solà <mikisabate@gmail.com>
#


##
# Basic OOP.

class Class(object):
    def __init__(self):
        pass

    def foo(self):
        print('foo!')

    def asd(self):
        print('asd')

class SubClass(Class):
    def foo(self):
        print('subclassed foo')


SubClass().foo() # => subclassed foo
SubClass().asd() # => asd


##
# Iterators.

class Fib(object):
    def __init__(self, max):
        self.max = max

    def __iter__(self):
        self.a = 0
        self.b = 1
        return self

    def __next__(self):
        fib = self.a
        if fib > self.max:
            raise StopIteration
        self.a, self.b = self.b, self.a + self.b
        return fib

for i in Fib(1000):
    print(i, end=' ')
print('')


##
# Same as above but with plain generators.

def fib(n):
    a, b = 0, 1
    while a < n:
        yield a
        a, b = b, a + b

for i in fib(1000):
    print(i, end=' ')
print('')


##
# Exceptions.

class MyException(Exception):
    def __init__(self, msg):
        self.msg = msg

    def __str__(self):
        return 'My exception: {0}'.format(self.msg)

try:
    raise MyException('lala')
except (ZeroDivisionError, TypeError, MyException) as e:
    print('Fucked: {0}'.format(e))
else:
    print('Another exception')
finally:
    print('Finally, execute this, no matter what.')


##
# Metaclasses.

class Persistent(type):
    def __new__(self, name, bases, dct):
        self.tables = dict()
        return super(Persistent, self).__new__(self, name, bases, dct)

    def __init__(self, name, bases, dct):
        table = name.lower() + 's'
        self.tables[self] = table
        super(Persistent, self).__init__(name, bases, dct)


class Model(object, metaclass = Persistent):
    def table_name(self):
        return Persistent.tables[self.__class__]


class User(Model):
    pass


u = User()
print(u.table_name()) # => users

