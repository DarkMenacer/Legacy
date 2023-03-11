# Subarray Sums II
## Program Info
- Platform/Source:-     CSES Sorting and Searching 
- Date:-                5 April 2022
- Type of Problem:-     Prefix Sums, Searching using Maps
- Status:-              Solved
#### Complexity:-       O(n*logn)
---
## Solution in brief
The concept used here is of Prefix Sums.\
In a Prefix Sum array, sum of the elements of the array uptil that index is stored. Therefore sum of any subarray can be calculated in constant time.

$$\text{Sum}[i,j] = \text{prefixSum}[j] - \text{prefixSum}[i-1]$$

Additionally a dummy value is added at the beginning with value 0, so that $\text{Sum}[1,i] = \text{sum of array uptil index i}$

Now, $x$ needs to be found out such that $x = \text{prefixSum}[j] - \text{prefixSum}[i-1] \text{ } \forall \text{ } j > i$


Here sum of subarray, x is already known, therefore for every element $a[j]$, we first find Prefix Sum till j and then try to find an i such that 
$$\text{prefixSum}[i-1] = \text{prefixSum}[j] - x$$

Therefore the answer is number of times such an i was found.

A map is used here as a data structure there can be multiple such 'i's for which above equation is true (and each such i gives a valid answer)./
Therefore, a map is used with key being prefix_sum[i] and value being no. of times prefix_sum[i] has occured.

## Sample to understand the solution

### Input
7 5\
0 -3 6 2 -8 5 3

### Output
6

### Explanation

Using 1-based indexing (and 0 for dummy value added)

| Input      |     | 0   | -3  | 6   | 2   | -8  | 5   | 3   |
| ---------- | --- | --- | --- | --- | --- | --- | --- | --- |
| Prefix Sum | 0   | 0   | -3  | 3   | 5   | -3  | 2   | 5   |

At each index, prefix sum is calculated as shown and an appropriate 'i' is tried to found out, i.e

At index 2,\
    $\text{prefixSum}[2] = -3$, therefore we need such an $i (< 2)$ for which $\text{prefixSum}[i] = 8$, but such an i does not exist.

But at index 6,\
    $\text{prefixSum}[6] = 2$, therefore we need such an $i (< 6)$ for which $\text{prefixSum}[i] = 3$, and at $i = 2$ satisfies this condition, therefore answer is incremented once

At index 3,\
    $\text{prefixSum}[4] = 5$, therefore there are 2 $i$s, $i=1 \text{ } \& \text{ } i=0$ satisfy the condition, therefore answer is incremented by 2.


Therefore answer is incremented on following places\
    At $j=4$, twice, as Prefix Sum = 5 and there are two '0's (including dummy)\  
    At $j=7$, same as with j=4\
    At $j=6$, twice, Prefix Sum = 2 and there are two '-3's\
    Therefore answer = 2 + 2 + 2 = 6 


---