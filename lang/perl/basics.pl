#!/usr/bin/perl
# Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
# This file is licensed under the MIT license.
# See the LICENSE file.

use strict;


##
# Undef.

my $undef;
my $same_as_above = undef;


##
# Strings.

my $str = 'string';
$str = qq(double quotes);
$str = q^single quote^;
$str = "two
lines";
$str = <<HEREDOC;
two
lines
HEREDOC
$str .= ' concatenated';


##
# Numbers.

my $bin = 0b101011;
my $oct = 0123214;
my $tho = 1_000;


##
# Lists.

my @list = (1, 2, 3);
my @range = 1 .. 3;
my ($first, $second) = @range;
print "First: $first, Second: $second\n";
my @cool = qw( this is a list of strings );
for (@cool) {
    print "$_ ";
}
print "\n";

my $count = @cool;
my $last = $cool[-1];

push @cool, 'another';
for (@cool) { print "$_ "; }
print "\n";
$last = pop @cool;

unshift @cool, qw( this will be prepended );
for (@cool) { print "$_ "; }
print "\n";
my $first = shift @cool;
for (@cool) { print "$_ "; }
print "\n";

my ($second, $third) = splice @cool, 1, 2;
print "Second: $second, Third: $third\n";
for (@cool) { print "$_ "; }
print "\n";

my @sublist = @cool[1..2];
for (@sublist) { print "$_ "; }
print "\n";


##
# Hashes.

my %empty;
my %hash = ('key1', 'value1', 'key2', 'value2');
%hash = ('key1' => 'value1', 'key2' => 'value2');
my $value = $hash{'key1'};

print "Keys.\n";
for (keys %hash) { print "$_ "; }
print "\n";
print "Values.\n";
for (values %hash) { print "$_ "; }
print "\n";
print "Altogether.\n";
while (my ($k, $v) = each %hash) {
    print "$k => $v\n";
}
