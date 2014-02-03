package graph

import (
    "fmt"
)


type Vertex struct {
    id int
    edges map[string]*Edge
}

type Edge struct {
    weight int
    first, last *Vertex
}

type Graph struct {
    vertices map[int]*Vertex
    edges map[string]*Edge
}


func NewGraph() *Graph {
    g := new(Graph)
    g.vertices = make(map[int]*Vertex)
    g.edges = make(map[string]*Edge)
    return g
}

func (g *Graph) AddVertex(vertices ...int) {
    for _, nv := range vertices {
        if node := g.vertices[nv]; node != nil {
            fmt.Printf("Warning: node %v already exists.\n", nv)
            continue
        }
        vtx := new(Vertex)
        vtx.id = nv
        vtx.edges = make(map[string]*Edge)
        g.vertices[nv] = vtx
    }
}

func (g *Graph) RemoveVertex(id int) {
    if node := g.vertices[id]; node != nil {
        delete(g.vertices, id)
    }
}

func (g *Graph) Connect(a, b, weight int) {
    id := fmt.Sprintf("%v-%v", a, b)
    if edge := g.edges[id]; edge != nil {
        fmt.Printf("Warning: the edge connecting the %v and %v nodes already" +
                   " exists.\n", a, b)
        return
    }
    e := new(Edge)
    e.weight = weight
    e.first = g.vertices[a]
    e.last = g.vertices[b]
    e.first.edges[id] = e
    e.last.edges[id] = e
    g.edges[id] = e
}

func (g *Graph) Disconnect(a, b int) {
    id := fmt.Sprintf("%v-%v", a, b)
    if g.edges[id] != nil {
        delete(g.edges[id].first.edges, id)
        delete(g.edges[id].last.edges, id)
        delete(g.edges, id)
    }
}

func (g *Graph) Print() {
    printed := map[string]bool{}

    if len(g.vertices) == 0 {
        fmt.Println("Empty graph")
        return
    }

    for idx, v := range g.vertices {
        if len(v.edges) == 0 {
            fmt.Printf("Lonely vertex %v\n", idx)
            continue
        }

        for idx, e := range v.edges {
            if _, ok := printed[idx]; ok {
                continue
            }
            if len(printed) > 0 {
                fmt.Printf(", ")
            }
            printed[idx] = true
            fmt.Printf("%v -> %v", e.first.id, e.last.id)
            if e.weight > 0 {
                fmt.Printf(" (weight %v)", e.weight)
            }
        }
    }
    fmt.Println("")
}
