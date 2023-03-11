# Nearest Smaller Value
## Program Info
- Platform/Source:-     CSES Sorting and Searching
- Date:-                18 March 2022
- Type of Problem:-     Stack, Adaptive Decremental
- Status:-              Solved
#### Complexity:-       O(n)
---
## Solution in brief
The algorithm works on the principle that if a subsequent number is smaller, than the earlier number (larger one) can never be the answer.
Therefore a stack 'low' is used. Stack because we need nearest from left.\
Numbers are taken input one-by-one and if the next number is smaller than stack top, then stack is popped.

This is done until our current input is larger than all elements in the stack.\
Then the stack top's index is printed. 


## Sample to understand the solution

### Input
7\
1 3 5 7 6 4 2

### Output
0 1 2 3 3 2 1

### Explanation
Up until when input is 7, all subsquent elements are bigger hence stack keeps growing.\
After 7, during 6, 7 is popped and <6,5> is pushed and index of stack top, i.e. index of 5 is printed.\
Then as each subsquent element is smaller, the stack keeps decreasing in size. 

---