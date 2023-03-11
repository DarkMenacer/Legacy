# Movie Festival
## Program Info
- Platform/Source:-     CSES Sorting and Searching
- Date:-                17 January 2022    
- Type of Problem:-     Greedy, Sorting
- Status:-              Solved
#### Complexity:-       O(n*logn)
---
## Solution in brief
The problem follows the basic premise of 
"Choosing maximum events such that no event can be selected partially within a given set of overlapping events".\
First, a vector with pair of ints, 'movies' is initialised and input is taken in the format <end_time, begin_time>
(so as to sort movies based on end_time).

Movies are selected on the principle that next movie should end as soon as possible.

## Sample to understand the solution

### Input
5\
1 6\
3 4\
4 7\
6 10\
7 9

### Output
3

### Explanation

Sorting based on end_time:\
1: 3 4\
2: 1 6\
3: 4 7\
4: 7 9\
5: 6 10

Clearly, the combination to watch most movies is 1 -> 3 -> 4


---