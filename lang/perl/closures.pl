#!/usr/bin/perl
# Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
# This file is licensed under the MIT license.
# See the LICENSE file.

use strict;


# Decorator. Same idea as the Python decorators. In this case it takes a
# function as the only argument and returns a closure that returns the result
# of the originally passed function plus two.
sub plus_two
{
    my ($f_ref) = @_;
    return sub() {
        return $f_ref->(@_) + 2;
    }
}

sub mul()
{
    my ($one, $two) = @_;
    return $one * $two;
}

# And decorate the mul function so it always adds 2 to the result of
# the original mul.
my $mul_plus_two = plus_two(\&mul);
print $mul_plus_two->(2, 3) . "\n";


# Lazy generator. It returns a generator of Fibonacci numbers that holds
# a cache that is filled lazyly.
sub lazy_fibonacci
{
    my @fibs = (0, 1);

    return sub {
        my $item = shift;
        if ($item >= @fibs) {
            for my $i (@fibs .. $item) {
                $fibs[$i] = $fibs[$i - 2] + $fibs[$i - 1];
            }
        }
        return $fibs[$item];
    }
}

my $gen_fib = lazy_fibonacci();
print $gen_fib->(4) . "\n";
print $gen_fib->(8) . "\n";
