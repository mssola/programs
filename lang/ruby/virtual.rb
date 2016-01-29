# Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
# This file is licensed under the MIT license.
# See the LICENSE file.

##
# This file describes a simple way to implement the idea of pure virtual
# methods (abstract methods in Java, C#,...) in Ruby. Personally, I haven't
# used this pattern while programming in Ruby, but I thought it could be fun.
#


##
# This class provides a fancy way to show an error when a virtual method
# is being used but the subclass hasn't implemented it.
class VirtualMethodError < RuntimeError
  ##
  # Just call to super with some fancy message.
  def initialize(name)
    super("Error: Pure virtual method '#{name}' called")
  end
end

##
# Here's the trick: let's open the Module class and implement the
# 'virtual' method, so it's available also for classes.
class Module
  ##
  # This method defines a method for each of the elements passed by the
  # variable length argument. The implementation for each method will be
  # just raising a VirtualMethodError coupled with the name of the method.
  def virtual(*methods)
    methods.each do |name|
      define_method(name) { raise VirtualMethodError, name }
    end
  end
end

##
# Let there be code !

class VirtualClass
  virtual :vfoo, :foo
end

class GoodBoy < VirtualClass
  def vfoo
    puts 'Yay!'
  end

  def foo; end
end

class BadBoy < VirtualClass
end

GoodBoy.new.vfoo # Everything is just fine.

begin
  BadBoy.new.vfoo # oopsies !
rescue VirtualMethodError => e
  puts $!
end
