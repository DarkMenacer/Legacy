# Array Division
## Program Info
- Platform/Source:-     CSES Sorting and Searching
- Date:-                25 May 2022
- Type of Problem:-     Binary Search
- Status:-              Solved
#### Complexity:-       O(n*logn)
---
## Solution in brief
Few points which are observed:
1. For an arbitrarily large value of k as well, the answer will atleast be as big as the max value of the array
2. For k=1, the answer will be the sum of all of the elements in the array
   
Therefore answer lies between max and sum of the array.
Now, let the answer be $\text{ans}$

That implies all the subarray sums $\leq \text{ans}$\
Moreoever there exists atleast one subarray with sum $> \text{ans} - 1$\
Therefore we use binary search to find such an $\text{ans}$.

We use the fact that if the array uses more partitions than what is allowed (k), 
then there is a subarray with sum greater than current choice of $\text{ans}$.

Hence $\text{ans}$ will have the property that, number of partitions, when $\text{ans}$ is max_allowed_subarray_sum = k
and no. of partitions when $\text{ans}-1$ is the max_allowed_subarray_sum > k.


## Sample to understand the solution

### Input
5 3\
2 7 4 3 4

### Output
9

### Explanation

for ans = 7 ====    2 | 7 | 4 3 | 4     => 4 partitions\
for ans = 12 ====  2 7 | 4 3 4        => 2 partitions\
for ans = 10 ====  2 7 | 4 3 | 4      => 3 partitions\
for ans = 9 ====   2 7 | 4 3 | 4       => 3 partitions\
for ans = 8 ====    2 | 7 | 4 3 | 4    => 4 partitions

Therefore 9 is the answer.

---