// Copyright (C) 2014 Miquel Sabaté Solà <mikisabate@gmail.com>
// This file is licensed under the MIT license.
// See the LICENSE file.

package main

// This is an incredibly simple & stupid example of a type that implements both
// the Reader and the Writer interfaces. Note that this is *not* the best way
// to read files, this example is here just for the sake of the example :)

import (
	"io"
	"os"
)

type FileBuffer struct {
	path      string
	readSeek  int64
	writeSeek int64
}

// Read a file and put the contents into the given bytes.
func (f FileBuffer) Read(p []byte) (int, error) {
	file, err := os.Open(f.path)
	if err != nil {
		return 0, err
	}
	defer file.Close()

	if _, err := file.Seek(f.readSeek, 0); err != nil {
		return 0, err
	}

	count, err := file.Read(p)
	if err == nil {
		f.readSeek += int64(count)
	}
	return count, err
}

// Opens a file and appends the given bytes to it. The file will be created if
// it doesn't exist yet.
func (f FileBuffer) Write(p []byte) (int, error) {
	file, err := os.Open(f.path)
	if err != nil {
		if os.IsNotExist(err) {
			if file, err = os.Create(f.path); err != nil {
				return 0, err
			}
		} else {
			return 0, err
		}
	}
	defer file.Close()

	if _, err := file.Seek(f.writeSeek, 0); err != nil {
		return 0, err
	}

	count, err := file.Write(p)
	if err == nil {
		f.writeSeek += int64(count)
	}
	return count, err
}

func main() {
	src := FileBuffer{path: "./reader_writer.go"}
	dst := FileBuffer{path: "./lol.txt"}
	io.Copy(dst, src)
}
