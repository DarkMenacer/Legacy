# Reading Books
## Program Info
- Platform/Source:-     CSES Sorting and Searching 
- Date:-                23 February 2022
- Type of Problem:-     Sorting (Set, greater\<int\>)
- Status:-              Solved
#### Complexity:-       O(n*logn)
---
## Solution in brief
As time has to be minimised, the overlap between the readers should be maximum.\
Therefore all longer books are read first. Kotivalo starts with longest and Justiina starts with 2nd longest.\
Justiina finishes before Kotivalo (because her book was 2nd longest) and picks up 3rd longest.\
She keeps picking up the next longer book (but not the longest) and ends with the longest book (so that Kotivalo avoids waiting whatsoever).\
So in this case, the answer is the sum of duration of all books (as no one is waiting at any point of time).

But if the longest book is longer than sum of durations of all other book, Justiina has to wait for Kotivalo to finish the longest book.
Hence the total time is twice the duration of the longest book.

## Sample to understand the solution

### Input-1
4\
50 21 20 8

### Output-1
99

### Input-2
4\
50 22 20 8

### Output-2
100

### Explanation
(Sufficiently explained in 'Solution in brief').

---