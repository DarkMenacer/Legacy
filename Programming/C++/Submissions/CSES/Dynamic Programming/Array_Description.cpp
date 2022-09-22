/*
Name:-              Array Description
Platform:-          CSES
Date:-              24 August 2022
Type of Problem:-   2D Dynamic Programming
Complexity:-        O(n²)
Status:-            Solved

Solution in brief:
Starting with a string with all 0s, it is observed that the number of arrays for each place depend on
1) The position and
2) The number placed
i.e. for each ordered pair of (position,number), same number of arrays are possible.
Therefore a 2D memoization table is constructed with position as y axis and numbers as x axis.
Each entry aᵢⱼ represents the total possible arrays when number 'j' is placed at position 'i'
The table is constructed from the bottom as if last value is unknown then for each number at the position, only 1 array is possible.
This acts like a base criteria of dynamic programming. The recursive formula is 
memoize[i][j] = memoize[i+1][j-1] + memoize[i+1][j] + memoize[i+1][j+1] if x[j] is unknown(0).
else if x[j] is a known number then memoize[j][x[j]] = memoize[j+1][x[j]-1] + memoize[j+1][x[j]] + memoize[j+1][x[j]+1]

Sample to understand solution:
Input:-
4 4
0 0 0 0

Output:-
68

Explanation:-

                       0000
    1000               2000                3000                  4000
1100   1200     2100   2200   2300     3200   3300   3400     4300   4400
 A      B        A      B      C        B       C      D        C     D 

As seen, both the strings '1100' and '2100' have equal number of arrays possible
Hence we need to calculate them only once and stored in the memoize table
Below is the Memoize Table and A = Memoize[2][1], B = Memoize[2][2]

Memoize Table:-
   0  1  2  3  4
  _______________
0| 0  13 21 21 13 
1| 0  5  8  8  5 
2| 0  2  3  3  2 
3| 0  1  1  1  1 

*/

#include <iostream>
#include <vector>
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> x(n);
    take_loop_input_in(x,n);
    vector< vector<int> > memoize(n, vector<int>(m+1,0));
    if(x[n-1]){
        memoize[n-1][x[n-1]] = 1;
    }
    else{
        vector<int> temp(m+1,1);
        temp[0] = 0;
        memoize[n-1] = temp;
    }

    int answer = 0;
    int mod = 1e9 + 7;
    for(int i=n-2;i>=0;--i){
        if(x[i]){
            //memoize[i][x[i]] = memoize[i+1][x[i]-1] + memoize[i+1][x[i]] + memoize[i+1][x[i]+1];
            (memoize[i][x[i]] += memoize[i+1][x[i]-1])%=mod;
            (memoize[i][x[i]] += + memoize[i+1][x[i]])%=mod;
            (memoize[i][x[i]] += memoize[i+1][x[i]+1])%=mod;
            //if(!i){answer=memoize[i][x[i]];}
        }
        else{
            for(int j=1;j<m+1;++j){
                //memoize[i][j] = memoize[i+1][j-1] + memoize[i+1][j] + memoize[i+1][j+1];
                (memoize[i][j] += memoize[i+1][j-1])%=mod;
                (memoize[i][j] += memoize[i+1][j])%=mod;
                (memoize[i][j] += memoize[i+1][j+1])%=mod;
                //if(!i){(answer+=memoize[i][j])%=mod;}
            }
        }
    }
    for(int j=1;j<m+1;++j){
        (answer+=memoize[0][j])%=mod;
    }

    cout<<answer%mod;
    return 0;
}