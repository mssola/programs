# Go programming language

Examples that helped me understand Go. Each topic has its own subdirectory. To
compile all the examples there will be always an all.sh executable script. Just
run this script and all the examples will be compiled.

## Concurrency

To compile each example separately you have to compile the common.go file too.

* fib.go: simple generator pattern.
* timeout.go: Alice and Bob talk to each other through channels. A timeout will
  interrupt them.
* fan_in.go: basically the same as the timeout but the Alice and Bob channels
  are joined into the same channel.


