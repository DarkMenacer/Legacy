/*
Name:-              Array Division
Platform:-          CSES
Date:-              25 May 2022
Type of Problem:-   Binary Search
Complexity:-        O(nlog(n))
Status:-            Solved

Solution in brief:
Few points which are observed:
1) For an arbitrarily large value of k as well, the answer will atleast be as big as the max value of the array
2) For k=1, the answer will be the sum of all of the elements in the array
Therefore answer lies between max and sum of the array
Now, let the answer be 'ans'
Therefore we know that all the subarray sums are less than equal to ans.
Therefore all the subarray sums are less than equal to ans+y (any arbitrary y).
And there exists atleast one subarray with sum greater than ans-1. (and thereby ans-y)
Therefore we use binary search to find such an ans.
We use the fact that if the array uses more partitions than what is allowed (k), 
then there is a subarray with sum greater than current choice of ans.
Hence ans will have the property that, number of partitions, when ans is max_allowed_subarray_sum = k
and no. of partitions when ans-1 is the max_allowed_subarray_sum > k.

Sample to understand solution:
Input:-
5 3
2 7 4 3 4

Output:-
9

Explanation:-
for ans = 7 ==== 2 | 7 | 4 3 | 4  => 4 partitions
for ans = 12 ==== 2 7 | 4 3 4 => 2 partitions
for ans = 10 ==== 2 7 | 4 3 | 4 => 3 partitions
for ans = 9 ==== 2 7 | 4 3 | 4 => 3 partitions
for ans = 8 ==== 2 | 7 | 4 3 | 4 => 4 partitions

Therefore 9 is the answer.

*/

#include <iostream>
#include <vector>
#define ll long long
#define nl cout<<'\n';
using namespace std;

ll partitions(vector<ll> &values, ll max_sum, int k){
    ll answer = 0, sub_array_sum = 0;
    for(ll i=0;i<values.size();++i){
        if(values[i] > max_sum){return k+1;}
        if(sub_array_sum + values[i] > max_sum){sub_array_sum = 0; answer++;}
        sub_array_sum += values[i];
    }
    return answer+1;
}

ll give_me_answer(vector<ll> values, ll k, ll maxm, ll sum){
    ll low = maxm, high = sum, mid, part1;
    if(k==1){return sum;}
    while(low < high){
        mid = (low + high)/2;
        part1 = partitions(values,mid,k);
        if(part1 <= k){
            int part2 = partitions(values,mid-1,k);
            if(part2 > k){return mid;}
            else{high = mid;}
        }
        else{low = mid;}
    }
    if(values.size()==1){return values[0];}
} 

int main(){
    ll n,k, maxm = 0, sum = 0;
    cin>>n>>k;
    vector<ll> values(n);
    for(ll i=0;i<n;++i){
        cin>>values[i];
        sum+=values[i];
        maxm = max(maxm,values[i]);
    }
    cout<<give_me_answer(values,k,maxm,sum);
    return 0;
}