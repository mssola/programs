/*
 * Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
 * This file is licensed under the MIT license.
 * See the LICENSE file.
 */

/*
 * This is an example to show off the different smart pointers available in the
 * standard library since C++11 (therefore std::auto_ptr is excluded).
 *
 * In this example we can build a Town, which is essentially a map of people. A
 * person has a name, a last name and an age. The map of people is built with
 * the pair: std::string, std::shared_ptr<Person>. This way, the Town struct
 * takes responsibility on allocating/freeing each person, but it will be done
 * implicitly through the shared_ptr mechanism.
 *
 * Additionally, let's imagine that it makes sense to cache the people being
 * accessed through the Town struct. This cache will be built with weak_ptr's
 * instead of shared_ptr's. This is because the elements of this cache will
 * point to the shared_ptr elements from the original map, and we don't want
 * this cache to update the reference counter. Moreover, it's convenient
 * because the transformation from weak_ptr to shared_ptr is trivial.
 *
 * Finally, in the main function we use a unique_ptr to store the town.
 */

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

struct Person
{
	Person(std::string name, std::string lastname, uint age);
	const std::string toString() const;

	std::string name;
	std::string lastname;
	uint age;
};

Person::Person(std::string name, std::string lastname, uint age)
	: name(name)
	, lastname(lastname)
	, age(age)
{
}

const std::string Person::toString() const
{
	return "My name is " + name + " " + lastname + " and I'm " +
		std::to_string(age) + " years old.";
}

struct Town
{
	using Population = std::unordered_map<std::string, std::shared_ptr<Person>>;

	explicit Town(Population &&people);
	std::shared_ptr<Person> getPerson(std::string id);

	Population people;

private:
	std::unordered_map<std::string, std::weak_ptr<Person>> cache;
};

Town::Town(Population &&people)
	: people(std::move(people))
{
}

std::shared_ptr<Person> Town::getPerson(std::string id)
{
	// Lookup the cache first.
	const auto &it = cache.find(id);
	if (it != cache.end()) {
		std::cout << "Cached!" << std::endl;
		return it->second.lock();
	}

	// Is it an existing person ?
	const auto &pit = people.find(id);
	if (pit == people.end()) {
		return nullptr;
	}

	// Add it to the cache and return this person.
	cache[id] = pit->second;
	return pit->second;
}

int main(int argc, char *argv[])
{
	// Note that we have to specify the type (Town::Population) because
	// std::make_unique wouldn't be able to deduce the type otherwise with the
	// brace initialization syntax.
	auto town = std::make_unique<Town>(Town::Population{
		{"person1", std::make_shared<Person>("John", "Smith", 21)},
		{"person2", std::make_shared<Person>("Michael", "Scott", 43)},
		{"person3", std::make_shared<Person>("George", "Washington", 44)}
	});

	auto p1 = town->getPerson("person1");
	std::cout << p1->toString() << std::endl;

	std::cout << "Should say cached: ";
	auto p2 = town->getPerson("person1");
	std::cout << p2->toString() << std::endl;
}

