# Gray Code
## Program Info
- Platform/Source:- CSES Introductory
- Date:- 23 June 2021
- Type of Problem:- Brute-Force, Complete Search
- Status:- Solved
#### Complexity:- O(2ⁿ)
---
## Solution in brief
The key here is to notice that there is a pattern for the least two significant bits. The pattern is

...00 -> ...01 -> ...11 -> ...10 -> ...00 -> ...01 -> ......

Therefore, first using the input $n$ , a vector of size $n$ can be initialised with all elements 0 \
Then for every least significant bit starting from the 3rd LSB, the above pattern is printed using brute-force. 

## Sample to understand the solution

### Input
4

### Output
0000\
0001\
0011\
0010\
0110\
0100\
0101\
0111\
1111\
1110\
1100\
1101\
1001\
1011\
1010\
1000

### Explanation

The above pattern is evident in the example. After every 4 iterations, the pattern picks up from the 4th iteration and continues itself forward till all combinations have been elucidated.

---