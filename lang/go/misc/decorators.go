// Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
// This file is licensed under the MIT license.
// See the LICENSE file.

package main

import (
	"fmt"
)

type Func func(i int) int

// Simple decorator that multiplies the result by 4 if the original value was
// lesser than 4.
func decorator(f Func) Func {
	return func(i int) int {
		res := f(i)
		if i < 4 {
			return res * 4
		}
		return res
	}
}

func original(i int) int {
	return i
}

func main() {
	decorated := decorator(original)

	fmt.Println(decorated(2)) // => 2 * 4
	fmt.Println(decorated(5)) // => 5
}
