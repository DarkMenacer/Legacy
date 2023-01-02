# Two Knights

## Program Info

- Platform/Source:- CSES Introductory

- Date:- 24 August 2022

- Type of Problem:- Combinatorix

- Status:- Solved

#### Complexity:- O(1)

---

## Solution in brief

It can be realised that for 
1. n = 1, no solution is possible.
2. n = 2, all possible combinations are valid, i.e ${4 \choose 2} = 6$
3. For x = 3 onwards, there will be cases in which the knights attack each other, therefore certain number of configurations need to subtracted out of total possible combinations (for  $n \times n$ board, there are $n^2 \choose 2$ ways to place 2 knights, conflicting cases included)

There are 2 approaches to count the no. of conflicting configurations:

  

#### Approach 1: Brute Force counting

There are discrete number of cases for where the first knight can be placed.
1. At corner position: There are 2 possible undesirable configuration for each corner
2. At edge positions
	1. < 2 steps away from corner (*count no. of cases*)
	2. ≥ 2 steps away from corner (*count no. of cases*)
3. At inner positions
	1. < 2 steps away from edges
		1. from both the edges (*count no. of cases*)
		2. from only one of the edges (*count no. of cases*)
	2. ≥ 2 steps away from edges (*count no. of cases*)

Add all of the above cases and subtract it from $n^2 \choose 2$

The final formula after subtracting comes out to be:
$$\frac{n^4 - 9n^2 + 24n - 16}{2} $$

#### Approach 2: *Clever counting

It can be realised that there is exactly 1 conflict for every $4 \times 3$ segment on the board. Therefore the number of $4 \times 3$  blocks can be counted to get the number of conflicting configurations.

<!-- To complete -->
  

## Sample to understand the solution

### Input
3
  
### Output
0\
6\
28

### Explanation
Answers evaluated using $\frac{n^4 - 9n^2 + 24n - 16}{2}$ formula for each number $n\text{ }\epsilon\text{ }[1,3]$ 

---