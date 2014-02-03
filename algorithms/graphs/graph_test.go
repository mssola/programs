package graph

import (
    "fmt"
    "testing"
)


func TestGraph(t *testing.T) {
    g := NewGraph()
    g.AddVertex(4, 4, 1, 2, 3)
    g.Print()
    g.RemoveVertex(1)
    fmt.Println("---")
    g.Print()
    g.Connect(2, 3, 1)
    g.Connect(2, 4, 2)
    fmt.Println("---")
    g.Print()
    g.Disconnect(2, 3)
    fmt.Println("---")
    g.Print()
}
