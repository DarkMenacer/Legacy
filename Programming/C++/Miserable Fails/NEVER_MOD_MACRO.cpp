#include <iostream>
#include <vector>
#define all(name) name.begin(),name.end()
#define ll long long
#define INF 1e9
//#define mod 100000007   USING THIS GIVES WRONG ANSWER
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
#define take_indexed_loop_input(name,size) for(int i=1;i<size+1;++i){int x;cin>>x;name.push_back(make_pair(x,i));}
#define here cout<<"here\n"
#define display(name) for(auto it: name){cout<<it<<" ";}cout<<"\n"
#define display_2d(name, x, y) for(int i=0;i<x;++i){for(int j=0;j<y;++j){cout<<name[i][j]<<" ";}cout<<'\n';}
#define what_is_here(name) cout<<#name<<": "<<name<<"\n"
using namespace std;

int main(){
    int n;
    //int mod = 1e9+7;  USING THIS GIVES THE CORRECT ANSWER
    cin>>n;
    if((n*(n+1)/2)%2 == 0){
        int set_sum = n*(n+1)/4;
        vector< vector<int> > memoize(n,vector(set_sum+1,0));
        memoize[0][0] = 1;
        for(int i=1;i<n;++i){
            for(int j=0;j<set_sum+1;++j){
                if(i>j){
                    memoize[i][j] = memoize[i-1][j] % mod;
                }
                else{
                    (memoize[i][j] = (memoize[i-1][j-i] + memoize[i-1][j])) %= mod;
                }
            }
        }
        cout<<memoize[n-1][set_sum];
    }
    else{
        cout<<0;
    }
    return 0;
}