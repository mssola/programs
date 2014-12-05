// Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
// This file is licensed under the MIT license.
// See the LICENSE file.


/*
 * Strings. Defined with double quotes. Character can also be declared
 * with single quote characters.
 */

println("ABCDEF".length)
println("ABCDEF".substring(2, 6))
println("ABCDEF".replace("C", "3"))

val n = 45
println(s"We have $n apples")

val aux = Array(11, 9, 6)
println(s"My second daughter is ${aux(2-1)} years old")

// Some characters need to be 'escaped', e.g. a double quote inside a string:
val lala = "They stood outside the \"Rose and Crown\""

// Triple double-quotes let strings span multiple rows and contain quotes
val html = """<form id="daform">
                <p>Press belo', Joe</p>
             |  <input type="submit">
//               </form>"""

/*
 * Functions.
 */

// Variable-length arguments.
def capitalizeAll(args: String*) = {
  args.map { arg =>
    arg.capitalize
  }
}
println(capitalizeAll("miquel", "sabaté"))

// Recursive function have to define a return type because the compiler
// can't infer it for us.
def recursive(a:Int, b:Int):Unit = {
  print(a)
  if (a < b) {
    recursive(a + 1, b)
  }
}
recursive(1, 5)
println("")

// Assigning a function.
val sq = (x:Int) => x * x
println(sq(10))

// Mapping with an stored function.
val add10: Int => Int = _ + 10
val list1 = List(1, 2, 3) map add10
println(list1)

// Anonymous function.
val list2 = List(1, 2, 3) map (x => x + 10)
println(list2)

// Anonymous function with implicit variable.
val list3 = List(1, 2, 3) map (_ + 10)
println(list3)

// If the anonymous block *and* the function we're applying both take one
// argument, we can even omit the underscore.
List(1, 2, 3) foreach println


/*
 * Data structures: Array, Map & Set.
 */

/*
 * Array vs List:
 *  - Array: mutable, simple array, faster random access.
 *  - List: immutable, built again with accesses, faster appending of elements.
 */
val a = Array(1, 2, 3, 4)
println(a(0))
try {
  println(a(-1))
} catch {
  case ex: ArrayIndexOutOfBoundsException =>{
    println("Invalid access")
  }
}

/*
 * Maps are immutable hashes.
 */
val b = Map("first" -> "value1", "second" -> "value2")
println(b)
println(b("first"))
try {
  println(b("lala"))
} catch {
  case ex: NoSuchElementException =>{
    println("Invalid access")
  }
}

// This is a safer way to get things.
val res1 = b.get("first")
val undef = b.get("undefined")
println(res1.get)
println(undef.isDefined)
println(undef.getOrElse(1))

/*
 * Sets.
 */
var c = Set(1, 2, 3)
c += 2
println(c)

/*
 * Tuples. To access elements, we use the t._n notation, where n is the
 * 1-based index of the element.
 */
println((1, 2)._1)
val divideInts = (x:Int, y:Int) => (x / y, x % y)
val d = divideInts(10, 3)
print(d._1 + " ")
println(d._2)

// Syntactic sugar to create 2-sized tuples.
val tup = 1 -> 2


/*
 * Combinators.
 */

val squared = c.map(sq)
println(squared)
println(squared.filter(_ < 6))
println(squared.reduce(_ + _))
squared foreach (x => println(x))
squared foreach println


/*
 * For comprehensions.
 */

val squared2 = for { n <- c } yield sq(n)
println(squared)
println(for { n <- squared2 if n < 6 } yield n)
println(for { n <- c; squared = n * n if squared < 10} yield squared)


/*
 * Loops and iteration.
 */

(1 to 5).foreach( println )
(1 to 5 by 2).foreach( println )

// There's nothing magic in Scala's while and do-while loops.
var i = 0
while (i < 10) {
  println("i: " + i)
  i += 1
}
println(i)

// Conditionals are done with if-else. There's no ternary operator. Switches
// are done through "Pattern matching" (See the re.scala file).
if (i < 10) {
  println("Lesser")
} else if (i == 10) {
  println("Equal")
} else {
  println("Greater")
}


/*
 * Application structure and organization
 */

// Importing things
import scala.collection.immutable.List

// Import all "sub packages"
import scala.collection.immutable._

// Import multiple classes in one statement
import scala.collection.immutable.{List, Map}

// Rename an import using '=>'
import scala.collection.immutable.{ List => ImmutableList }

// Import all classes, except some. The following excludes Map and Set:
import scala.collection.immutable.{Map => _, Set => _, _}


/*
 * I/O.
 */

import scala.io.Source
for (line <- Source.fromFile("basics.scala").getLines())
  println(line)
