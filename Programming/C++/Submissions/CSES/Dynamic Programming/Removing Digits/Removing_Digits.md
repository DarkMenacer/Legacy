# Removing Digits
## Program Info
- Platform/Source:-     CSES Dynamic Programming 
- Date:-                14 August 2022
- Type of Problem:-     Optimising using memoisation
- Status:-              Solved
#### Complexity:-       O(n*(logn)²)
---
## Solution in brief

For each number x,
$$\text{memoize}[x] = \text{min}(\text{memoize}[x-d₁], \text{memoize}[x-d₂], ...) + 1$$
where d₁, d₂ are the digits in x

## Sample to understand the solution

### Input
13

### Output
3

### Explanation

14 = {1,4}\
$\text{memoize}[14] = \text{min}($\text{memoize}[13], $\text{memoize}[10]) + 1$\
$\text{memoize}[10] = \text{min}($\text{memoize}[9], $\text{memoize}[10]) + 1$\
$\text{memoize}[9] = 1$\
so $\text{memoize}[10] = 2$\
similarly $\text{memoize}[13] = 3$

---