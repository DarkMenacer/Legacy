# Sum of Two Values
## Program Info
- Platform/Source:-     CSES Sorting and Searching
- Date:-                22 January 2022
- Type of Problem:-     Two Pointer, Sorting, Pairing
- Status:-              Solved
#### Complexity:-       O(n*logn)
---
## Solution in brief
Input is taken in a pair with the value and its index and is stored in a vector. An iterator and a reverse iterator are used.\
If itr + ritr < x, itr is incremented, Else if itr + ritr > x, ritr is incremented, Else loop is broken and indexes are printed.

## Sample to understand the solution

### Input
4 8\
2 7 5 1

### Output
2 4

### Explanation

Original input:

| Number   | 2   | 7   | 5   | 1   |
| -------- | --- | --- | --- | --- |
| Position | 1   | 2   | 3   | 4   |

After Sorting:

| Number   | 1   | 2   | 5   | 7   |
| -------- | --- | --- | --- | --- |
| Position | 4   | 1   | 3   | 2   |

itr -> 1\
ritr -> 7

Sum is 8 hence 2 and 4 are printed.

If sum would have been less than 8, itr would have been incremented.\
If sum would have been greater than 8, ritr would have been incremented (note ritr is a reverse iterator, not an iterator).


---