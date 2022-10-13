#include <vector>
#include <iostream>
#include <numeric>
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
#define all(name) name.begin(),name.end()
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    take_loop_input_in(coins,n);
    int sum = accumulate(all(coins),0);
    vector<int> possible(sum+1,0);
    vector<bool> updated(sum+1,false);
    possible[0] = 1;
    for(auto coin: coins){
        for(int i=0;i<sum+1;++i){
            if(possible[i] == 1 && updated[i] == false && possible[i+coin] == 0){
                possible[i+coin] = 1;
                updated[i+coin] = true;
                
            }
        }
        fill(all(updated),false);
    }
    cout<<accumulate(all(possible),-1)<<endl;
    for(int i = 1;i<sum+1;++i){
        if(possible[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}