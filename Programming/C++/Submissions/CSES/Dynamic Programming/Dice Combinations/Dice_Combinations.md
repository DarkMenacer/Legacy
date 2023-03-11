# Dice Combinations
## Program Info
- Platform/Source:- CSES Dynamic Programming 
- Date:- 25 June 2022
- Type of Problem:- Traditional Dynamic programming
- Status:- Solved
#### Complexity:- O(n)
---
## Solution in brief
Basically, as total possible ways need to be counted\
For any input n, $solve(n) = \displaystyle\sum_{i=0}^{6} solve(n-i)$\
and base conditions are\
$solve(0) = 0$ and $solve(1) = 1$\
Note that for n = 2 to n = 6, there is an extra possibility as the die has a face corresponding to those numbers.

#### Bottom-up implementation
An array $memoize[0\ldots n]$ is initialised
and $memoize[0] = 1$ & $memoize[1] = 1$\
A variable $total$ is used to store the sum of no. of ways of achieving last 6 (and 6 only) numbers, i.e.
$total_{\text{at }p^{th}\text{ iteration}} = \displaystyle\sum_{i=0}^{6} memoize[p-i]$\
$p$ goes up to $n$ and the final answer is stored in $memoize[n]$

## Sample to understand the solution

### Input
8

### Output
125

### Explanation
$$\begin{aligned}
solve(8)&= solve(8-1) + solve(8-2) + solve(8-3) + solve(8-4) + solve(8-5) + solve(8-6)\\
        &= solve(7) + solve(6) + solve(5) + solve(4) + solve(3) + solve(2)\\
        &= \ldots \\
        &= 125\end{aligned}$$
        

---