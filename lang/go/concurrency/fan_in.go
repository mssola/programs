// Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>

package main

import (
    "fmt"
    "time"
    "os"
    "strconv"
)

// In the fan in pattern we join similar channels into one.
func fanIn(first, second <-chan string) <-chan string {
    c := make(chan string)
    go func() {
        for {
            select {
            case s := <-first: c <- s
            case s := <-second: c <- s
            }
        }
    }()
    return c
}

func main() {
    // Get how many seconds Bob and Alice are allowed to speak.
    if len(os.Args) != 2 {
        panic("dude, wrong usage...")
    }
    seconds, err := strconv.Atoi(os.Args[1])
    if err != nil {
        panic("what kind of integers are you passing me ? :(")
    }

    // Some channels.
    bob := Boring("Bob")
    alice := Boring("Alice")
    fanned := fanIn(bob, alice)
    timeout := time.After(time.Duration(seconds) * time.Second)

    // Let's talk!
    for {
        select {
        case s := <-fanned:
            fmt.Println(s)
        case <-timeout:
            fmt.Println("Enough talking!")
            os.Exit(0)
        }
    }
}
