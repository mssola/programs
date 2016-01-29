// Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
// This file is licensed under the MIT license.
// See the LICENSE file.

package main

import (
	"fmt"
	"os"
	"strconv"
	"time"
)

func main() {
	// Get how many seconds Bob and Alice are allowed to speak.
	if len(os.Args) != 2 {
		panic("dude, wrong usage...")
	}
	seconds, err := strconv.Atoi(os.Args[1])
	if err != nil {
		panic("what kind of integers are you passing me ? :(")
	}

	// Let there be channels.
	bob := Boring("Bob")
	alice := Boring("Alice")
	timeout := time.After(time.Duration(seconds) * time.Second)

	// And let them talk.
	for {
		select {
		case s := <-bob:
			fmt.Println(s)
		case s := <-alice:
			fmt.Println(s)
		case <-timeout:
			fmt.Println("You've talked too much!")
			os.Exit(0)
		}
	}
}
