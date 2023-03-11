# Concert Tickets
## Program Info
- Platform/Source:-     CSES Sorting and Searching 
- Date:-                24 January 2022
- Type of Problem:-     Sorting and Searching (Bounds)
- Status:-              Solved
#### Complexity:-       O(n*logn)
---
## Solution in brief

2 vectors, 'tickets' and 'customers' are created, only tickets is sorted, as order matters for customers for output.\
For each customer, an iterator 'tic' is always initiated at tickets.begin().

If customer's max price is smaller than smallest ticket price (&tickets.begin()) OR tickets is empty\
    then '-1' printed & next customer is checked.\
Else, tic is incremented till *tic is greater than the customer's max price.\
tic is then decremented once, *tic is printed and the ticket is removed (tic is erased from tickets).

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
