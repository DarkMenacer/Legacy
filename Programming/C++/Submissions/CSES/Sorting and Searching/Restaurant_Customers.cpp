/*
Name:-              Restaurant Customers
Platform:-          CSES
Date:-              17 January 2022
Type of Problem:-   Sorting, Pair
Complexity:-        O(n)
Status:-            Solved

Solution in brief:
The arrival time of a customer is taken as a pair with '1' and departure time as a pair with '-1' in a vector<pair<int,int>>
The vector is sorted according to the 1st values and then tranversed, adding the second values.
Basic idea is that when a customer arrives, '1' is added and when he leaves '-1' is added. Max of the value is our answer to the problem.

Sample to understand solution:
Input:-
3
1 5
2 3
4 7

Output:-
2

Explanation:-
vector<pair<int,int>> : 1  2  3  4  5  7
                        1  1 -1  1 -1 -1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define f first
#define s second
#define mp make_pair
#define p pair
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define pb push_back
#define all(name) name.begin(),name.end()
using namespace std;

int main(){
    int n,i,x,answer = 0, current=0;
    cin>>n;
    vector <p <int, int> > customers_moving;
    FOR(i,0,n){
        cin>>x;
        customers_moving.push_back( mp(x,1) );
        cin>>x;
        customers_moving.push_back( mp(x,-1) );
    }
    sort(all(customers_moving));
    for(auto time: customers_moving){
        current+=time.second;
        answer = max(answer,current);
    }
    cout<<answer;
    return 0;
}