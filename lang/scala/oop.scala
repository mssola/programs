/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 */


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
