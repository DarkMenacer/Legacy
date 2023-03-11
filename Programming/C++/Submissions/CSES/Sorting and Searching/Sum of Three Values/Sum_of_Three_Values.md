# Sum of Three Values
## Program Info
- Platform/Source:-     CSES Sorting and Searching
- Date:-                24 February 2022 -> 19 September 2022
- Type of Problem:-     Three pointer, Greedy
- Status:-              Solved
#### Complexity:-       O(n²)
---
## Solution in brief

Firstly input is taken in a vector of pairs, the pair being the integer and its index.\
The vector is sorted according to first (preserving the initial indexes in the second).

3 iterators, i, j, k are defined, i is initialised to input.begin(). 
Now, j and k are tampered with according to the sum of i, j, k. j is initiased to i + 1

1. if i+j+k > x, then k is reduced, else if i+j+k < x, then j is increased.
2. If j ever increments to k or k decrements to j, then i is increment (as no possible combination fot that i was found).
3. If i reaches to input.end(), no possible combinations exists.
4. If i + j + k = x, then their indices are printed and program exits.

## Sample to understand the solution

### Input
7 13\
1 3 4 6 7 14

### Output
2 3 4

### Explanation

After sorting: 
| value | 1   | 3   | 4   | 6   | 7   | 14  |
| ----- | --- | --- | --- | --- | --- | --- |
| index | 1   | 2   | 3   | 4   | 5   | 6   | 


Finding possible solution
| 1   | 3   | 4   | 6   | 7   | 14  |
| --- | --- | --- | --- | --- | --- |
| i   | j   |     |     |     | k   | 

| 1   | 3   | 4   | 6   | 7   | 14  |
| --- | --- | --- | --- | --- | --- |
| i   | j   |     |     | k   |     |

| 1   | 3   | 4   | 6   | 7   | 14  |
| --- | --- | --- | --- | --- | --- |
| i   |     | j   |     | k   |     |

...

| 1   | 3   | 4   | 6   | 7   | 14  |
| --- | --- | --- | --- | --- | --- |
|     | i   | j   |     |     | k   | 

...

| 1   | 3   | 4   | 6   | 7   | 14  |
| --- | --- | --- | --- | --- | --- |
|     | i   | j   | k   |     |     | 

Triplet found

---