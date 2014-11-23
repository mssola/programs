/*
 * Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
 */

#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	std::vector<std::string> v;

	// Adding elements through a lambda expression.
	auto l = [&v](std::string x) {
		v.push_back(x);
	};

	l("hello");
	l("bye");
	for (const auto &s : v) {
		std::cout << s << std::endl;
	}

	// Using the "for_each" new function.
	for_each(v.begin(), v.end(), [](std::string &x) {
		if (x.size() > 0) {
			x[0] = std::toupper(x[0]);
		}
	});
	for (const auto &s : v) {
		std::cout << s << std::endl;
	}
}
