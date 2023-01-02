# Digit Queries
## Program Info
- Platform/Source:- CSES Introductory 
- Date:- 31 August 2021
- Type of Problem:- Mathematics
- Status:- Solved
#### Complexity:- O(n) for n queries (i.e. O(1) for each query)
---
## Solution in brief
An approach to solve this question can be to first figure out the exact number corresponding to the query $n$.\
Following observations are helpful\
1. First 9 numbers ($0\ldots9$) take up first 9 digits, then next 90 numbers ($10\ldots99$) take the next ($90\times2$) 180 digits and so on...
2. Therefore the exact number in contention can be found out using just the query.

To generalise, consider a query $n$. Do the following to get the answer

1. Subtract $9\times1$, $90\times2$, $900\times3 \ldots$ until n stays non-negative. This gives the number of the digits, the number corresponding to the query, has, call it $c$.
2. Now, after subtracting, $n$ contains the remainder, i.e. the number of digits after the first $c$ digit number ($10, 100\ldots$). Divide $n$ by $c$ and add to the first $c$ digit number to get the exact number, the query corresponds to.
3. To figure out which digit of this number is the answer, the remainder of $n\div c$ is used.

## Sample to understand the solution

### Input
5\
9\
10\
189\
190\
240

### Output
9\
1\
9\
1\
6

### Explanation

For the last query, $240$, 
1. Subtract $9$, $=231$, subtract $90 \times 2$, $=51$. Therefore $3$ digit number.
2. $51 \div 3 = 17$, and $100 + 17 = 117$, is the number in consideration.
3. As $51 \text{ mod } 3 = 0$, the $0^{th}$ digit of $117$ is the last digit of number before ($116$), which is 6.



---