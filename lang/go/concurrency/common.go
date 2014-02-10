// Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>

package main

import (
    "fmt"
    "time"
    "math/rand"
)

// Say something boring and sleep for a random number of milliseconds.
func Boring(msg string) <-chan string {
    c := make(chan string)
    go func() {
        for i := 0; ; i++ {
            c <- fmt.Sprintf("%s %d", msg, i)
            time.Sleep(time.Duration(rand.Intn(1e3)) * time.Millisecond)
        }
    }()
    return c
}

// Same as the Boring function but with channels.
func BoringChan(msg string, quit chan bool, out chan string) <-chan string {
    c := make(chan string)
    go func() {
        for i := 0; ; i++ {
            select {
            case c <- fmt.Sprintf("%s %d", msg, i):
                // Doing nothing.
            case <-quit:
                out <- msg + " says good bye!"
                return
            }
        }
    }()
    return c
}
