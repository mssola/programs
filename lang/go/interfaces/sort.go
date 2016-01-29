// Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
// This file is licensed under the MIT license.
// See the LICENSE file.

package main

// This file implements a couple of things shown in the documentation of the
// "sort" package. We'll do a basic sort and a multikey sort (a sort based
// on sorting on multiple fields at once).

import (
	"fmt"
	"sort"
)

type Student struct {
	Name, Lastname string
	Age            int
	Qualification  int
}

// First of all, the simple sort. We want something that sorts students by age

type ByAge []Student

func (a ByAge) Len() int {
	return len(a)
}

func (a ByAge) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}

func (a ByAge) Less(i, j int) bool {
	return a[i].Age < a[j].Age
}

// Now we want to be able to sort with multiple keys

type lessFunc func(s1, s2 *Student) bool

// This type knows how to sort students by applying a list of "less" functions.
type StudentSorter struct {
	students []Student
	less     []lessFunc
}

// Create and initialize a student sorter with the given "less" functions.
func OrderedBy(less ...lessFunc) *StudentSorter {
	return &StudentSorter{
		less: less,
	}
}

// This is the function to be called in order to sort students.
func (s *StudentSorter) Sort(students []Student) {
	s.students = students
	sort.Sort(s)
}

func (s *StudentSorter) Len() int {
	return len(s.students)
}

func (s *StudentSorter) Swap(i, j int) {
	s.students[i], s.students[j] = s.students[j], s.students[i]
}

func (s *StudentSorter) Less(i, j int) bool {
	p, q := &s.students[i], &s.students[j]
	var k int

	// We will iterate over all the "less" functions (except the last one). If
	// both elements have a different value for each key, then we can make a
	// decission, otherwise we have to check for the next key.
	for k = 0; k < len(s.less)-1; k++ {
		less := s.less[k]
		switch {
		case less(p, q):
			// p < q
			return true
		case less(q, p):
			// p > q
			return false
		}
	}

	// Both elements are the same for the previous keys. Since we haven't
	// checked the last one yet, we'll base our decission on this one.
	return s.less[k](p, q)
}

func main() {
	students := []Student{
		{"Some", "Guy", 32, 8},
		{"Another", "Guy", 32, 5},
		{"Yet", "Another", 32, 5},
		{"Yet", "Another", 32, 9},
		{"Miquel", "Sabaté", 24, 6},
		{"Old", "Guy", 86, 7},
	}

	// Simple sort
	fmt.Println("Simple sort\n")
	fmt.Printf("Before: ")
	fmt.Println(students)
	sort.Sort(ByAge(students))
	fmt.Printf("After: ")
	fmt.Println(students)

	// Multikey sort
	fmt.Println("\nMulti-key sort")

	// Defining the different "less" functions.
	age := func(s1, s2 *Student) bool {
		return s1.Age < s2.Age
	}
	qualification := func(s1, s2 *Student) bool {
		return s1.Qualification < s2.Qualification
	}
	name := func(s1, s2 *Student) bool {
		n1 := s1.Name + " " + s1.Lastname
		n2 := s2.Name + " " + s2.Lastname
		return n1 < n2
	}

	// Age
	fmt.Println("\nBy age")
	OrderedBy(age).Sort(students)
	fmt.Printf("After: ")
	fmt.Println(students)

	// Age + Qualification
	fmt.Println("\nBy age and qualification")
	OrderedBy(age, qualification).Sort(students)
	fmt.Printf("After: ")
	fmt.Println(students)

	// Everything
	fmt.Println("\nBy age, qualification, name and lastname")
	OrderedBy(age, qualification, name).Sort(students)
	fmt.Printf("After: ")
	fmt.Println(students)
}
