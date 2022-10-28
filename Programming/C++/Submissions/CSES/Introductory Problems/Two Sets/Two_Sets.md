# Two Sets
## Program Info
- Platform/Source:- CSES Introductory Problems
- Date:- 26 May 2021
- Type of Problem:- Brute Force
- Status:- Solved
#### Complexity:- O(n) 
---
## Solution in brief
Through observation it is realised that for any number of the form 
1. 4k, there can be n/2 pairs whose sums are equal i.e. (1,n), (2,n-1)...n/2 pairs, 
   these are equally divided into 2 sets (as (n/2)/2 is a whole number)
2. 4k+3, can be converted to 4k because 1+2 = 3 and these three numbers are shaved off, 
   therefore the pairs are (4,n),(5,n-1)...(n-2)/2 pairs
3. As the sum of 4k+1, and 4k+2 is always odd, they can never be divided into 2 equal sets

The printing of values is trivial.

## Sample to understand the solution

### 1. Input
8

### Output
YES

4

1 2 7 8 

4

3 4 5 6 

### 2. Input
7

### Output
YES

4

1 2 4 7 

3

3 5 6 

### 3. Input
9

### Output
NO

### Explanation
1. (1,8), (2,7) in set 1 and (3,6), (4,5) in set 2
2. (1,2), (4,7) in set 1 and (3), (5,6) in set 2 

---