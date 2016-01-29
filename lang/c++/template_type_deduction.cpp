/*
 * Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
 * This file is licensed under the MIT license.
 * See the LICENSE file.
 */

#include <iostream>

#define _unused_(p) (void) p

/**
 * This file is devoted to template type deduction. There's stuff only
 * available since C++11/14. Most of the examples have been taken from the
 * great book "Effective Modern C++" by Scott Meyers. Check it out!
 */

template<typename T>
void foo1(T& param)
{
	_unused_(param);
}

template<typename T>
void foo2(const T& param)
{
	_unused_(param);
}

template<typename T>
void foo3(T&& param)
{
	_unused_(param);
}

template<typename T>
void foo4(T param)
{
	_unused_(param);
}

/**
 * Returns the size of a fixed-sized C-style array in compile time.
 */
template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
	return N;
}

int main(int argc, char *argv[])
{
	int x = 27;
	const int cx = x;
	const int& rx = x;

	// Case 1: The template parameter type is a Reference or a Pointer, but
	// not an Universal reference.

	// Even if T is not const, if the passed parameter is const it has to be
	// enforced upon the "foo" function to ensure the constness.

	foo1(x);     // T is int, param is int&
	foo1(cx);    // T is int, param is const int&
	foo1(rx);    // T is int, param is const int&

	// The T type in foo2 is const, so the constness has to be enforced for any
	// given parameter type.

	foo2(x);     // T is int, param is const int&
	foo2(cx);    // T is int, param is const int&
	foo2(rx);    // T is int, param is const int&

	// Case 2: The template parameter type is an Universal reference.

	// If the passed parameter is an lvalue, both T and param will be lvalue
	// references. Otherwise, the rules described in "Case 1" apply.

	foo3(x);     // T is int&, param is int&
	foo3(cx);    // T is const int&, param is const int&
	foo3(rx);    // T is const int&, param is const int&
	foo3(27);    // T is int, param is int&&

	// Case 3: The template parameter type is neither a Reference nor a Pointer.

	// We're passing by value: references, const and volatile will be ignored.

	foo4(x);     // T is int, param is int
	foo4(cx);    // T is int, param is int
	foo4(rx);    // T is int, param is int

	// Pointers and C-style arrays have the same logic as before when deducing
	// their types.

	// Oh, by the way, did you know that you can pass C arrays by reference? :P
	int numbers[] = { 1, 2, 3, 4, 5 };
	std::cout << arraySize(numbers) << std::endl;
}

