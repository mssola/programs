#!/bin/bash


for i in `ls *.go | grep -v common`; do
  `go build $i common.go`
done

