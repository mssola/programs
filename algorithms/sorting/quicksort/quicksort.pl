#!/usr/bin/perl -W

use strict;


sub partition {
    my ($array, $low, $high) = @_;
    my $x = $$array[$high];
    my $i = $low - 1;

    for my $j ($low .. $high - 1) {
        if ($$array[$j] <= $x) {
            $i++;
            @$array[$i, $j] = @$array[$j, $i];
        }
    }
    $i++;
    @$array[$i, $high] = @$array[$high, $i];
    return $i;
}

sub quicksort
{
    my ($array, $first, $last) = @_;
    if ($first < $last) {
        my $pivot = partition($array, $first, $last);
        quicksort($array, $first, $pivot - 1);
        quicksort($array, $pivot + 1, $last);
    }
}


my @list = (4, 65, 2, -31, 0, 99, 2, 83, 782, 1);
foreach my $i (@list) {
    print "$i ";
}
print "\n";

quicksort(\@list, 0, $#list);

foreach my $i (@list) {
    print "$i ";
}
print "\n";
