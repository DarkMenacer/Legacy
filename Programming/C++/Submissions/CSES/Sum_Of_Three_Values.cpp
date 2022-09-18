/*
Name:-              Sum Of Three Values
Platform:-          CSES
Date:-              24 February 2022 -> 19 September 2022
Type of Problem:-   Three pointer, Greedy
Complexity:-        O(n²)
Status:-            Solved

Solution in brief:
Firstly input is taken in a vector of pairs, the pair being the integer and its index.
The vector is sorted according to first (preserving the initial indexes in the second).
3 iterators, i, j, k are defined, i is initialised to input.begin(). 
Now, j and k are tampered with according to the sum of i, j, k. j is initiased to i + 1
if i+j+k > x, then k is reduced, else if i+j+k < x, then j is increased.
If j ever increments to k or k decrements to j, then i is increment (as no possible combination fot that i was found).
If i reaches to input.end(), no possible combinations exists.
If i + j + k = x, then their indices are printed and program exits.

Sample to understand solution:
Input:-
7 13
1 3 4 6 7 14

Output:-
2 3 4

Explanation:-
value |1 3 4 6 7 14
index |1 2 3 4 5 6

after sorting
1 3 4 6 7 14
1 2 3 4 5 6

Finding possible solution
1 3 4 6 7 14
i j       k

1 3 4 6 7 14
i j     k

1 3 4 6 7 14
i   j   k
..

1 3 4 6 7 14
  i j     k
..

1 3 4 6 7 14
  i j k
Triplet found
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#define take_indexed_loop_input(name,size) for(int i=1;i<size+1;++i){int x;cin>>x;name.push_back(make_pair(x,i));}
#define all(name) name.begin(),name.end()
#define fr first
#define sc second
#define ll long long
using namespace std;

int main(){
    ll n,x;
    cin>>n>>x;
    vector< pair<ll,ll> > input;
    take_indexed_loop_input(input,n);
    sort(all(input));
    vector< pair<ll,ll>>::iterator i,j,k;
    for(i = input.begin();i<input.end();++i){
        j = i + 1;
        k = input.end()-1;
        while(distance(j,k)>0){
            if(i->fr + j->fr + k->fr == x){
                cout<<i->sc<<" "<<j->sc<<" "<<k->sc<<endl;
                exit(0);
            }
            else if(i->fr + j->fr + k->fr > x){--k;}
            else if(i->fr + j->fr + k->fr < x){++j;}
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}