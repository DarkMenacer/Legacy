# Number Spiral
## Program Info
- Platform/Source:- CSES Introductory Problems
- Date:- 26 May 2021
- Type of Problem:- Identifying pattern and generalising
- Status:- Solved
#### Complexity:- O(1)
---
## Solution in brief
Through observation it is realised that $\text{grid}[x][y]$ depends on x and y

There are 4 total cases; $\text{grid}[x][y] =$
1. $x^2 - y + 1$ if $x ≥ y\text{ and } x\text{ is odd}$
2. $(x-1)^2 + y$ if $x ≥ y\text{ and } x\text{ is even}$
3. $y^2 - x + 1$ if $y ≥ x\text{ and } y\text{ is odd}$
4. $(y-1)^2 + x$ if $y ≥ x\text{ and } y\text{ is even}$

## Sample to understand the solution

### Input
3\
2 3\
1 1\
4 2

### Output
8\
1\
15

### Explanation
Using the formulae mentioned in "Solution in brief"
---