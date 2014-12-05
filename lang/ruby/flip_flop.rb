# Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
# This file is licensed under the MIT license.
# See the LICENSE file.


# This file shows a somewhat rare feature of Ruby with the .. operator.
# It's a a perlism called "flip-flop". This feature will make it into Ruby 2.0
# but its future is uncertain (probably removed in a future Ruby 3.0 ?).
#
# More on flip-flops here: https://bugs.ruby-lang.org/issues/5400


# Prints all the lines between begin..end in the DATA section.
DATA.each_line do |line|
  print line if (line =~ /begin/)..(line =~ /end/)
end

__END__
0a
1begin
2c
3end
4e
5f
6begin
7end
8i
9j
