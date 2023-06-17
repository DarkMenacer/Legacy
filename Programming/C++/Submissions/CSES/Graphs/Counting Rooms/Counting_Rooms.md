# Counting Rooms
## Program Info
- Platform/Source:- CSES Graphs 
- Date:-    29 April 2023
- Type of Problem:- Depth-First-Search
- Status:- Solved
#### Complexity:- O(n) 
---
## Solution in brief

The solution can be approached like how basic depth-first-search is implemented. 

Whenever a '.' is encountered, a new function is triggered which searches the entire room and marks all '.' in that room as visited.
No. of rooms are incremented when all the '.' of the room have been visited.\
For all '.' which are already visited, this function is not triggered, hence they do not contribute to increase in no. of rooms.

## Sample to understand the solution

### Input
5 5
#####
##..#
##..#
#.###
...##

### Output
2

### Explanation

The first '.' is encountered at position [2,3]. Hence the function is triggered and it marks all the 4 '.' in the room and no. of rooms is set to 1.\
The next '.' for which the function is triggered is [4,2] as it was not the part of earlier room and the fucntion marks the rest 4 points as visited, incrementing answer to 2.


---
