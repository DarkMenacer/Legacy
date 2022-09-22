/*
Name:-              Coin Combinations II
Platform:-          CSES
Date:-              17 August 2022
Type of Problem:-   Dynamic Programming
Complexity:-        O(n²)
Status:-            Solved

Solution in brief:
This problem is an extension of its predecessor in the list. Consider both as a pair.
Pay close attention to the codes here and code in "Coin Combinations I".
They are almost identical apart from the order in which for loops are nested.
As the order matters in this case, the coins, taken one by one, and once used are never considered again, starting from the least.
To understand why this works, construst a tree, with 0 as its root. To ensure that the set isn't repeated, a restriction is put.
Once a higher value coin is added, a lower value coin can't be added (look at the sample explanation for clearer understanding).
The number of times, 'x'(desired sum of money) appears, is the solution to the problem.

Sample to understand solution:
Input:-
3 11
2 3 5

Output:-
4

Explanation:-
Below tree gives a rough idea of what is happening
                                       0
                         2             3             5
           4             5     7       6    8         10
    6      7   9         8 10          9 11
  8 9 11  10            11
10 11

On the left subtree, only 2s are added. Once a 3 is added, 2 can't be added further (as evident in the middle subtree)
The right subtree contains increments by 5 hence neither 2 or 3 is added further.
MIND that the implement DIFFERS SIGNIFICANTLY.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define all(name) name.begin(),name.end()
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    take_loop_input_in(coins,n);
    vector<int> memoize(x+1,0);
    memoize[0] = 1;
    sort(all(coins));
    for(int i=0;i<n;++i){
        for(int j=1;j<x+1;++j){
            if(j-coins[i]>=0){
                memoize[j]+=memoize[j-coins[i]];
                memoize[j]%=1000000007;
            }
        }
    }
    cout<<memoize[x];
    return 0;
}

// THIS APPROACH OF USING SET IS SURPRISINGLY SLOWER
/* 
#include <set>

int main(){
    int n,x;
    cin>>n>>x;
    set<int> coins;
    take_loop_input_in(coins,n);
    vector<int> memoize(x+1,0);
    memoize[0] = 1;
    for(auto itr = coins.begin();itr!=coins.end();++itr){
        for(int j=1;j<x+1;++j){
            if(j-*itr>=0){
                memoize[j]+=memoize[j-*itr];
                memoize[j]%=1000000007;
            }
        }
    }
    cout<<memoize[x];
    return 0;
} */