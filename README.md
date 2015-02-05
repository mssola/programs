
## Programs

This repository contains a set of random programs that I have written with
the sole purpose of learning. I have created a subdirectory for each main area.
This way, we have:

- `algorithms`: different algorithms implemented (maybe) in different
programming languages.
- `lang`: it contains a subdirectory for each programming language. This
doesn't mean that I perfectly know each language or that these are all the
languages that I "know".
- `net`: a subdirectory containing low-level stuff in regards to networking.
- `os`: bare-metal programs that are focussed on teaching stuff from (UNIX)
operating systems. I've written everything on a Linux machine, so I don't
really advertise it as a full POSIX-compatible thing.

Some of these directories might "feel incomplete", but bear in mind that these
programs are not only stuff that I've learned during my time as a programmer,
but it also means that I had the time/patience to actually write them in a
"useful" way. Note that the term "useful" is quite subjective. By that I mean:

- First of all, they are/were useful to me.
- Some of these programs/scripts are *really* old and might seem ridiculous to
me from a technical point of view. I've just added them in this repo for
historical/nostalgic reasons, and adapted them to my current code
style. This applies for example to programs like `lang/c/clock.c` or
`algorithms/misc/power_of_two.c`.

Moreover, some of these files have been built as a "mini-tutorial". That is,
their sole purpose is to introduce the reader to a concept. The best examples
of this are probably files such as `lang/perl/basics.pl`.

## Running this stuff

Each program is a different executable file or script. For C and C++ programs,
we can rely on CMake. So, in order to compile all of them, you just have to do:

```
$ mkdir build && cd build
$ cmake ..
$ make
```

Note that since this is a personal project, I'm not being shy on which versions
I want to use. Since the only purpose of some of the C++ files is to
show off some C++11/14 feature, in this project we require compilers that know
how to deal with these standards *perfectly*. In our case, this is GCC 4.9 and
Clang 3.5. I haven't tested MSVC because, again, I work on Linux. Moreover, the
C standard being picked is C11.

Another exceptional case is the Go programming language. This programming
language does not respect the fact that a programmer might want to implement
multiple executable files into the same directory. I'm fine with this
decission, but it makes our lives a bit harder in this specific case. For this,
all the subdirectories in the `lang/go` directory include a `all.sh` script.
Run this script to compile the different programs. Otherwise, if this script
does not exist, it means that the plain `go build` command will suffice.

Finally, for all the other cases, running this stuff is as easy as running the
given interpreter/compiler and passing the desired file.

## License

Copyright (c) 2014 Miquel Sabaté Solà

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
