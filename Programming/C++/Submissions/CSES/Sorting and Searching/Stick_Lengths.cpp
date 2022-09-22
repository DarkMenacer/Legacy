/*
Name:-              Stick Lengths
Platform:-          CSES
Date:-              21 January 2022
Type of Problem:-   Measures of central tendency(median), sorting 
Complexity:-        O(n)
Status:-            Solved

Solution in brief:
Input is taken as vector<ll> and is sorted. The vector is sorted. Median is found. (n-1)/2th for odd, average of n/2th and (n/2-1)th for even.
Median is subtracted from each value in the vector and the values are added up as the answer.

Sample to understand solution:
Input:-
2 2 4 6 7

Output:-
9
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define pb push_back
#define all(name) name.begin(),name.end()
using namespace std;

ll give_me_answer(vector<ll> values){
    ll index, len, answer = 0;
    if(values.size()%2){
        index = (values.size()-1)/2;
        len = values[index];
    }
    else{
        index = (values.size())/2;
        len = (values[index] + values[index-1])/2;
    }
    for_each(all(values),[len, &answer](ll &d){ d=abs(d-len); answer += d;});
    return answer;
}

int main(){
    ll n,i,x;
    vector<ll> values;
    cin>>n;
    FOR(i,0,n){
        cin>>x;
        values.pb(x);
    }
    sort(all(values));
    cout<<give_me_answer(values);
    return 0;
}