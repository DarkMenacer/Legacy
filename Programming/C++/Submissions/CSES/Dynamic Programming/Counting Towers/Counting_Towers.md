# Counting Towers
## Program Info
- Platform:- CSES: Dynamic Programming
- Date:- 13 September 2022
- Type of Problem:- Mathematically modelling, Dynamic Programming
- Status:- Solved
#### Complexity:- O(n)

---
## Solution in Brief
The first thing to be done in such a question is to setup a model to encode blocks.
The best way to encode is to use the intersection point (middle point) of a 2x2 block
There are 8 possible combinations:-

![8_blocks.png](https://github.com/DarkMenacer/Legacy/blob/main/Programming/C%2B%2B/Submissions/CSES/Dynamic%20Programming/Counting%20Towers/8_blocks.png)

It must be noted that all towers can be represented using the above 8 blocks
For eg:-

![Example_block.png](https://github.com/DarkMenacer/Legacy/blob/main/Programming/C%2B%2B/Submissions/CSES/Dynamic%20Programming/Counting%20Towers/Example_block.png)

This block is {6, 2}, i.e first intersection from bottom is of type 6 and one above that is type 2.
Now that the towers are encoded, it is realised that not all encodings can exist i.e.
{1,8} cannot exist as 1 demands top to be closed whereas 8 demands bottom to be open.
Therefore a mapping is made.

| Bottom | Top       |
| ------ | --------- |
| 1      | 1,2,3,4,5 |
| 2      | 1,2,3,4,5 |
| 3      | 1,2,3,4,5 |
| 4      | 1,2,3,4,5 |
| 5      | 6,7,8     |
| 6      | 1,2,3,4,5 |
| 7      | 6,7,8     |
| 8      | 6,7,8     |


As 1,2,3,4,5 are same, that is why they are grouped into Group G1, so are 7,8 into G4.
Now as 5,6 map to different tops, they are each into different group G2 and G3 respectively.
Now, finally a 2D memoization table is created 

$$memoize[\text{size of tower}][\text{total groups (=4)}]$$

To understand further working, forget about the groups and try to solve it taking each block seperately for ease.

Following continues the group approach for efficiency.

#### Recursive Condition:-
$$memoize[i][j] = memoize[i-1][\text{depends on the group}]$$

$\text{if group 1 then [1,2,3,4] + [5] times 4 because 4 blocks in the group}$

$\text{if block 5 then [6] + [7,8]}$

$\text{if block 6 then [1,2,3,4] + [5]}$

$\text{if group 4 then [6] + [7,8] times 2 because 2 blocks in the group}$

#### Base Condition:-
$memoize[2][G1] = 4 \text{ for 4 blocks}$ 
$memoize[2][G4] = 2$ and 
$memoize[2][\text{G2 and G3}] = 1$ similarly

Finally the answer is the sum of the last row (that is the no. of blocks that can be formed using all groups at that height).

## Sample to understand solution:
### Input:-
3

2

6

1337

### Output:-
8

2864

640403945

### Explanation:-
Explained sufficiently in "Solution in brief".

---
