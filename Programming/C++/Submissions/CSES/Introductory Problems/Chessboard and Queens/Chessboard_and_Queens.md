# Chessboard and Queens
## Program Info
- Platform/Source:- CSES Introductory Problems
- Date:- 3 September 2021
- Type of Problem:- Complete Search (Back-tracking)
- Status:- Solved
#### Complexity:- O(n!)
---
## Solution in brief
For every queen placed, its corresponding row, column and primary & secondary diagonals become invalid.
Therefore 3 arrays $\text{column}$,$\text{ prdiag, sediag}$ are created to monitor each of them.

Now, It is ensured that only 1 queen can be placed on each row by iterating row-wise.
A simple back-tracking algorithm is contrived there-after.

Row $i$ is used as a means to progress ahead\
$i$ is only incremented if a queen is either already placed or IS placed during the iteration, else no solution is possible.

For each row $i$:-  $\text{column}[j]$ , $\text{prdiag}[j-i+7]$, $\text{sediag}[i+j]$ or $\text{board}[i][j]$ are checked to be true.

1. If true, queen cannot be placed on $\text{board}[i][j]$ and $j$ is incremented. If $j$ reaches 8 and still no queen is placed, the algorithm backtracks, i.e. $i$ is decremented.
2. If false, queen is placed on $\text{board}[i][j]$, $\text{column}[j]$ , $\text{prdiag}[j-i+7]$, $\text{sediag}[i+j]$ are set true and $i$ is incremented to next state.

Now, if $i$ reaches 8, that means 8 queens (0 to 7) are successfully placed on the board, therefore it is a possible solution.
Hence 'answer' is incremented, and the algorithm back-tracks.

## Sample to understand the solution

### Input
\*.......\
......\*.\
....\*...\
.......\*\
.\*......\
...\*....\
........\
........

### Output
50

### Explanation
Sufficiently explain in "Solution in brief"

---