#!/usr/bin/perl
# Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
# This file is licensed under the MIT license.
# See the LICENSE file.

use strict;


package Class
{
    our $VERSION = '0.1';

    sub new
    {
        my ($klass) = @_;
        bless { name => 'name' }, $klass;
    }

    sub name
    {
        my ($self) = @_;
        return $self->{'name'};
    }

    sub set_name
    {
        my ($self, $name) = @_;
        $self->{'name'} = $name;
    }
}


my $o = Class->new();
print $o->name() . "\n";
$o->set_name('mssola');
print $o->name() . "\n";
print $Class::VERSION . "\n";


package SubClass
{
    # ISA is an array containing the parent packages.
    our @ISA = 'Class';

    sub new
    {
        my ($klass, %opts) = @_;
        bless { name => 'name', %opts }, $klass;
    }

    sub opt
    {
        my ($self, $entry) = @_;
        return $self->{$entry};
    }

    sub subname
    {
        # We can access parent methods through SUPER.
        return shift->SUPER::name();
    }
}


my $s = SubClass->new('lala' => 'lala');
print $s->name() . "\n";
$s->set_name('mssola');
print $s->name() . "\n";
print $s->subname() . "\n";
print $SubClass::VERSION . "\n"; # => Empty, the our keyword is per-package.
print $s->opt('lala') . "\n";
print $s->{'lala'} . "\n";
