/*
Name:-              Sum Of Three Values
Platform:-          CSES
Date:-              24 February 2022
Type of Problem:-   Two pointer
Complexity:-        O(nlog(n))
Status:-            Wrong Answer (Algorithm correct, Implementation correct, C++ issue, need easier implementation of same algorithm)

Solution in brief:
Firstly input is taken in a vector of pairs, the pair being the integer and its index.
The vector is sorted according to first (preserving the initial indexes in the second).
2 iterators, one forward and one reverse, are initialised at the begin() and rbegin(), and their sum is subtracted from x, and named to_find.
If to_find < *itr, means that last element is too big hence ++ritr, similarly ++itr if to_find > *ritr.
Then lower_bound is implemented (user-implemented, as lower_bound couldn't be used on vector of pairs).
If element is found, then all seconds are printed, (all indexes).
Else "IMPOSSIBLE" is printed.

Sample to understand solution:
Input:-
6 10
2 5 3 8 1 9

Output:-
1 2 3

Explanation:-
Solution in brief self-explanatory.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define pb push_back
#define all(name) name.begin(),name.end()
#define take_loop_input_in(name,size) for(ll i=0;i<size;++i){cin>>name[i];}
#define take_indexed_loop_input(name,size) for(ll i=1;i<size+1;++i){cin>>v;name.push_back(make_pair(v,i));}
#define here cout<<"here\n"
#define nl cout<<'\n'
#define display(name) for(auto it: name){cout<<it<<" ";}cout<<"\n"
#define what_is___here(name) cout<<"It is "<<name<<"\n"
#define f first
#define s second
#define mp make_pair
#define p pair
#define ll long
using namespace std;
 
void print_answer(vector< p<int,int> > &integers, ll x){
    vector< p<int,int> >:: iterator itr = integers.begin(), middle;
    vector< p<int,int> >:: reverse_iterator ritr = integers.rbegin();
    while(distance(itr,ritr.base())){
        ll to_find = x - itr->f - ritr->f;
        if(to_find < itr->f){++ritr;continue;}
        if(to_find > ritr->f){++itr;continue;}
 
        vector< p<int,int> >:: iterator bin_min = itr, bin_max = ritr.base()-1, bin_mid;
        bool found = false;
 
        //user-implemented lower_bound function because c++ couldn't give a general stl function for vector of pairs.
        while(distance(bin_min,bin_max)>1){
            bin_mid = bin_min + (distance(bin_min,bin_max))/2;
            if(bin_mid->f > to_find){bin_max = bin_mid;}
            else if(bin_mid->f < to_find){bin_min = bin_mid;}
            if(bin_mid->f == to_find){found = true;break;}
        }
        if(found){cout<<itr->s<<" "<<bin_mid->s<<" "<<ritr->s;return;}
        ++itr;
    }
    cout<<"IMPOSSIBLE";
    return;
}
 
int main(){
    ll n,x,v;
    cin>>n>>x;
    vector< p<int,int> > integers;
    take_indexed_loop_input(integers,n);
    sort(all(integers));
    print_answer(integers,x);
    return 0;
}