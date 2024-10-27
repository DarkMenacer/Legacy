# Floyd Warshall Algorithm
## Algorithm Info
- History (in a line):- An example of dynamic programming, and was published in its currently recognized form by Robert Floyd in 1962
- Date implemented (by me):- 12 August 2023
- Type of problem it solves: Process shortest path queries from any vertex to any other vertex
- Alternatives:- [Dijstrka](https://github.com/DarkMenacer/Legacy/tree/main/Programming/Classic%20Algorithms/Dijstrka/Dijstrka.md), [Bellman Ford](https://github.com/DarkMenacer/Legacy/tree/main/Programming/Classic%20Algorithms/Bellman%20Ford/Bellman_Ford.md)
- Complexity:- $O(n^3)$

---
## Explanation of algorithm

The algorithm simply works on the principle of choosing each vertex and trying to minimize the distances of all it's neighbours.

The graph is stored in an adjacency matrix and initially all distances are set as infinity. Then as edges are stored, the adjacency matrix is updated with the weights of the edges and indices representing the vertices the edge connects.
After all edges are stored, the algorithm starts consecutive rounds. On each round, the algorithm selects a new node that can act as an intermediate node in paths from now on, and distances are reduced using this node.\
The algorithm completes when all nodes have been selected once.\
The adjacency matrix contains minimum distances from each vertex to all other vertices (including itself).


## Sample to understand the solution

### I/O Format

#### Input
n m q\
$a_1$ $b_1$ $c_1$\
...\
$a_m$ $b_m$ $c_m$\
$e_1$ $f_1$\
...\
$e_q$ $f_q$

n = no. of vertices\
m = no. of edges\
q = no. of queries to process\
all subsequent lines are the undirected edges {a, b, c} where a, b are the vertices connected by the edge and c is the weight\
The lines after these represent the queries {e, f} where shortest distance between vertices e and f needs to be found out.

#### Output
$d_1$\
...\
$d_q$

where $d_i$ is the distance between $e_i$ and $f_i$

### Sample Case

#### Input
6 8 4\
1 2 2\
1 3 5\
2 4 1\
2 5 1\
2 6 3\
3 4 1\
4 6 3\
5 6 1\
2 3\
4 6\
3 5\
1 6

#### Output
2\
3\
3\
4

#### Explanation

```mermaid
flowchart TD
	1 --2-- 2
	2 --1-- 4
	2 --1-- 5
	2 --3-- 6
	4 --3-- 6
	4 --1-- 3
	1 --5-- 3
	6 --1-- 5
```

---
