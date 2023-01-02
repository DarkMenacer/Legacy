# Apple Division
## Program Info
- Platform/Source:- CSES Introductory
- Date:- 27 August 2022
- Type of Problem:- Complete Search, Implementation
- Status:- Solved
#### Complexity:- O(2ⁿ)
---
## Solution in brief
As the constraints are lenient, a complete search algorithm can be constructed.

The apples need to be divided into 2 groups, and the difference between weights of the 2 groups must be minimized.

Hence the apples in the first group can be assigned a positive sign and, one in group 2 can be assigned a negative sign.
Finally all of them are added to get the difference between the weights.

The brute force method checks all possible $2^n$ combinations (either an apple is in group 1 or group 2) and outputs the least difference.

The implementation is tricky though. A boolean array $sign$ of size $n$ is initialized.
$sign[i]$ indicates which group apple $i$ belongs to.
Following function is used to go through each possible configuration of $sign$ array.

    for(int i=n-1;i>=1;--i){
        if(sign[i]==0){sign[i]=1;break;}
        else{sign[i]=0;}

Note that, by only considering n-1 apples in the algorithm, the last apple is forcefully kept in the first group to avoid double counting.

## Sample to understand the solution

### Input
4\
3 2 7 4

### Output
2

### Explanation

| 3   | 2   | 7   | 4   | difference |
| --- | --- | --- | --- | ---------- |
| +   | +   | +   | +   | 16         |
| +   | +   | +   | -   | 8          |
| +   | +   | -   | +   | 2          |
| +   | +   | -   | -   | 6          |
| +   | -   | +   | +   | 12         |
| +   | -   | +   | -   | 4          |
| +   | -   | -   | +   | 2          |
| +   | -   | -   | -   | 10         |

Therefore answer is 2

---