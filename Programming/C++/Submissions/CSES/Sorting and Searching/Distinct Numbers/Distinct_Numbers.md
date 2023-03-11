# Distinct Numbers
## Program Info
- Platform/Source:- CSES Sorting and Searching 
- Date:- 2 Nov 2021
- Type of Problem:- Searching
- Status:- Solved
#### Complexity:- O(n)
---
## Solution in brief
Use the basic property of sets. \
find() function tries to search for the element.
If not present, points to end(), meaning number is unique. Answer++ and number added to set.

## Sample to understand the solution

### Input
5\
2 3 2 2 3

### Output
2

### Explanation
Initially set: {} \
Reads 2 set: {2}\
Reads 3 set: {2, 3}\
Reads 2 set: {2, 3}\
Reads 2 set: {2, 3}\
Reads 3 set: {2, 3}


---