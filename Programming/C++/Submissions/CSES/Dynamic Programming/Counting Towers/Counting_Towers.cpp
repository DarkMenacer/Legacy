/*
Name:-              Counting Towers
Platform:-          CSES
Date:-              13 September 2022
Type of Problem:-   Mathematically modelling, Dynamic Programming
Complexity:-        O(n)
Status:-            Solved

Solution in brief:
The first thing to be done in such a question is to setup a model to encode blocks.
The best way to encode is to use the intersection point (middle point) of a 2x2 block
There are 8 possible combinations:-
 _ _     _ _     _ _     _ _     _ _     _ _     _ _     _ _                         
|_|_|   | |_|   | | |   |_| |   |_ _|   |_|_|   |_ _|   |   |
|_|_|   |_|_|   |_|_|   |_|_|   |_|_|   |_ _|   |_ _|   |_ _|
  1       2       3       4       5       6       7       8
It must be noted that all towers can be represented using the above 8 blocks
For eg:-
     _ _
    | |_|
    |_|_|
    |_ _|
This block is {6, 2}, i.e first intersection from bottom is of type 6 and one above that is type 2.
Now that the towers are encoded, it is realised that not all encodings can exist i.e.
{1,8} cannot exist as 1 demands top to be closed whereas 8 demands bottom to be open.
Therefore a mapping is made.
Bottom          Top
  1          1,2,3,4,5
  2          1,2,3,4,5
  3          1,2,3,4,5
  4          1,2,3,4,5
  5            6,7,8
  6          1,2,3,4,5
  7            6,7,8
  8            6,7,8
As 1,2,3,4,5 are same, that is why they are grouped into Group G1, so are 7,8 into G4.
Now as 5,6 map to different tops, they are each into different group G2 and G3 respectively.
Now, finally a 2D memoization table is created memoize[size_of_tower][{total groups = 4}]
To understand further working, forget about the groups and try to solve it taking each block seperately for ease.
Following continues the group approach for efficiency.
memoize[i][j] = memoize[i-1][{depends on the group}]
if group 1 then [1,2,3,4] + [5] times 4 because 4 blocks in the group
if block 5 then [6] + [7,8]
if block 6 then [1,2,3,4] + [5] 
if group 4 then [6] + [7,8] times 2 because 2 blocks in the group
Base condition is memoize[2][G1] = 4 for 4 blocks,  memoize[2][G4] = 2 and memoize[2][G2 and G3] = 1 similarly
Finally the answer is the sum of the last row (that is the no. of blocks that can be formed using all groups at that height)

Sample to understand solution:
Input:-
3
2
6
1337

Output:-
8
2864
640403945

Explanation:-
Explained sufficiently in "Solution in brief".
*/

#include <iostream>
#include <vector>
#define G1 0
#define G2 1
#define G3 2
#define G4 3
#define TOT_GRPS 4
#define ll long long
using namespace std;

int main(){
    ll mod = 1e9 + 7;
    vector< vector<ll> > memoize(1e6 + 1, vector<ll>(TOT_GRPS));
    for(int j=0;j<TOT_GRPS;++j){
        memoize[0][j] = 0;
        memoize[1][j] = 0;
    }
    memoize[1][1] = 1;
    memoize[1][2] = 1;
    for(int i=2;i<1e6+1;++i){
        (memoize[i][G1] = 4*(memoize[i-1][G1] + memoize[i-1][G3]))%=mod;
        (memoize[i][G2] = memoize[i-1][G1] + memoize[i-1][G3])%=mod;
        (memoize[i][G3] = memoize[i-1][G2] + memoize[i-1][G4])%=mod;
        (memoize[i][G4] = 2*(memoize[i-1][G2] + memoize[i-1][G4]))%=mod;
    }
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll answer = 0;
        for(int j=0;j<TOT_GRPS;++j){
            (answer+=memoize[n][j])%=mod;
        }
        cout<<answer<<endl;
    }
    return 0;
}