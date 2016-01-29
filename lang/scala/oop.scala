// Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
// This file is licensed under the MIT license.
// See the LICENSE file.


/*
 * Abstract classes, just like abstract classes in other places such as
 * Java, PHP, etc. or C++ pure virtual classes.
 */
abstract class AbstractCalculator {
  def add(x: Int, y: Int): Int
}

class Calculator(brand: String) extends AbstractCalculator {
  /**
   * A constructor is not a special method, but the code that lies outside
   * of method definitions in our class.
   */
  val color: String = if (brand == "TI") {
    "blue"
  } else if (brand == "HP") {
    "black"
  } else {
    "white"
  }

  // An instance method.
  def add(m: Int, n: Int): Int = m + n
  def quack = println("Calculator")
}

val calc = new Calculator("HP")
println(calc.color)
println(calc.add(1, 2))


/*
 * The difference between functions and methods.
 */

class C {
  var acc = 0

  def minc = { acc += 1 }
  def finc = { () => acc + 1 }
}

val c = new C
println(c.minc) // Calls minc()
println(c.finc) // Returns the function as a value.


/*
 * Subclassing.
 */

class CoolCalculator(brand: String, n: String) extends Calculator(brand) {
  val _name = c

  // Overloading.
  def add(x: Int, y: Int, z: Int): Int = x + y + z

  // Overriding.
  override def quack = println("CoolCalculator")
}

val cc = new CoolCalculator("HP", "yellow")
println(cc.color)
println(cc.add(1, 2))
println(cc.add(1, 2, 3))
cc.quack

/*
 * Aliasing. Prefer aliasing instead of subclassing if the subclass isn't
 * really different from the superclass.
 */

type Accumulator = C


/**
 * Traits. Traits are a collection of fields and behaviors that can be
 * later mixed in a class. The cool thing about traits is that classes
 * can mix in multiple traits.
 */

trait Car {
  val brand: String
}

trait Shiny {
  val shineRefraction: Int
}

// Even if the syntax differ, here, extends and with mean the same.
class BMW extends Car with Shiny {
  val brand = "BMW"
  val shineRefraction = 12
}

val bmw = new BMW
println(bmw.shineRefraction)


/**
 * Generics.
 */

trait Cache[K, V] {
  def get(key: K): V
  def put(key: K, value: V)
  def delete(key: K)
}

// Methods can also have type parameters introduced.
def remove[K](key: K) = { /* Doing nothing :P */ }


/**
 * The apply method. It's a nice syntactic sugar for when a class or object
 * has one main use.
 */

class Bar {
  def apply() = 0
}

val bar = new Bar
println(bar())


/**
 * Objects. Objects are used to hold single instances of a class. They
 * are often used for factories.
 */

object Timer {
  var count = 0

  def current() = {
    count += 1
    count
  }
}

println(Timer.current())

/**
 * Moreover, inside a package it's not allowed to define functions or
 * values. If we want to define package values/functions, we can put them
 * inside an object.
 */

/*
  package example {
    object Values {
      val VALUE = 1
    }
  }
  println(example.Values.VALUE)
*/


/**
 * Objects and classes can have the same name. The object is called then
 * the "Companion Object". This technique is used to create factories.
 * Objects can also implement the apply method. Therefore, we can have
 * the following.
 */

class Bar2(foo: String) {
  val f = foo
}

object Bar2 {
  def apply(foo: String) = new Bar2(foo)
}

val bar2 = Bar2("asd")
println(bar2.f)


/**
 * Functions are objects. A function is a s set of traits. That is, a
 * function that takes one argument is an instance of a Function1 trait.
 * This trait defines the apply method. Let's do something similar.
 */

object addOne extends Function1[Int, Int] {
  def apply(m: Int): Int = m + 1
}

println(addOne(1))

/*
 * A nice shortcut for this is the (Int => Int) syntax. Therefore, the
 * following example does the same than the previous example but by using
 * a class (the same can be done in an object, of course).
 */

class AddOne extends (Int => Int) {
  def apply(m: Int) = m + 1
}
