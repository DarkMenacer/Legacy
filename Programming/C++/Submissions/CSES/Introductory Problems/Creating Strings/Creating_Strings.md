# Creating Strings
## Program Info
- Platform/Source:- CSES Introductory Problems 
- Date:- 27 June 2021
- Type of Problem:- Combinatrix, STL
- Status:- Solved
#### Complexity:- O(n!)
---
## Solution in brief
This is a cheap move but teaches how to use the tool.

Firstly the string is traversed over and the distinct characters and 
their respective number of occurences are stored in vectors $letters$ and $counts$ respectively

Then, calculate the total possible number of strings, $total$, using combinatrix by using the $counts$ vector.\
Sort the input string, and use the next_permutation() function in the standard template library $total$ number of times.

## Sample to understand the solution

### Input
aabac

### Output
20\
aaabc\
aaacb\
aabac\
aabca\
aacab\
aacba\
abaac\
abaca\
abcaa\
acaab\
acaba\
acbaa\
baaac\
baaca\
bacaa\
bcaaa\
caaab\
caaba\
cabaa\
cbaaa

### Explanation
Explained sufficiently in "Solution in brief"

---