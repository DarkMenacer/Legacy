/*
Name:-              Dice Combinations
Platform:-          CSES
Date:-              25 June 2022
Type of Problem:-   Dynamic Programming
Complexity:-        O(n)
Status:-            Solved

Solution in brief:
Basically, as total possible ways need to be counted
For any input n, solve(n) = ⁶∑ᵢ₌₁ solve(n-i)
and base conditions are solve(0) = 0 and solve(1) = 1
Note that for n = 2 to n = 6, there is an extra possibility as the die has a face corresponding to those numbers

Sample to understand solution:
Input:-
7

Output:-
63

Explanation:-
solve(7)= solve(7-1) + solve(7-2) + solve(7-3) + solve(7-4) + solve(7-5) + solve(7-6)
        = solve(6) + solve(5) + solve(4) + solve(3) + solve(2) + solve(1) 
        = ....
        = 63
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long mod = 1e9 + 7;
    vector<long long> solve(n+1);
    solve[0] = 0;
    solve[1] = 1;
    long long total = 1;
    for(int i=2;i<n+1;++i){
        if(i<7){solve[i] = total + 1;}
        else{solve[i] = total % mod;total-=solve[i-6];}
        total+=solve[i];
    }
    cout<<solve[n];
    return 0;
}