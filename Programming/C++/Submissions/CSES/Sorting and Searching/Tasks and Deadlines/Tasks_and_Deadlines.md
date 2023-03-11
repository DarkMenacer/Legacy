# Task and Deadlines    
## Program Info
- Platform/Source:-     CSES Sorting and Searching
- Date:-                22 February 2022
- Type of Problem:-     Greedy
- Status:-              Solved
#### Complexity:-       O(n*logn)
---
## Solution in brief

Firstly all tasks are sorted(increasing order) according to their durations and then they are executed in that order.\
This approach works and can be proved because:-

Let taskᵢ end at xᵢ, then the answer will be ∑(dᵢ - xᵢ), now dᵢs are constant (i.e we can't affect them).\
Therefore now the answer is ∑dᵢ - ∑xᵢ, so the objective naturally is to minimise ∑xᵢ\
That implies tasks should finish as soon as possible. Hence the greedy approach works

## Sample to understand the solution

### Input
4\
4 2\
3 5\
2 7\
4 5

### Output
-10

### Explanation
Sorted order:\
2 7\
3 5\
4 2\
4 5\
and this is the order

---