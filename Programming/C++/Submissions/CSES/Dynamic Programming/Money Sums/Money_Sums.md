# Money Sums
## Program Info
- Platform/Source:- CSES
- Date:- 12 October 2022
- Type of Problem:- Dynamic Programming
- Status:- Solved
#### Complexity:- O(n²)
---
## Solution in brief
For each coin, we can either pick it or leave it, hence the total possible sums will be 2ⁿ.
But this is a naive approach.

A clever approach involves noticing that when the search tree is constructed, many cases are repeated.
The trick to avoid this redundancy is to process the coins in order, i.e. once a coin is dropped it won't be picked again.

So, a boolean array is constructed, initially all 0 and for every coin, that index is set to true which is possible to form using the coin.
That is, if current index is possible then so is the sum, current index + next coin.

## Sample to understand the solution

### Input
4

4 2 5 2

### Output
9

2 4 5 6 7 8 9 11 13

### Explanation
possible |0 0 1 0 1 1 1 1 1 1  0  1  0 1

____sum|0 1 2 3 4 5 6 7 8 9 10 11 12 13

---