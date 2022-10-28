# Palindrome Reorder
## Program Info
- Platform/Source:- CSES Introductory Problems
- Date:- 23 June 2021
- Type of Problem:- Brute Force
- Status:- Solved
#### Complexity:- O(n²) 
---
## Solution in brief
Firstly the string is traversed over and the distinct characters and 
their respective number of occurences are stored in vectors $letters$ and $counts$ respectively

Now the $size$ of the string is checked
1. If it is even, then no occurence of any letter should be odd
2. If it is odd, then only one letter is allowed to occur odd number of times

After this step, the letters are symmetrically placed in a new string, i.e.
$$out[i] = out[size-1-i]$$

The final answer is $out$

## Sample to understand the solution

### Input
AAAACACBA

### Output
AACABACAA

### Explanation

| letters | A   | B   | C   |
| ------- | --- | --- | --- |
| counts  | 6   | 1   | 2   |

$\text{size of input} = 9$ which is odd, therefore 'B' will be placed in the middle

A...B...A\
AA..B..AA\
AAA.B.AAA\
AAACBCAAA

---