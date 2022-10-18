#include <iostream>
#include <vector>
#define all(name) name.begin(),name.end()
#define ll long long
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<ll> values(n);
    take_loop_input_in(values,n);
    vector< vector<ll> > memoize (n, vector<ll>(n));
    ll sum = 0;
    for(int i=0;i<n;++i){
        memoize[i][i] = values[i];
        sum+=values[i];
    }
    for(int i = n-1;i>=0;--i){
        for(int j = i+1;j<n;++j){
            memoize[i][j] = max(values[i] - memoize[i+1][j], values[j] - memoize[i][j-1]);
        }
    }
    cout<<(sum + memoize[0][n-1])/2;
    return 0;
}