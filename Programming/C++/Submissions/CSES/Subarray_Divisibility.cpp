/*
Name:-              Subarray Divisibility
Platform:-          CSES
Date:-              5 April 2022
Type of Problem:-   Prefix Sums
Complexity:-        O(n)
Status:-            Solved

Solution in brief:
Input is taken in vector 'integers'. Another vector 'remainder' is initialed.
For each input, prefix sum is found out and its mod is found out.
The basic idea is that the number of pairs are to be found with same remainders as if x(mod)n = y(mod)n then (x-y)(mod)n = 0
Therefore for each prefix sum, the remainder[prefix_sum % n] is incremented but special care is taken that 
negative index is not inputed hence remainder[((prefix_sum % n) + n)%n]++
Then finally no. of pairs for each index in remainder (x*(x-1)/2) are found out and added to answer. 

Sample to understand solution:
Input:-
6
4 -6 8 2 3 11

Output:-
4

Explanation:-
Input      :    4  -6  8  2  3  11
Prefix Sum : 0  4  -2  6  8  11 22 
Remainder  : 2 0 1 0 3 1
             0 1 2 3 4 5
Pairs are only possible for index 0 and 4, one pair for index 0 and three for index 4. 
Therefore answer = 4

*/

#include <vector>
#include <iostream>
#define ll long long
#define vl vector<ll>
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
using namespace std;

int main(){
    int n;
    cin>>n;
    vl integers(n);
    take_loop_input_in(integers,n);
    vl remainder(n);
    ll sum = 0, answer = 0;
    remainder[0]++;
    for(int i=0;i<n;++i){
        sum+=integers[i];
        remainder[(sum%n + n)%n]++;
    }
    for(int i=0;i<n;++i){
        if(remainder[i]){
            ll x = remainder[i];
            answer+= x*(x-1)/2;
        }
    }
    cout<<answer;
    return 0;
}