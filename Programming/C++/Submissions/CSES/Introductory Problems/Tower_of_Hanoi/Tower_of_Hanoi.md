# Tower of Hanoi
## Program Info
- Platform/Source:- CSES Introductory
- Date:- 25 June 2021
- Type of Problem:- Complete Search
- Status:- Solved
#### Complexity:- O(2ⁿ) 
---
## Solution in brief
The key here is to realise following patterns
1. To form a solution for $n = x$, first a solution for $x = x-1$ needs to be formed at the intermediate (2nd) tower.
2. If there are 3 towers ($A,B,C$) and 2 rings on $A$, then to move this arrange to $C$, following operations need to be performed
   1. Move smaller ring to intermediate tower, $B$ (i.e. $A\text{ }B$)
   2. Move larger ring to final tower, $C$, (i.e. $A\text{ }C$)
   3. Move smaller ring to final tower, $C$, (i.e. $B\text{ }C$)

Now using these, consider for $n=3$, firstly a solution is needed for $n=2$ but with the final tower being $2$ instead of $3$, then largest ring will be transfered to tower $3$ and then again solution for $n=2$ is needed, this time, with initial tower being $2$ and final tower being tower $3$.

Similarly for $n=4$, a solution for $n=3$ is needed at intermediate tower and so on...

## Sample to understand the solution

### Input
4

### Output
15\
1 2\
1 3\
2 3\
1 2\
3 1\
3 2\
1 2\
1 3\
2 3\
2 1\
3 1\
2 3\
1 2\
1 3\
2 3

### Explanation

15 (total number of steps)\
1 2\
1 3\
2 3 (create $n=2$ on tower $3$)\
1 2\
3 1\
3 2\
1 2 (create $n=3$ on tower $2$)\
1 3 (transfer largest ring to tower $3$)\
2 3\
2 1\
3 1\
2 3\
1 2\
1 3\
2 3 (create $n=3$ on tower $3$ from tower $2$)

---