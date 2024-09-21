# Concert Tickets
## Program Info
- Platform/Source:-     CSES Sorting and Searching
- Date:-                24 January 2022
- Type of Problem:-     Sorting and Searching (Bounds)
- Status:-              Solved
#### Complexity:-       O(n*logn)
---
## Solution in brief

All the tickets are stored in a multiset, called 'tickets'. For each incoming customer, the lower\_bound iterator in the multiset is checked:

- If the lower\_bound iterator points to the exact value customer is willing to pay, then the value is printed and iterator is erased.
- Else if the lower\_bound points to the first ticket in the multiset (i.e. tickets.begin()), then -1 has to be printed as no ticket exists as small as the maximum value the customer is willing to pay.
- Else, the lower\_bound is first decremented (to find the ticket that is just smaller than the price customer is willing to pay), then the value is printed and iterator erased.


## Sample to understand the solution

### Input
5 5\
3 5 7 9 11\
3 8 9 4 6

### Output
3\
7\
9\
-1\
5

### Explanation
(Sufficiently explained in 'Solution in brief').

---
