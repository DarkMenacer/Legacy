# Coin Combinations I
## Program Info
- Platform/Source:-     CSES Dynamic Programming
- Date:-                9th July 2022
- Type of Problem:-     Traditional Dynamic Programming
- Status:-              Solved
#### Complexity:-       O(n²)
---
## Solution in brief
Basically, all total possible ways of reaching 'x' need to be found out
Therefore 
$$\text{solve}(x) = ∑_{i} \text{solve}(x - cᵢ)$$

If x is smaller than all of coins, then there are 0 ways to reach x, hence the calculation is started from the least value coin

## Sample to understand the solution

### Input
3 9\
2 3 5

### Output
8

### Explanation

Memoise Table:
| No. of ways  | 1   | 0   | 1   | 1   | 1   | 3   | 2   | 5   | 6   | 8   |
| ------------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Sum of coins | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 


---