# Subarray Distinct Values
## Program Info
- Platform/Source:-     CSES Sorting and Searching
- Date:-                12 April 2022
- Type of Problem:-     Two pointer, Map, Searching
- Status:-              Solved
#### Complexity:-       O(n*logn)
---
## Solution in brief

Input is taken in vector 'integers'. Two pointers, $i$ and $j$ are used.\
The basic idea is that a map is used to keep track of no. of distinct values in the subarray bounded by $i$ and $j$,
key representing the integer and value representing the no. of occurences.

Till the size of the map is less-than-or-equal-to $k$, $j$ is kept on incremented and values are kept on added in the map.\
When the size of the map becomes larger than $k$, $\text{integers}[i]$ is decremented (and removed if 0 occurences), till $\text{map.size()} \leq k$.

Now, during this decrementation, answer is added with the no. of subarrays starting strictly from the $i^{th}$ index only.
This can be given by the difference between "total subarrays from $i$ to $j$" and "total subarrays from $i+1$ to $j$", i.e.
$$[(j-i)*\frac{(j-i-1)}{2}] - [(j-i-1)*\frac{(j-i-2)}{2}]$$ 
$$ = j-i-1$$

Therefore $\text{answer} = \text{answer} + (j-i-1)$

When $j$ reaches end of the integers, there is no need to subtract 'total subarrays from $i+1$ to $j$',
(as no new element is going to be added further), 

Therefore $\text{answer} = \text{answer} + (j-i)*\frac{j-i-1}{2}$
And then answer is printed out.

## Sample to understand the solution

### Input
6 3\
1 5 3 1 2 4

### Output
16

### Explanation

1 5 3 1 2 4\
i  j

i: 0 j: 1 map: 1(1)\
i: 0 j: 2 map: 1(1) 5(1)\
i: 0 j: 3 map: 1(1) 3(1) 5(1)\
i: 0 j: 4 map: 1(2) 3(1) 5(1)\
i: 0 j: 5 map: 1(2) 2(1) 3(1) 5(1)\
1 decremented\
answer: 4\
5 decremented 5 erased\
answer: 7\
i: 2 j: 6 distinct: 1(1) 2(1) 3(1) 4(1)\
3 decremented 3 erased\
answer: 10\
i: 3 j: 7 distinct: 0(1) 1(1) 2(1) 4(1)\
answer: 16


---