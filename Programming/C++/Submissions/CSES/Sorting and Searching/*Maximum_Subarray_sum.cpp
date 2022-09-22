/*
Name:-              Maximum Subarray Sum
Platform:-          CSES
Date:-              20 February 2022
Type of Problem:-   Greedy, incremental design
Complexity:-        O(n)
Status:-            Solved

Solution in brief:
For every succesive element in the 'values' array, we compare existing (sum + next) and (next) itself, and 

Sample to understand solution:
Input:-

Output:-

*/

#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define pb push_back
#define ll long long
using namespace std;
 
ll give_me_answer(vector<ll> &values){
    ll max_sum = values[0], sum = max_sum;
    unsigned i;
    FOR(i,1,values.size()){
        sum = max(sum + values[i], values[i]);
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}
 
int main(){
    int n,i,x;
    cin>>n;
    vector<ll> values;
    FOR(i,0,n){
        cin>>x;
        values.pb(x);
    }
    cout<<give_me_answer(values);
    return 0;
}