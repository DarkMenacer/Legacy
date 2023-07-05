# Round Trip
## Program Info
- Platform/Source:- CSES Graphs 
- Date:- 19 June 2023
- Type of Problem:- Cycle Detection and Printing
- Status:- Solved
#### Complexity:- O(n) 
---
## Solution in brief

The key to solve this problem is to realise that, if during a depth-first-search, such a child node is encountered which is already visited, then a cycle is present.\
Parent of each node is calculated prudently hence the path can be extracted if a cycle is found.

## Sample to understand the solution

### Input
4 4\
1 2\
2 3\
3 4\
1 4

### Output
5\
1 2 3 4 1

### Explanation
Starting a depth-first-search from 1, 4 is visited through it's parent 3 and 2 but it is again encountered as 1's neighbor hence the cycle is detected.

---
