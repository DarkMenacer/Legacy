# Grid Paths
## Program Info
- Platform/Source:-     CSES Dynamic Programming 
- Date:-                14 August 2022
- Type of Problem:-     Traditional Dynamic Programming
- Status:-              Solved
#### Complexity:-       O(n³)
---
## Solution in brief

There are only 2 ways to visit a square, from top or from the left.
Therefore 
$$\text{no. of ways of visit grid}[x][y] = \text{no. of ways of visit grid}[x-1][y] + \text{no. of ways of visit grid}[x][y-1]$$
Now using memoization and safeguarding boundary cases, the answer for the bottom left square is obtained.

## Sample to understand the solution

### Input
4\
....\
.*..\
...*\
*...

### Output
3

### Explanation

Memoization table:
|     | 1   | 2   | 3   | 4   |
| --- | --- | --- | --- | --- |
| 1   | 1   | 1   | 1   | 1   |
| 2   | 1   | 0   | 1   | 2   |
| 3   | 1   | 1   | 2   | 0   |
| 4   | 0   | 1   | 3   | 3   | 

---