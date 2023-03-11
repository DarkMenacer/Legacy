# Apartments
## Program Info
- Platform/Source:- CSES Sorting and Searching
- Date:-    3 January 2022
- Type of Problem:- Sorting
- Status:- Solved
#### Complexity:- O(n log(n)) 
---
## Solution in brief
2 multisets, 'apartments' and 'applicants' are created. 
For each element in applicants, elements in apartments are checked from the beginning.
Let e(apartments) denote current element of apartments
If e(applicants) - e(apartments) > k, then e(apartments) is removed from apartments.
Else if e(applicants) - e(apartments) < -k, next element of applicants is checked, i.e. e(applicants) occupies no room.
Else e(applicants) occupies e(apartments), and e(apartments) is removed from apartments.

## Sample to understand the solution

### Input
10 10 10\
90 41 20 39 49 21 35 31 74 86\
14 24 24 7 82 85 82 4 60 95

### Output
6

### Explanation

Applicants: 20 21 31 35 39 41 49 74 86 90 (sorted)\
Apartments: 4 7 14 24 24 60 82 82 85 95 (sorted)

Iterating over applicants, \
1st and 2nd apartments eliminated, as less than (20-10)\
3rd apartment allotted to applicant 1 and we go on to next applicant\
This continues for all applicants 


---