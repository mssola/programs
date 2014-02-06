package main

import (
    "time"
    "fmt"
    "math/rand"
    "os"
    "strconv"
)

// Say something boring and sleep for a random number of milliseconds.
func boring(msg string) <-chan string {
    c := make(chan string)
    go func() {
        for i := 0; ; i++ {
            c <- fmt.Sprintf("%s %d", msg, i)
            time.Sleep(time.Duration(rand.Intn(1e3)) * time.Millisecond)
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

    // Let there be channels.
    bob := boring("Bob")
    alice := boring("Alice")
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

