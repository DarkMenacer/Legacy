# Increasing Array
## Program Info
- Platform/Source:- CSES Introductory Problems
- Date:- 25 May 2021
- Type of Problem:- Basic, Greedy
- Status:- Solved
#### Complexity:- O(n)
---
## Solution in brief
Each element must be at least as large as before, so if the succeeding element is smaller than previous element
then just increase that element to be as big as previous one.

## Sample to understand the solution

### Input
5\
3 2 5 1 7

### Output
5

### Explanation
3 3 5 5 7\
0 +1 0 +4 0

Total = 5

---