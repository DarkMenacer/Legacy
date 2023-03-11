# Edit Distance
## Program Info
- Platform/Source:-     CSES Dynamic Programming
- Date:-                15 September 2022
- Type of Problem:-     Conditional Memoization, 2D Dynamic Programming
- Status:-              Solved
#### Complexity:-       O(n²)
---
## Solution in brief

The key to solve this problem is to start comparing from last characters from each string.
If, say that, first string has to be converted to second string, there are 3 possibilities for first string
1. Add a character.
2. Delete a character. 
3. Replace a character.
   
For the first two possibilities, it is guarenteed to increase cost by 1, but in the last case, if both characters are equal, then no replacement is needed, hence cost doesn't increase.

So at position 'a' for first string and position 'b' for the second string,
$$\text{solve}(a,b) = \text{min}(\text{solve}(a-1,b) + 1, \text{solve}(a,b-1) + 1, \text{solve}(a-1,b-1) + \text{cost})$$
where $\text{cost} = 0$ if characters are equal else 1 and base condition is $\text{solve}(0,0) = 0$

Now this is memoized simply by a 2D array with one string as column and other as rowand the elements are filled using above 2 recursion equations.

Finally the answer is $\text{memoize}[\text{one.size()}][\text{two.size()}]$ where one and two are the strings.

## Sample to understand the solution

### Input
LOVE\
MOVIE 

### Output
2

### Explanation

Starting from behind, try finding edit distances for following:\
    LOV_ and MOVI_\
    LOV_ and MOV_\
    ...

This table depicts the conversion when travelled along principle diagonal starting from bottom right

|     |     | M   | O   | V   | I   | E   |
| --- | --- | --- | --- | --- | --- | --- |
|     | 0   | 1   | 2   | 3   | 4   | 5   |
| L   | 1   | 1   | 2   | 3   | 4   | 5   |
| O   | 2   | 2   | 1   | 2   | 3   | 4   |
| V   | 3   | 3   | 2   | 1   | 2   | 3   |
| E   | 4   | 4   | 3   | 2   | 2   | 2   | 

---
