/*
Name:-              Towers
Platform:-          CSES
Date:-              24 January 2022
Type of Problem:-   Searching (multiset)
Complexity:-        O(nlog(n))
Status:-            Solved

Solution in brief:
For each input, upper bound is found in the multiset. 
If it is end(), then a new tower is required, else the upper_bound is erased and new element is added.
At the end, the size of the multiset is printed.

Sample to understand solution:
Input:-
5
3 8 2 1 5
Output:-
2
Explanation:-

*/
#include <iostream>
#include <set>
using namespace std;

int main(){
    int n,a;
    cin>>n;
    multiset<int> towers;
    for(int i= 0;i<n;++i){
        cin>>a;
        auto itr = towers.upper_bound(a);
        if(itr == towers.end()){towers.insert(a);}
        else{towers.erase(itr);towers.insert(a);}
    }
    cout<<towers.size();
    return 0;
} 