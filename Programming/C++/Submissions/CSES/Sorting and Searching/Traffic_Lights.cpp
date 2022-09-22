/*
Name:-              Traffic Lights
Platform:-          CSES
Date:-              25 January 2022
Type of Problem:-   Sorting and Searching
Complexity:-        O(n²)
Status:-            Time Limit Error

Solution in brief:

Sample to understand solution:
Input:-

Output:-

Explanation:-

*/

#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <numeric>
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define pb push_back
#define all(name) name.begin(),name.end()
using namespace std;

int main(){
    int x,n,p,answer;
    cin>>x>>n;
    set<int> signals;
    signals.insert(0);
    signals.insert(x);
    while(n--){
        answer = 0;
        cin>>p;
        signals.insert(p);
        vector<int> lengths(x,0);
        adjacent_difference(all(signals),lengths.begin());
        answer = *max_element(all(lengths));
        cout<<answer<<"\n";
    }
    return 0;
}