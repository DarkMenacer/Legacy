#include <iostream>
#include <vector>
#include <algorithm>
#define all(name) name.begin(),name.end()
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    take_loop_input_in(coins,n);
    vector<int> memoize(x+1,0);
    memoize[0] = 1;
    sort(all(coins));
    for(int i=0;i<n;++i){
        for(int j=1;j<x+1;++j){
            if(j-coins[i]>=0){
                memoize[j]+=memoize[j-coins[i]];
                memoize[j]%=1000000007;
            }
        }
    }
    cout<<memoize[x];
    return 0;
}

// THIS APPROACH OF USING SET IS SURPRISINGLY SLOWER
/* 
#include <set>

int main(){
    int n,x;
    cin>>n>>x;
    set<int> coins;
    take_loop_input_in(coins,n);
    vector<int> memoize(x+1,0);
    memoize[0] = 1;
    for(auto itr = coins.begin();itr!=coins.end();++itr){
        for(int j=1;j<x+1;++j){
            if(j-*itr>=0){
                memoize[j]+=memoize[j-*itr];
                memoize[j]%=1000000007;
            }
        }
    }
    cout<<memoize[x];
    return 0;
} */