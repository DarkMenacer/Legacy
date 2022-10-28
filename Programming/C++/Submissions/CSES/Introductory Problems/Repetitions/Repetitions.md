# Repetitions
## Program Info
- Platform/Source:- CSES Introductory Problems
- Date:- 24 May 2021
- Type of Problem:- Greedy, Basic
- Status:- Solved
#### Complexity:- O(n) 
---
## Solution in brief

The solution involving having a counter that keeps on incrementing until the character remains same 
while iterating through the string.

When the character changes, the value of counter is compared with a max length and 
if $counter > maxlen$ then $maxlen = counter$ else continue iterating through string

## Sample to understand the solution

### Input
ATTCGGGA

### Output
3

### Explanation

| character | A   | T   | T   | C   | G   | G   | G     | A   |
| --------- | --- | --- | --- | --- | --- | --- | ----- | --- |
| counter   | 1   | 1   | 2   | 1   | 1   | 2   | **3** | 1   |


---

