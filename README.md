# OOP_projects

Small object-oriented C++ projects from 11th and 12th grade. The main one is a reusable **directed graph class** (`Grafuri_Orientate`) with the classic graph algorithms implemented as methods.

## The `Grafuri_Orientate` class

Stores a directed graph as adjacency lists (`vector<int>`), with dynamically allocated arrays for visited flags, distances and in/out degrees.

**OOP concepts used**

- constructor and destructor that allocate and free the internal arrays
- overloaded assignment operator (`operator=`) to copy one graph into another
- method overloading: `Citire()` reads from the keyboard, `Citire(const char*)` reads from a file
- private helper methods (`ReallocPointers`, `Clear`, `Grade`) hidden behind a public interface

**Algorithms**

| Method | What it does |
|---|---|
| `BFS(k)` | Breadth-first search from node `k`, also computes the distance to every node (`Distanta(i)`) |
| `DFS(k)` | Depth-first search |
| `SortTop()` | Topological sort with DFS, read with `VTopologic(i)` |
| `Dextern(i)`, `Dintern(i)` | Out-degree and in-degree of a node |
| `Size()`, `Reset()` | Number of nodes, reset visited flags and distances |

`main()` contains small exercises solved with the class (select one by uncommenting it):

- nodes whose in-degree equals their out-degree
- "friendly" node pairs: nodes at the same distance from each other in both directions (two BFS runs)
- topological sort from `topsort.in` to `topsort.out`

`GrafuriCTC.cpp` is the same class, the starting point for strongly connected components.

## Build and run

```bash
g++ -std=c++17 -O2 Grafuri_Orientate.cpp -o graf
./graf
```

Input format: the number of nodes `n` and edges `m`, then `m` lines `i j` for an edge from `i` to `j`.

## Planned

The list of graph operations I'm adding: read / delete graph, add edge, BFS, DFS, copy graph, adjacency-matrix print, nodes that reach the whole graph, graph union, topological sort, cycles and circuits of length 3, simple paths, friendly nodes, degrees, complete-graph check.

## Tech

C++ · STL (`vector`, `queue`) · OOP · graph algorithms
