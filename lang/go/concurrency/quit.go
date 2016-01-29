// Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
// This file is licensed under the MIT license.
// See the LICENSE file.

package main

import (
	"fmt"
)

func main() {
	quit := make(chan bool)
	out := make(chan string)
	bob := BoringChan("Bob", quit, out)
	alice := BoringChan("Alice", quit, out)

	for i := 0; i < 5; i++ {
		select {
		case s := <-bob:
			fmt.Println(s)
		case s := <-alice:
			fmt.Println(s)
		}
	}

	quit <- true
	fmt.Println(<-out)
	quit <- true
	fmt.Println(<-out)
}
