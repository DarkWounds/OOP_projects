# OOP_projects

Object-oriented programming in C++ from 11th and 12th grade: small, self-contained programs, each focused on one concept, most of them applied to a classic algorithmic problem.

> Branch **`Grafice`** contains a separate project: a reusable directed-graph class (BFS, DFS, topological sort, degrees).

## Programs

### Classes, constructors and destructors

| File | Topic | What it does |
|---|---|---|
| `oop01.cpp` | Classes, access specifiers | `Rational` class: add and multiply fractions, simplified with the GCD (recursive and iterative) |
| `oop02.cpp` | Constructors | `Complex` class with default, parameterised, copy and read-from-file constructors; add, multiply, divide, modulus |
| `oop03.cpp` | Encapsulation | Stack that also returns its maximum element |
| `oop04.cpp` | Destructor, dynamic memory | `Vector` class: a dynamic array that doubles its capacity (like `std::vector`), with insert, erase, sort, linear and binary search (first and last occurrence) |
| `oop09.cpp` | Static members | A static variable shared by all objects, used to count them, plus a static method |

### Templates

| File | Topic | What it does |
|---|---|---|
| `oop05.cpp` | Function template | Sum of an array for any numeric type, with the size as a template parameter |
| `oop06.cpp` | Class template | Generic `Stiva<T>` (stack) driven by push / pop / top commands |
| `oop07.cpp` | Template applied | *Intervale4*: merges overlapping intervals with a `Stiva<Interval>` and counts the result |
| `oop08.cpp` | Template applied | Removes `k` digits from a number to get the smallest possible result (greedy with a `Stiva<char>`) |

### Operator overloading

| File | Topic | What it does |
|---|---|---|
| `oop10.cpp` | Linked list + operators | `LSI` singly linked list: insert at the front, after a node or at the end, erase, destructor that frees every node; overloaded `[]`, `==`, `=` and `<<` |
| `oop11.cpp` | Matrix operators | Square `Matrice` class with overloaded `=`, `+`, `*` and `<<` |

### Inheritance and hash tables

| File | Topic | What it does |
|---|---|---|
| `oop12.cpp` | Inheritance | `HashTable` (separate chaining, value + frequency) and a derived class `H2` that finds the smallest value appearing exactly once |
| `oop13.cpp` | Inheritance | *SumUnice*: for every window of length `k`, counts the values that appear exactly once (sliding window over the hash table) |
| `oop14.cpp` | Hash table + bits | *Complementar*: counts pairs of binary strings that are complements of each other, using XOR and the hash table |

### Polymorphism and backtracking

| File | Topic | What it does |
|---|---|---|
| `oop15.cpp` | Virtual functions | `FormeGeom → Cerc → Cilindru`: area, perimeter and volume called through base-class pointers |
| `oop16.cpp` | Polymorphic backtracking | Generic `Backtracking` class with virtual `Valid`, `Back` and `Afis`; `Paranteze` derives from it to generate all balanced bracket sequences |
| `oop17.cpp` | Polymorphic backtracking | `Combinari`: all combinations of `n` taken `k` |
| `oop18.cpp` | Polymorphic backtracking | *descp2*: every way to write a sum as powers of 2 |

## Build and run

Each file is an independent program:

```bash
g++ -std=c++17 -O2 oop04.cpp -o oop04
./oop04
```

Some programs read from a `.in` file and write to a `.out` file with the same name as the problem (for example `paranteze.in` → `paranteze.out`); create the input file next to the executable first.

## Concepts covered

classes and objects · access specifiers · constructors (default, parameterised, copy) · destructors · dynamic memory · static members · function and class templates · operator overloading · friend functions · inheritance · virtual functions and polymorphism · stacks, dynamic arrays, linked lists, hash tables · backtracking

## Tech

C++ · STL
