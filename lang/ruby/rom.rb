# Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
# This file is licensed under the MIT license.
# See the LICENSE file.

##
# This file describes some topics regarding the Ruby Object Model.
#

require 'pp'

##
# First of all, let's take a look at the very basics.

module Modul
  class Klass
    def foo
      @v = 1
    end
  end
end

# Objects contain instance variables and, unlike static languages, in Ruby
# there is no connection between an object’s class and its instance variables.
# Instance variables just spring into existence when you assign them a value,
# so you can have objects of the same class that carry different sets of
# instance variables.
obj = Modul::Klass.new
obj2 = Modul::Klass.new
pp obj.instance_variables # => []
obj.foo
pp obj.instance_variables # => [:@v]
obj2.instance_variable_set(:@x, 42)
pp obj2.instance_variables # => [:@x]


# Classes contain methods. In Ruby there're two kind of methods: instance
# methods (only called by instances) and class methods (only called by
# the class reference).
puts String.instance_methods == 'abc'.methods # => true


# Both obj and Modul::Klass are references to a class. The only difference
# between obj and Modul::Klass is that obj is a variable, while Modul::Klass
# is a constant. The root of the Ruby Class Hierarchy is BasicObject, which
# is the superclass of Object. All the other basic classes in Ruby should be
# subclasses of Object (for example the Module class).
puts <<HERE
obj.class => Modul::Klass
Modul::Klass.class => Class
Class.class => Class
Class.superclass => Module
Module.superclass => Object
Object.superclass => BasicObject
BasicObject.superclass => nil
HERE

# In Ruby, the Class and Module classes are almost identical. In fact, Module
# is the superclass of Class. The Class class just adds three methods:
# allocate (to allocate some memory for the instance), new (to get a new
# instance of the class) and superclass (to access to this class' superclass).
inst = Class.instance_methods - Module.instance_methods
puts "The difference between Class and Module is: #{inst}"


# By definition: any reference that begins with an uppercase letter, including
# the names of classes and modules, is a constant. The scope of constants does
# not follow the same rules as for instance variables. We can imagine that
# modules and classes are directories in a file system and constants are files.
# Therefore, it's possible to have two constants with the same name but still
# be different because where they're contained at.
module MyModule
  MyConstant = 'Outer constant'
  class MyClass
    MyConstant = 'Inner constant'
    pp Module.nesting # => [MyModule::MyClass, MyModule]
  end
end
puts MyModule::MyConstant # => Outer constant
puts MyModule::MyClass::MyConstant # => Inner constant


# I agree that the following calls are confusing as hell. They have the same
# name but the first is a call to an instance method and the second one is
# a call to a class method. Looking at the results, I think it's pretty
# obvious that they are really different methods.
pp MyModule.constants # => [:MyConstant, :MyClass]
pp Module.constants.sort[1..3] # => [:ARGV, :ArgumentError, :Array]


# The BasicObject class provides the most basic methods and is in the root
# of the class hierarchy. It can be useful to create blank slates.
class BlankSlate < BasicObject; end
pp BlankSlate.instance_methods # => [:=, :equal?, :!, :!=, :instance_eval,
                               #     :instance_exec, :__send__, :__id__]

