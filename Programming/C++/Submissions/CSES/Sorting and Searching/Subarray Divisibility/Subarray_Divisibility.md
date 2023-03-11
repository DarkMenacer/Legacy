# Subarray Divisibility
## Program Info
- Platform/Source:-     CSES Sorting and Searching
- Date:-                5 April 2022
- Type of Problem:-     Prefix Sums
- Status:-              Solved
#### Complexity:-       O(n)
---
## Solution in brief

Input is taken in vector 'integers'. Another vector 'remainder' is initialised.

For each input, prefix sum is found out and its mod is found out.
The basic idea is that the number of pairs are to be found with same remainders i.e. 
$$\text{if } x \text{ mod } n = y \text{ mod } n \text{ then } x-y \text{ mod } n = 0$$

Therefore for each prefix sum, the $\text{remainder}[\text{prefixSum } \% \text{ }n]$ is incremented for every occurernce of it to count the no. of same remainders.

(but special care is taken that 
negative index is not inputed hence $\text{remainder}[((\text{prefixSum }\%\text{ }n) + n)\%\text{ }n]$ is incremented)

Then finally no. of pairs for each index in remainder $(\frac{x*(x-1)}{2})$ are found out and added to answer. 

## Sample to understand the solution

### Input
6\
4 -6 8 2 3 11

### Output
4

### Explanation


| Input          |     | 4   | -6  | 8   | 2   | 3   | 11  |
| -------------- | --- | --- | --- | --- | --- | --- | --- |
| Prefix sum     | 0   | 4   | -2  | 6   | 8   | 11  | 22  |
| Prefix sum % n | 0   | 4   | 4   | 0   | 2   | 5   | 4   |


| Count     | 2   | 0   | 1   | 0   | 3   | 1   |
| --------- | --- | --- | --- | --- | --- | --- |
| Remainder | 0   | 1   | 2   | 3   | 4   | 5   | 

Pairs are only possible for index 0 and 4, one pair for index 0 and three for index 4. 
Therefore answer = 4

---