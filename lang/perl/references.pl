#!/usr/bin/perl
# Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
# This file is licensed under the MIT license.
# See the LICENSE file.

use strict;


##
# List & hash references.

package Class
{
    sub new
    {
        my ($class, %opts) = @_;
        bless \%opts, $class;
    }

    sub foo
    {
        my ($self) = @_;
        my %hash = ( key => 'value' );
        my @list = qw( one bat two bi );
        my $hash_r = $self->return_hash(\%hash, \@list);
        foreach my $i (keys %$hash_r) {
            print "Key: $i, Value: $hash_r->{$i}\n";
        }
    }

    sub return_hash
    {
        my ($self, $hash_r, $list_r) = @_;
        my %hashed = ( @$list_r );
        my %res = ( %$hash_r, %hashed );
        return \%res;
    }
}

my $c = Class->new(name => 'class');
print "$c->{name}\n";
$c->foo();


##
# Function references,

sub ref1 {
    print "ref1\n";
}

my $ref1 = \&ref1;
my $ref2 = sub { print "ref2\n"; };
$ref1->();
$ref2->();


##
# Filehandle references.

local *FH;
open FH, "references.pl" or die "Could not open references.pl";
my $fh = \*FH;
close $fh;
