# Trailing Zeros
## Program Info
- Platform/Source:- CSES Introductory Problems 
- Date:- 30 May 2021
- Type of Problem:- Math, Number Theory
- Status:- Solved
#### Complexity:- O(log(n)) 
---
## Solution in brief

## Sample to understand the solution
A number has $x$ number of zeros at the end $\implies$ it is divisible by 10, $x$ number of times.

Therefore we need to find the number of factors of 10 in that number
Now, number of factors of 10 are number of factors of 5 and 2 paired together and\
since $\text{number of factors of }5 < \text{number of factors of }2$
, the number of factors of 5 needs to be found out.

This can be done easily by just counting them, i.e.
initially $\text{factors}=0$
and $\text{factors} = \text{factors} + \text{num}/5$ till $\text{num}/5 > 1$

### Input
20

### Output
4

### Explanation
$\frac{20}{5} = 4$

---