/*
Name:-              Subarray Sums II
Platform:-          CSES
Date:-              5 April 2022
Type of Problem:-   Prefix Sums, Searching using Maps
Complexity:-        O(nlog(n))
Status:-            Solved

Solution in brief:
Input is taken in vector 'values'. The concept used here is of Prefix Sums, i.e.
sum of subarray[i,j] = Prefix_Sum[j] - Prefix_Sum[i-1]
Here sum of subarray should be x, therefore for every element a[j] in values, we first find Prefix Sum till j and then 
find for such an i such Prefix_Sum[i-1] = Prefix_Sum[j] - x.
Searching is fast in set and map O(log(n)) but map is specifically used for this question.
As there can be multiple such 'i's for which above equation is true (and each such i gives a valid answer)
Therefore, a map is used with key being prefix_sum[i] and value being occurence of prefix_sum[i].
Answer is incremented the number of times such an 'i' is found. 

Sample to understand solution:
Input:-
7 5
0 -3 6 2 -8 5 3

Output:-
6

Explanation:-
Input       : 0   -3   6   2   -8   5   3
Prefix Sum  : 0   -3   3   5   -3   2   5

At each index, prefix sum is calculated as shown and an appropriate 'i' is tried to found out, i.e
At index 2, prefix_sum[2] = -3, therefore we need such an i (< 2) for which prefix_sum[i] = 8, but such an i does not exist.
But at index 5, prefix_sum[5] = 2, therefore we need such an i (< 5) for which prefix_sum[i] = 3, and at i = 2, prefix_sum[i] = 3, therefore answer is incremented once
At index 3, prefix_sum[3] = 5, therefore there are 2 'i's, i=0 and i=-1(as in including dummy index 0), therefore answer is incremented by 2 (as there are 2 zeroes).
Therefore answer is incremented on following places
    At j=3, twice, as prefix_sum = 5 and there are two '0's (including dummy)  
    At j=6, same as with j=3
    At j=5, twice, prefix_sum = 2 and there are two '-3's
    Therefore answer = 2 + 2 + 2 = 6 
*/

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#define ll long long
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
#define f first
#define s second
#define mp make_pair
#define p pair
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> values(n);
    take_loop_input_in(values,n);
    ll sum = 0,answer = 0;
    map<ll,int> seen_before;
    map<ll,int>::iterator itr;
    seen_before.insert(mp(0,1));
    for(int i=0;i<n;++i){
        sum+=values[i];
        answer+=seen_before[sum-x];
        seen_before[sum]++;
    }
    cout<<answer;
    return 0;
}