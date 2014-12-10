/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 * This file is licensed under the MIT license.
 * See the LICENSE file.
 */

#include <iostream>
#include <string>

class Thing
{
public:
	// NOTE: it's *important* that this string is not `const`, because the
	// std::string class does *not* have a constructor taking a const rvalue
	// reference. If this parameter had been const, then it would've
	// compiled just fine and called the copy constructor (thus copying, not
	// moving). As a general rule: move constructors never wear a const.
	explicit Thing(std::string text)
		: m_str(std::move(text))
	{
		std::cout << "First constructor < " << m_str << std::endl;
	}

	// This is how a typical move constructor works.
	explicit Thing(Thing&& thing)
		: m_str(std::move(thing.m_str))
	{
		std::cout << "Move constructor < " << m_str << std::endl;
	}

private:
	std::string m_str;
};

int main(int argc, char *argv[])
{
	// Using the first constructor.
	Thing t1(std::string("Hello"));

	// Using the move constructor.
	Thing t2(Thing(std::string("Lala")));

	// NOTE: The following declaration would've resulted in a compile error:
	//
	// 	Thing t3(t2);
	//
	// This is because Thing has declared a user-defined move constructor.
	// Doing this implicitly deletes the copy constructor. So our only option
	// is to use the move constructor. We do that by using std::move.
	Thing t3(std::move(t2));
}

