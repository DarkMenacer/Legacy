# Static Range Sum Queries
## Program Info
- Platform/Source:- CSES Range Queries
- Date:- 30 October 2022
- Type of Problem:- Range Queries, Prefix Sums
- Status:- Solved
#### Complexity:- O(n) 
---
## Solution in brief
To process the sum of elements in the given range, a new data structure of type array,
called $\text{Prefix Sum}$  to avoid developing a $O(nq)$ solution and solve it in $O(q)$

In $\text{Prefix Sum}$ each element contains the sum of values of the elements in the original array,
$\text{values}[1 \ldots n]$ uptil that index,i.e.

$$\text{PrefixSum}[x] = \displaystyle\sum_{i=1}^{x} \text{values}[i]$$

Therefore to find the sum of elements between indices $a$ & $b$
$$\text{sum}(a,b) = \text{PrefixSum}[b] - \text{PrefixSum}[a-1]$$

## Sample to understand the solution

### Input
8 4\
3 2 4 5 1 1 5 3\
2 4\
5 6\
1 8\
3 3

### Output
11\
2\
24\
4

### Explanation

| Index      | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   |
| ---------- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| values     |  -  | 3   | 2   | 4   | 5   | 1   | 1   | 5   | 3   |
| prefix sum | 0   | 3   | 5   | 9   | 14  | 15  | 16  | 21  | 24  |

$\text{sum}(2,4) = \text{prefixSum}[4] - \text{prefixSum}[2-1] = 14 - 3 = 11$
$\text{sum}(5,6) = \text{prefixSum}[6] - \text{prefixSum}[5-1] = 16 - 14 = 2$
$\text{sum}(1,8) = \text{prefixSum}[8] - \text{prefixSum}[1-1] = 24 - 0 = 24$
$\text{sum}(3,3) = \text{prefixSum}[3] - \text{prefixSum}[3-1] = 9 - 5 = 4$

---