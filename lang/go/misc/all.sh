#!/bin/bash


for i in `ls *.go`; do
  `go build $i`
done

