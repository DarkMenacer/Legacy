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