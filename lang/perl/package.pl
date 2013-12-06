#!/usr/bin/perl
#
# Copyright (C) 2013 Miquel Sabaté Solà <mikisabate@gmail.com>
#

use strict;


# We're now in the "main" package.

package Pack;

# We're now in the "Pack" package.

package Thing
{
    # Pack::Thing
    our $VERSION = '0.1';

    sub foo
    {
        print "foo!\n";
    }
}

# In Pack again.

Thing::foo();

package Another;

# Oops, now we're in "Another" package (Pack::Another).

print __PACKAGE__ . "\n";
Thing::foo();
print $Thing::VERSION . "\n";
