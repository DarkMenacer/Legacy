# Maximum Subarray Sum
## Program Info
- Platform/Source:-     CSES Sorting and Searching
- Date:-                20 February 2022
- Type of Problem:-     Greedy
- Status:-              Solved
#### Complexity:-       O(n)
---
## Solution in brief

The key to solve this problem is the realisation that the exact problem statement can be coded so that the answer is found incrementally for each index of the array.

Maximum sum among (contiguous) subarray needs to be found. Hence firstly sum of contiguous elements is started to be stored as the array is traversed.

Now, when the element present in the array is negative, the sum drops. If this negative value is too large in magnitude, then the sum might also become negative.\
Then the next value comes in and if the value is greater than all of the previous sum of the values, it makes sense to discard the previous sum and start afresh with new beginning.

Therefore mathematically
$$\text{maxSum}_i = \text{max(maxSum}_{i-1} + \text{values}[i], \text{values}[i]\text{) } \forall \text{ } i \text{ } \epsilon \text{ } [1, \text{ size(values)}]  $$


## Sample to understand the solution

### Input
8\
-1 3 -2 5 3 -5 2 2

### Output
9

### Explanation

$\text{maxSum}_1 = -1$\
$\text{maxSum}_2 = \text{max}(-1 + 3, 3) = 3$\
$\text{maxSum}_3 = \text{max}(3 + -2, -2) = 1$\
...

---