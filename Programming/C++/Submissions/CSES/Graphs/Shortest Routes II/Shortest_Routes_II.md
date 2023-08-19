# Shortest Routes II
## Program Info
- Platform/Source:- CSES Graphs 
- Date:- 12 Aug 2023
- Type of Problem:- Shortest paths
- Status:- Solved
#### Complexity:- O($n^3$) 
---
## Solution in brief

This is a classic graph problem. As the constraints allow for a $n^3$ algorithm, the best approach here is that of [Floyd-Warshall Algorithm](https://github.com/DarkMenacer/Legacy/tree/main/Programming/Classic%20Algorithms/Floyd%20Warshall/Floyd_Warshall.md)

## Sample to understand the solution

### Input
6 8 4\
1 2 2\
1 3 5\
2 4 1\
2 5 1\
2 6 3\
4 6 3\
4 3 1\
6 5 1\
2 3\
4 6\
3 5\
1 6

### Output
2\
3\
3\
4

### Explanation

Initial graph
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

