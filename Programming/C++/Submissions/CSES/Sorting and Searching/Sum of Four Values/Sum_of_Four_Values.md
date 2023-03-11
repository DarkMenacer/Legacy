# Sum of Four Values
## Program Info
- Platform/Source:-     CSES Sorting and Searching 
- Date:-                26 February 2022
- Type of Problem:-     Complete Search, Brute Force
- Status:-              Solved
#### Complexity:-       O(n²log(n))
---
## Solution in brief
Firstly input is taken in a vector of pairs, the pair being the integer and its index.\
The vector is sorted according to first (preserving the initial indexes in the second).\
Then for every 2 elements in the vector, other 2 are tried to found out using binary search.


## Sample to understand the solution

### Input
8 10\
4 4 2 3 1 3 1 2

### Output
7 1 5 2

### Explanation

Sorted input:
| value | 1   | 1   | 2   | 2   | 3   | 3   | 4   | 4   |
| ----- | --- | --- | --- | --- | --- | --- | --- | --- |
| index | 5   | 7   | 3   | 8   | 4   | 6   | 1   | 2   |'

Now for (1, 1), values are tried to be found out from 2 to 4 which can give sum as 10-1-1.


---