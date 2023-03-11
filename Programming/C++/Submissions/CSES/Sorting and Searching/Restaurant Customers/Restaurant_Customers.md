# Restaurant Customers
## Program Info
- Platform/Source:-     CSES Sorting and Searching
- Date:-                17 January 2022
- Type of Problem:-     Custom Pairing, Sorting
- Status:-              Solved
#### Complexity:-       O(n*logn)
---
## Solution in brief
The arrival time of a customer is taken as a pair with '1' and departure time as a pair with '-1' in a vector< pair<int,int> >\
The vector is sorted according to the 1st values and then tranversed, adding the second values.

Basic idea is that when a customer arrives, '1' is added and when he leaves '-1' is added. Max of the value is our answer to the problem.

## Sample to understand the solution

### Input
3\
1 5\
2 3\
4 7

### Output
2

### Explanation

vector<pair<int,int>> :

| 1   | 2   | 3   | 4   | 5   | 7   |
| --- | --- | --- | --- | --- | --- |
| 1   | 1   | -1  | 1   | -1  | -1  | 

at time 2, 2 customers are eating which is the max.

---