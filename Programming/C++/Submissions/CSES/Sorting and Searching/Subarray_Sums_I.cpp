/*
Name:-              Subarray Sums I
Platform:-          CSES
Date:-              20 March 2022
Type of Problem:-   Two pointer
Complexity:-        O(n)
Status:-            Solved

Solution in brief:
A variable sum is initialised to zero. Two pointers, i and j are initialised at a.begin().
while sum <= x, the value pointed by j is added and j is incremented.
when (and if) sum becomes greater than x, then value pointed by i is subtracted and i is incremented, effectively reducing the subarray.

Sample to understand solution:
Input:-
5 7
2 4 1 2 7

Output:-
3

Explanation:-
j is incremented until these points are reached, here i is incremented.
i: 0 j: 3 sum: 7
i: 1 j: 4 sum: 7
i: 4 j: 5 sum: 7

*/

#include <iostream>
#include <vector>
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
using namespace std;
 
int main(){
    int n,x,i = 0,j = 0,answer = 0;
    cin>>n>>x;
    vector<int> a(n);
    take_loop_input_in(a,n);
    int sum = 0;
    while(i<n){
        if(sum == x){
            ++answer;
            sum-=a[i++];
            continue;
        }
        else if(sum > x){
            sum-=a[i++];
            continue;
        }
        if(j<n){sum+=a[j];++j;}
        else{break;}
    }
    cout<<answer;
    
    return 0;
}