# Name of the program
## Program Info
- Platform/Source:- CSES
- Date:- 18 October 2022
- Type of Problem:- Dynamic Programming, Top-down approach variation
- Status:- Solved
#### Complexity:- O(n²) 
---
## Solution in brief
The trick to solve this question is to realise that the sum of player one and two is constant.
i.e.
$\text{one} + \text{two} = \Sigma \text{values}$

Now the objective naturally is to maximise one - two.

With just one value, one - two is that value and with two values, one - two = max_value - min_value.
For three values, the above can be used by breaking into 1+2 and 2+1 values. 

i.e. first choose the leftmost element and consider other two as a unit (difference for which can be found out) then
choose the rightmost element and consider the other two as a unit.

Now, it can be observed that the difference between one and two matters for intervals.

Generalising above approach for calculating the difference of values from interval l to r:

$$diff[l][r] = max(value[l] - diff[l+1][r], value[r]- diff[l][r-1])$$

Consider how to form a top-down approach, to calculate diff[**l**][r] we need diff[**l+1**][r] so l starts from n-1 to 0 
whereas for r, as r can never be smaller than l, it starts as regular but from l to n-1.

## Sample to understand the solution

### Input
4

4 5 1 3

### Output
8

### Explanation
![Removal_Game.png](https://github.com/DarkMenacer/Legacy/blob/main/Programming/C%2B%2B/Submissions/CSES/Dynamic%20Programming/Removal%20Game/Removal_Game.png)

Diff table:-
| left/right | 0   | 1   | 2   | 3   |
| ---------- | --- | --- | --- | --- |
| 0          | 4   | 1   | 0   | 3   |
| 1          | -   | 5   | 4   | 3   |
| 2          | -   | -   | 1   | 2   |
| 3          | -   | -   | -   | 3   |

---
