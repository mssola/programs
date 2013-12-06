#!/usr/bin/python
#
# Copyright (C) 2013 Miquel Sabaté Solà <mikisabate@gmail.com>
#


##
# Strings.

print('Simple string {0}'.format('formatting'))
print('{0:.1f} {1}'.format(698.4, 'GB'))


##
# Lists. A list is an array as in Perl.

list = [1, 2, 3]
list.append(5) # => [1, 2, 3, 5]
list.append(4) # => [1, 2, 3, 5, 4]
list[1:3] # => [2, 3]
list[:3] # => [1, 2, 3]
list[1:] # => [2, 3, 5, 4]
list[:] # => [1, 2, 3, 5, 4]
list.extend([6, 7]) # => [1, 2, 3, 5, 4, 6, 7]
list.insert(0, 2) # => [2, 1, 2, 3, 5, 4, 6, 7]

2 in list # => True
list.index(2) # => 0
list.count(2) # => 2

del list[-1] # => [2, 1, 2, 3, 5, 4, 6]
list.remove(2) # => [1, 2, 3, 5, 4, 6]
list.pop() # => [1, 2, 3, 5, 4]; Returns: 6

if list:
    print('The list is not empty.')
else:
    print('Empty list.')


##
# Tuples. Inmutable lists.

try:
    t = (1, 1, 2, 3)
    t.append(5)
except:
    print('You cannot modify tuples.')

a, b = (1, 2) # => same as: (a, b) = (1, 2); same as: a, b = 1, 2
print("{0}, {1}".format(a, b))


##
# Sets. Lists of unique values.

empty = set() # => {} creates an empty dict, not a set.
s = {1, 2}
s.add(1)
len(s) # => 2
s.remove(2)
len(s) # => 1
s.update([2, 4])
len(s) # => 3
s.discard(4)
len(s) # => 2
s.discard(4) # => nothing happens (with remove() Python raises an exception).
s.clear()
len(s) # => 0


##
# Dictionaries.

d = dict() # => same as: d = {}
d = { 'key': 'value' }
print(d['key']) # => value
try:
    d['lala']
except:
    print('Exception!')


##
# Comprehensions.

a = [x * 2 for x in [1, 2, 3]]
print(a) # => 2, 4, 6


##
# Regular expressions.

import re

str = 'asd123dasdas111sdas1'
print(re.findall('(\d{2,3})', str)) # => ['123', '111']

pattern = re.compile(r'''
            # don't match beginning of string, number can start anywhere
(\d{3})     # area code is 3 digits (e.g. '800')
\D*         # optional separator is any number of non-digits
(\d{3})     # trunk is 3 digits (e.g. '555')
\D*         # optional separator
(\d{4})     # rest of number is 4 digits (e.g. '1212')
\D*         # optional separator
(\d*)       # extension is optional and can be any number of digits
$           # end of string
''', re.VERBOSE)
pattern.search('work 1-(800) 555.1212 #1234').groups() # => ('800', '555', '1212', '1234')
pattern.search('800-555-1212') # => ('800', '555', '1212', '')
