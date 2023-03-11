# Subarray Sums I
## Program Info
- Platform/Source:-     CSES Sorting and Searching 
- Date:-                20 March 2022
- Type of Problem:-     Sliding Window, Searching
- Status:-              Solved
#### Complexity:-       O(n)
---
## Solution in brief

A variable sum is initialised to zero. Two pointers, i and j are initialised at a.begin(), which form a window.

While sum <= x, the value pointed by j is added and j is incremented.\
When (and if) sum becomes greater than x, then value pointed by i is subtracted and i is incremented, effectively reducing the subarray (window).


## Sample to understand the solution

### Input
5 7\
2 4 1 2 7

### Output
3

### Explanation
j is incremented until these points are reached, here i is incremented.\
i: 0 j: 3 sum: 7\
i: 1 j: 4 sum: 7\
i: 4 j: 5 sum: 7

---