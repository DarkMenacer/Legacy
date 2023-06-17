#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<ll> values(n), prefix_sum(n,0);
    ll sum = 0;
    for(int i=0;i<n;++i){
        cin>>values[i];
        sum+=values[i];
        prefix_sum[i]=sum;
    }
    vector< pair<int,int> > queries(q);
    for(int i=0;i<q;++i){
        int x,y;
        cin>>x>>y;
        queries[i] = make_pair(x-1,y-1);
    }
    for(int i=0;i<q;++i){
        if(queries[i].first < 1){cout<<prefix_sum[queries[i].second]<<endl;}
        else{cout<<prefix_sum[queries[i].second] - prefix_sum[queries[i].first - 1]<<endl;}
    }
    return 0;
}