# Minimizing Coins
## Program Info
- Platform/Source:-     CSES Dynamic Programming 
- Date:-                1 July 2022
- Type of Problem:-     Optimizing using memoization
- Status:-              Solved
#### Complexity:-       O(n²)
---
## Solution in brief
For any sum 'x', the minimum coins needed can be calculated by using following recursion
$$\text{solve}(x) = \text{min}(\text{solve}(x-c₁), \text{solve}(x-c₂),...\text{solve}(x-cₙ))$$

Further, this is converted into a bottom-up approach and the question is solved.


## Sample to understand the solution

### Input
3 14\
1 5 7

### Output
2

### Explanation

Memoize Table:

| Sum          | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 11  | 12  | 13  | 14  |
| ------------ | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Coins Needed | 0   | 1   | 2   | 3   | 4   | 1   | 2   | 1   | 2   | 3   | 2   | 3   | 2   | 3   | 2   | 


---