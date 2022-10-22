# Book Shop
## Program Info
- Platform/Source:- CSES Dynamic Programming
- Date:- 8 September 2022
- Type of Problem:- 0/1 Knapsack Problem
- Status:- Solved
#### Complexity:- O(n²)
---
## Solution in brief
This is a classic 0/1 Knapsack Problem.

In the naive approach, for every book, we can either choose it or reject it, hence 2 possiblities.
So the solution goes $O(2^n)$ which is unacceptable. To optimise it, we use Dynamic Programming.

Let $b_i$ represent $i^{th}$ book and pr and pg represent price and pages.
Starting making the recursion tree with 0 books, it is realised that picking $b_1$ first and $b_2$ second
will evaluate to give same answer as picking picking $b_2$ first and $b_1$ second.
Hence books are traversed in order (i.e. once a book is dropped it is never considered again).
For each node of the tree, the max of values of pages stored by its children is stored.
The tree bottoms out using the available budget, i.e. if no book can be bought further, the node is a leaf node.

This was the bottom-up approach. To implement this using top-down approach

Memoization table is constructed with budget (starting from 0 to total budget) as columns and specific book index as rows.
For entry of the table $memoize[i][j]$ represents max pages that can be bought using $j$ budget and using (first) $i$ books (uptil $i$ index).
So 
$$memoize[i][j] = max(memoize[i-1][j], pages[i] + memoize[i-1][j-price[i-1]]) $$

Here the first term of max, represents the case where the new added book is not chosen and
the second term represents the case where it is chosen (additionally if there is any more books that can be bought using leftover).


## Sample to understand the solution

### Input
4 10

4 8 5 3

5 12 8 1

### Output
13

### Explanation
Most important part:- indexing of books
| Index | Pages |
| ----- | ----- |
| 1     | 1     |
| 2     | 5     |
| 3     | 8     |
| 4     | 12    | 

#### Recursion Tree
![Recursion_tree.png](https://github.com/DarkMenacer/Legacy/blob/main/Programming/C%2B%2B/Submissions/CSES/Dynamic%20Programming/Book%20Shop/Recursion_tree.png)

#### Memoization Table

|     | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 1   | 1   | 1   | 1   | 1   | 1   | 1   | 1   |
| 2   | 0   | 0   | 0   | 1   | 5   | 5   | 5   | 6   | 6   | 6   | 6   |
| 3   | 0   | 0   | 0   | 1   | 5   | 8   | 8   | 8   | 9   | 13  | 13  |
| 4   | 0   | 0   | 0   | 1   | 5   | 8   | 8   | 8   | 12  | 13  | 13  | 

---