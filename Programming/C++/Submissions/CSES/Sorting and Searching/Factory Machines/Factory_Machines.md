# Factory Machines
## Program Info
- Platform/Source:-     CSES Sorting and Searching 
- Date:-                ~~21 February 2022~~ 3 March 2023
- Type of Problem:-     Binary Search
- Status:-              Solved
#### Complexity:-       O(n*logn)
---
## Solution in brief
Let the minimum time required be x
Therefore x should satisfy following conditions:

$$\displaystyle \sum_1^n \frac{x}{k_i} \geq t \text{ and } \displaystyle \sum_1^n \frac{x-1}{k_i} \leq t$$ 

i.e. at time x, at least t products should be produced and at time x-1, less than t products should be produced

Therefore we can find such an x using binary search on all natural numbers inside the bound


## Sample to understand the solution

### Input
3 7\
3 2 5

### Output
8

### Explanation

Initially high is set to $10^{19}$ and low to 1. Let p represent the no. of products that were formed for that particular value of x. Then using binary search to find suitable x:

high: 10000000000000000000 low: 1 x: 5000000000000000000 p: 5166666666666666666\
high: 5000000000000000000 low: 1 x: 2500000000000000000 p: 2583333333333333333\
high: 2500000000000000000 low: 1 x: 1250000000000000000 p: 1291666666666666666\
high: 1250000000000000000 low: 1 x: 625000000000000000 p: 645833333333333333\
high: 625000000000000000 low: 1 x: 312500000000000000 p: 322916666666666666\
high: 312500000000000000 low: 1 x: 156250000000000000 p: 161458333333333333\
high: 156250000000000000 low: 1 x: 78125000000000000 p: 80729166666666666\
high: 78125000000000000 low: 1 x: 39062500000000000 p: 40364583333333333\
....about 50 lines later\
high: 35 low: 1 x: 18 p: 18\
high: 18 low: 1 x: 9 p: 8\
high: 9 low: 1 x: 5 p: 4\
high: 9 low: 5 x: 7 p: 6\
high: 9 low: 7 x: 8 p: 7

---