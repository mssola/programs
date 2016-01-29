// Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
// This file is licensed under the MIT license.
// See the LICENSE file.

package main

import (
	"encoding/json"
	"fmt"
	"os"
)

type Configuration struct {
	Database map[string]struct {
		Dbname   string
		Host     string
		User     string
		Password string
	}

	Redis struct {
		Socket string
		Db     string
	}
}

func main() {
	file, _ := os.Open("data/config.json")
	decoder := json.NewDecoder(file)
	c := &Configuration{}
	decoder.Decode(&c)

	// Database
	fmt.Printf("Dbname of test: %v\n", c.Database["Test"].Dbname)

	// Redis
	fmt.Printf("Redis. Socket: %v ; DB: %v\n", c.Redis.Socket, c.Redis.Db)
}
