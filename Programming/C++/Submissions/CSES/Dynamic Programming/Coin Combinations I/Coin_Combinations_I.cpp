#include <iostream>
#include <vector>
#include <algorithm>
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
#define all(name) name.begin(),name.end()
#define display(name) for(auto it: name){cout<<it<<" ";}cout<<"\n"
using namespace std;

int main(){
    long long mod = 1e9 + 7;
    long long n,x;
    cin>>n>>x;
    vector<long long> coins(n);
    take_loop_input_in(coins,n);
    auto itr = min_element(all(coins));
    if(*itr > x){cout<<0;exit(0);}
    vector<long long> memoizer(x+1,0);
    memoizer[0] = 1;
    for(int i = *itr;i<x+1;++i){
        for(int j=0;j<n;++j){
            if(i>=coins[j]){memoizer[i]+=memoizer[i-coins[j]];}
        }
        memoizer[i]%=mod;
    }
    cout<<memoizer[x]<<endl;
    display(memoizer);
    return 0;
}