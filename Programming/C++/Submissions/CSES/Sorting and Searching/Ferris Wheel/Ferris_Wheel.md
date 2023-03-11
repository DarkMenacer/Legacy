# Ferris Wheel
## Program Info
- Platform/Source:- CSES Sorting and Searching
- Date:-    4 Jan 2022
- Type of Problem:- 2 Pointers, Sorting
- Status:- Solved
#### Complexity:- O(n) 
---
## Solution in brief
Input is taken into a vector 'input' and then sorted.\
1 iterator 'itr' is initialised at the begin() and 1 reverse iterator 'ritr' at rbegin().\
An integer 'answer' is initialised as input.size().

A while(true) loop is run and *itr + *ritr is checked.

1. If *itr + *ritr <= x, then answer is decremented (both can go in a single gondola) and both itr & ritr are incremented.
2. Else only ritr is incremented (hoping that the next element (or the previous one because reverse_itr)) goes with itr.

The loop breaks only in 3 cases, 
1. 2 iterators cross each other or
2. *itr becomes more than half of weight capacity
3. *ritr becomes less than half of weight capacity

## Sample to understand the solution

### Input
4 10\
7 2 3 9

### Output
3

### Explanation

Sorted: 2 3 7 9\
answer: 4

2[itr] 3 7 9[ritr]\
2+9 > 11, ritr++


2[itr] 3 7[ritr]\
2+7 < 10, answer--, ritr++, itr++


2 3[itr, ritr] 7 9\
break

---