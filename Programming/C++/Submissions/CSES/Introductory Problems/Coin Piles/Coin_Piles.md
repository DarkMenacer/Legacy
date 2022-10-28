# Coin Piles
## Program Info
- Platform/Source:- CSES Introductory Problems
- Date:- 31 May 2021
- Type of Problem:- Math
- Status:- Solved
#### Complexity:- O(1) 
---
## Solution in brief
Firstly, if either of $x$ or $y$ are more than twice of other, then it is not possible
to empty both piles together, i.e. there will always be some left over.

Now, let $a = 2x + y$ then $b = x + 2y$

These 2 equations can be manipulated and i.e.\
$a + b = 3x + 3y$ or $a - 2b = -3y$,  i.e. $a + b$ or $a - 2b$ should always be divisible by 3

This gives the required criteria

## Sample to understand the solution

### Input
3\
2 1\
2 2\
3 3

### Output
YES\
NO\
YES

### Explanation
1. $2 - 2(1) = 0$ which is divisible by 3
2. $2 - 2(2) = -2$ which is not divisible by 3
3. $3 - 2(3) = -3$ which is divisible by 3
---