# Two Sets II
## Program Info
- Platform/Source:- CSES Dynamic Programming
- Date:- 22 October 2022
- Type of Problem:- 0/1 Knapsack problem, Dynamic Programming
- Status:- Solved
#### Complexity:- O(---??) 
---
## Solution in brief
The key is to realise that the sum of each set will be half of $\frac{n(n+1)}{2}$

So $\frac{n(n+1)}{2}$ should be even, else answer is 0.

Now sum of each set will be $\frac{n(n+1)}{4}$, hence this is just a 0/1 Knapsack problem 
where we need to find the number of ways to constructing sum $\frac{n(n+1)}{4}$ using $[1,n]$

In the naive approach, for number, we can either choose it or reject it, hence 2 possiblities.
So the solution goes $O(2^n)$ which is unacceptable.

Let $n_i$ represent $i^{th}$ number and $\frac{n(n+1)}{4} =$ set sum.
Starting making the recursion tree with sum 0, it is realised that picking $n_1$ first and $n_2$ second
will evaluate to give same answer as picking picking $n_2$ first and $n_1$ second.
Hence numbers are traversed in order (i.e. once a number is dropped it is never considered again).
For each iteration when a new number is considered, the number is added to each existing node of the recursion tree, thus forming double the number of nodes as before.
Finally the number of nodes with value $\frac{n(n+1)}{4}$ are counted and that is the final answer.

This was the bottom-up approach. To implement this using top-down approach

Memoization table is constructed with rows as numbers and columns as the sum.
$\text{memoize}[i][j]$ represents the number of ways of constructing sum $j$ using $i$ (first) numbers.
With base criteria $\text{memoize}[0][0] = 0$
$$\text{memoize}[i][j] = \text{memoize}[i-1][j] + \text{memoize}[i-1][j-i]$$

Now for the final answer, if $\text{memoize}[n][\text{set sum}]$ is considered then all the sets are counted exactly twice
but if $\text{memoize}[n][\text{set sum} -1]$ is considered then all sets are counted exactly once, (as n has necessarily been placed in other group).
Therefore the final answer is $\frac{\text{memoize}[n][\text{set sum}]}{2} = \text{memoize}[n][\text{set sum}-1]$

## Sample to understand the solution

### Input
7

### Output
4

### Explanation

Memoize Table:- 
|     | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 11  | 12  | 13  | 14  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0   | 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 1   | 1   | 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 2   | 1   | 1   | 1   | 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 3   | 1   | 1   | 1   | 2   | 1   | 1   | 1   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 4   | 1   | 1   | 1   | 2   | 2   | 2   | 2   | 2   | 1   | 1   | 1   | 0   | 0   | 0   | 0   |
| 5   | 1   | 1   | 1   | 2   | 2   | 3   | 3   | 3   | 3   | 3   | 3   | 2   | 2   | 1   | 1   |
| 6   | 1   | 1   | 1   | 2   | 2   | 3   | 4   | 4   | 4   | 5   | 5   | 5   | 5   | 4   |**4**| 
---