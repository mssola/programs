// Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
// This file is licensed under the MIT license.
// See the LICENSE file.


/**
 * Matching can be used like a switch from languages like C. But we can
 * also add conditions inside a case.
 */

val times = 2
val lang = "ca"

times match {
  case 1 => println("one")
  case 2 if lang == "en" => println("two")
  case 2 if lang == "ca" => println("dos")
  case _ => "another, use this as a wildcard"
}


/**
 * We can use match to handle values of different types differently.
 */

def bigger(o: Any): Any = {
  o match {
    case i: Int if i < 0 => i - 1
    case i: Int => i + 1
    case d: Double if d < 0.0 => d - 0.1
    case d: Double => d + 0.1
    case text: String => text + "s"
  }
}

println(bigger(-1))
println(bigger("thing"))


// We can also use tuples.
val net = ("localhost", 9000)
net match {
  case ("localhost", port) => println("Localhost at port: " + port)
  case (host, port) => println("Host: " + host + " port: " + port)
}


/**
 * We can also match classes. With the case class construct, we can match
 * classes without instantiating them.
 */

case class Calculator(brand: String, model: String)

val hp20b = Calculator("hp", "20B")
val hp30b = Calculator("hp", "30B")

def calcType(calc: Calculator) = calc match {
  case Calculator("hp", "20B") => "financial"
  case Calculator("hp", "48G") => "scientific"
  case Calculator("hp", "30B") => "business"
  case Calculator(ourBrand, ourModel) => "Calculator: %s %s is of unknown type".format(ourBrand, ourModel)
}

// Other alternatives for that last match
// case Calculator(_, _) => "Calculator of unknown type"case _ => "Calculator of unknown type"

// Or we could simply not specify that it’s a Calculator at all.
// case _ => "Calculator of unknown type"

// Or we could re-bind the matched value with another name
// case c@Calculator(_, _) => "Calculator: %s of unknown type".format(c)


/**
 * Matching on exception. In the second example we can see the exceptions
 * can also be used as expressions.
 */

try {
  1 / 0
} catch {
  case e: ArithmeticException => println("Cannot divide by zero")
} finally {
  println("Finally")
}

val result: Int = try {
  1 / 0
} catch {
  case e: Exception => 0
}
println(result)
