#include <vector>
#include <iostream>
#include <algorithm>
#define all(name) name.begin(),name.end()
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
#define inf 1e9
#define nl cout<<'\n'
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    take_loop_input_in(coins, n);
    auto itr = min_element(all(coins));
    if(*itr > x+1){cout<<-1;exit(0);}
    vector<int> memoizer(x+1,inf);
    memoizer[0] = 0;
    for(int i = 1;i < *itr; ++i){memoizer[i] = -1;}
    for(int i = 0;i < n; ++i){memoizer[coins[i]] = 1;}
    for(int i = 0;i < x+1; ++i){
        if(memoizer[i] != inf){continue;}
        else{
            for(int j=0;j<n;++j){
                if(i-coins[j] >= 0){
                    if(memoizer[i-coins[j]] != -1){memoizer[i] = min(memoizer[i],memoizer[i-coins[j]] + 1);}
                }
            }
            if(memoizer[i] == inf){memoizer[i] = -1;}
        }
    }
    cout<<memoizer[x];nl;
    return 0;
}