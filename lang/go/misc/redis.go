// Copyright (C) 2014-2016 Miquel Sabaté Solà <mikisabate@gmail.com>
// This file is licensed under the MIT license.
// See the LICENSE file.

package main

// This file shows some basic examples of the redis package. It uses pool
// connections, transactions, etc. However, there are more cool examples and
// a superb documentation in: http://godoc.org/github.com/garyburd/redigo/redis

import (
	"fmt"
	"os"
	"time"

	"github.com/garyburd/redigo/redis"
)

// Global variable that will be visible for all the packages of the app.
// The idea is that we want to re-use this pool always.
var Redis *redis.Pool

const (
	// The UNIX socket to be used if the REDIS_SOCK environment variable is not set.
	defaultSocket = "/tmp/redis.sock"

	// The Redis DB to be used if the REDIS_DB environment variable is not set.
	defaultDb = "1"
)

// Get the value of the specified environment variable. If this variable is
// not set, then the given default value will be returned.
//
// name - the name of the environment variable.
// def  - the default value to be used if the environment variable is not set.
//
// Returns a string containing the value of the specified environment variable.
func getenv(name, def string) string {
	if val := os.Getenv(name); val != "" {
		return val
	}
	return def
}

// Initialize the Redis pool for this application.
func initRedis() error {
	sock := getenv("REDIS_SOCK", defaultSocket)
	db := getenv("REDIS_DB", defaultDb)

	// Initialize the pool of connections.
	Redis = &redis.Pool{
		MaxIdle:     5,
		IdleTimeout: 240 * time.Second,
		Dial: func() (redis.Conn, error) {
			c, err := redis.Dial("unix", sock)
			if err != nil {
				return nil, err
			}
			if _, err = c.Do("SELECT", db); err != nil {
				return nil, err
			}
			return c, err
		},
	}

	// Test that connections can be performed.
	conn := Redis.Get()
	defer conn.Close()
	res, err := conn.Do("PING")
	if err != nil || res != "PONG" {
		return err
	}
	return nil
}

func main() {
	if err := initRedis(); err != nil {
		panic("Cannot initialize Redis: " + err.Error())
	}

	// First we do this woth regular "Do" calls.
	r := Redis.Get()
	defer r.Close()
	r.Do("SADD", "golang_key", "value")
	results, err := redis.Strings(r.Do("SMEMBERS", "golang_key"))
	for _, v := range results {
		fmt.Printf("Value: %v\n", v)
	}

	// Let's do it in a transaction :)
	r.Send("MULTI")
	r.Send("SADD", "golang_key", "value")
	r.Send("SMEMBERS", "golang_key")
	others, err := redis.Values(r.Do("EXEC"))

	// Let's see what we've got.
	if err != nil {
		return
	}
	for _, v := range others {
		fmt.Printf("Value: %v\n", v)
	}
}
