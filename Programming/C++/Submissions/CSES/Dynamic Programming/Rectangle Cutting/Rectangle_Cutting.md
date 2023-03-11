# Name of the program
## Program Info
- Platform/Source:- CSES: Dynamic Programming
- Date:- 11 October 2022
- Type of Problem:- Dynamic Programming
- Status:- Solved
#### Complexity:- O(n³)
---
## Solution in brief
The first thing to observe is the constraints. Notice how 
$$a,b ≤ 500$$
This suggest that the solution could go upto O($n^3$)
Now that in mind, it can be observed that after every cut a new pair of rectangles are obtained which themselves need to be cut further
This makes it evident that dynamic programming paradigm can be used.

One naive approach that comes to mind is a greedy approach of always dividing the rectangle into largest possible square every time. This approach however fails when a and b are very close to each other
i.e. 7 x 6
(6x6) + (1x1) + (1x1) + (1x1) + (1x1) + (1x1) + (1x1) requires 6 cuts
vs
(3x3) + (3x3) + (4x4) + (2x2) + (2x2) requires 4 cuts

The only way to find the minimum is to check all possible cuts for given a and b, i.e
$$\text{solve}(a,b) = \text{min}(\text{solve}(a-1,b) + \text{solve}(1,b), \text{solve}(a-2,b) + \text{solve}(2,b)...) + 1$$
Not only about a but also about b, i.e.
$$\text{solve}(a,b) = \text{min}(\text{solve}(a,b-1) + \text{solve}(a,1), \text{solve}(a,b-1) + \text{solve}(a,2)...) + 1$$
with base critera 
$$\text{solve}(i,i) = 0 \text{ }\forall \text{ i}$$ 
That is why the solution needs cubic time.

For top-down implementation, memoization table is created with a columns and b rows.
Element $a_{ij}$ represents the minimum no. of cuts required for a i x j rectangle.
$$\text{memoize}[i][j] = \text{min}(\text{memoize}[i-k][j]+\text{memoize}[k][j], \text{memoize}[i][j-k] + \text{memoize}[i][k]) + 1 \text{ } \forall \text{ k}$$

## Sample to understand the solution
### Input
7 6

### Output
4

### Explanation
$\text{memoize}[7][6] = \text{min}(\text{memoize}[6][6]+\text{memoize}[1][6],...,\text{memoize}[4][6]+[3][6]...) + 1$

$\text{memoize}[6][6] = 0 \text{ but } \text{memoize}[1][6] = 5 \text{ whereas } \text{memoize}[4][6] = 2 \text{ and } \text{memoize}[3][6] = 1$

Therefore $\text{memoize}[7][6] = 4$.

---