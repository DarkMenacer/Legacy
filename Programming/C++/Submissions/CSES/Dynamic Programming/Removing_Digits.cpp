/*
Name:-              Removing Digits
Platform:-          CSES
Date:-              14 August 2022
Type of Problem:-   Dynamic Programming
Complexity:-        O(n (log(n))² )
Status:-            Solved

Solution in brief:
For each number x,
memoize[x] = min(memoize[x-c₁], memoize[x-c₂], ...) + 1
where c₁, c₂ are the digits in x

Sample to understand solution:
Input:-
13

Output:-
3

Explanation:-
14 = {1,4}
memoize[14] = min(memoize[13], memoize[10]) + 1
memoize[10] = min(memoize[9], memoize[10]) + 1
memoize[9] = 1
so memoize[10] = 2
similarly memoize[13] = 3

*/
#include <iostream>
#include <vector>
#include <cmath>
#define inf 1e9
using namespace std;

vector<int> digits(int x){
    int no = floor(log10(x)) + 1;
    vector<int> returner(no,-1);
    for(int i = 0; i < no; ++i){
        returner[i] = x%10;
        x = trunc(x/10);
    }
    return returner;
}

int main(){
    int n;
    cin>>n;
    if(n<10){
        cout<<1;
    }
    else{
        vector<int> memoize(n+1,inf);
        for(int i=0;i<n+1;++i){
            if(i<10){memoize[i] = 1;}
            else{
                vector<int> temp = digits(i);
                for(unsigned j=0;j<temp.size();++j){
                    memoize[i] = min(memoize[i], memoize[i - temp[j]] + 1);
                }
            }
        }
        cout<<memoize[n];
    }
    return 0;
}
