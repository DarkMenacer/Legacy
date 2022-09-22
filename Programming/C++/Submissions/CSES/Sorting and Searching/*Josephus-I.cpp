/*
Name:-              Josephus Problem I
Platform:-          CSES
Date:-              27 January 2022
Type of Problem:-   Number Theory, Searching
Complexity:-        O(n)
Status:-            Solved

Solution in brief:

Sample to understand solution:
Input:-

Output:-

Explanation:-

*/
#include <iostream>
#include <vector>
#include <iterator>
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define display(name) for(auto it: name){cout<<it<<" ";}cout<<"\n";using namespace std;
using namespace std;

int main(){
    int n,num_printed = 1;
    cin>>n;
    vector<int> children;
    int i = 0;
    while(1){
        ++i;
        children.push_back(i);
        if(n%2){
            if(i==n){break;}
            ++i;
            cout<<i<<" ";
            ++num_printed;
        }
        else{
            ++i;
            cout<<i<<" ";
            ++num_printed;
            if(i==n){break;}
        }
    }

    vector<int> :: iterator pick = children.begin();
    if(n%2){--pick;}
    while(num_printed<=n){
        ++pick;
        if(pick==children.end()){pick = children.begin();}
        cout<<*pick<<" ";
        ++num_printed;
        pick = children.erase(pick);
        if(pick==children.end()){pick = children.begin();}
    }

    display(children);
    return 0;
}