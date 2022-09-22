/*
Name:-              Edit Distance
Platform:-          CSES
Date:-              15 September 2022
Type of Problem:-   Dynamic Programming
Complexity:-        O(n²)
Status:-            Solved

Solution in brief:
The key to solve this problem is to start comparing from last characters from each string.
If it constrainted that first string has to be converted to second string, there are 3 possibilities for first string
One, add a character. Two, delete a character. Three, replace a character.
For the first two possibilities, it is guarenteed to increase cost by 1, 
but in the last case, if both characters are equal, then no replacement is needed, hence cost doesn't increase.
So at position 'a' for first string and position 'b' for the second string,
solve(a,b) = min (solve(a-1),b + 1, solve(a,b-1) + 1, solve(a-1,b-1) + cost)
where cost = 0 if characters are equal else 1 
The base condition is solve(0,0) = 0
Now this is memoized simply by a 2D array with one string as column and other as row
and the elements are filled using above 2 recursion equations.
Finally the answer is memoize[one.size()][two.size()]
where one and two are the strings.

Sample to understand solution:
Input:-
LOVE
MOVIE

Output:-
2

Explanation:-
Starting from behind, try finding edit distances for following
    LOV_ and MOVI_
    LOV_ and MOV_
    ...
This table depicts the conversion when travelled along principle diagonal starting from bottom right
    M O V I E
  0 1 2 3 4 5 
L 1 1 2 3 4 5 
O 2 2 1 2 3 4 
V 3 3 2 1 2 3 
E 4 4 3 2 2 2 

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
T min(T a, T b, T c){return ((a<b)? a:b) < c ? ((a<b)? a:b) : c;}
int cost(char i, char j){return (i==j? 0 : 1);}

int main(){
    string one, two;
    cin>>one>>two;
    vector< vector<int> > memoize (one.size()+1, vector<int> (two.size()+1));
    memoize[0][0] = 0;
    for(unsigned j=1; j<two.size()+1; ++j){
        memoize[0][j] = memoize[0][j-1] + 1;
    }
    for(unsigned i=1; i<one.size()+1; ++i){
        memoize[i][0] = memoize[i-1][0] + 1;
    }
    for(unsigned i=1; i<one.size()+1; ++i){
        for(unsigned j=1; j<two.size()+1; ++j){
            memoize[i][j] = min(memoize[i-1][j]+1, 
                                memoize[i][j-1]+1, 
                                memoize[i-1][j-1] + cost(one[i-1], two[j-1])
                                );
        }
    }
    cout<<memoize[one.size()][two.size()];
    return 0;
}