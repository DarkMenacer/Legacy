# Stick Lengths
## Program Info
- Platform/Source:-     CSES Sorting and Searching
- Date:-                21 January 2022
- Type of Problem:-     Measures of central tendency(median) 
- Status:-              Solved
#### Complexity:-       O(n*logn)
---
## Solution in brief

Input is taken as vector and is sorted. The vector is sorted.\
Median is found. (n-1)/2th for odd, average of n/2th and (n/2-1)th for even.\
Median is subtracted from each value in the vector and the values are added up as the answer.

## Sample to understand the solution

### Input
2 2 4 6 7

### Output
9

### Explanation

Median: 4\
Therefore answer = (4-2) + (4-2) + (4-4) + (6-4) + (7-4) = 9

---