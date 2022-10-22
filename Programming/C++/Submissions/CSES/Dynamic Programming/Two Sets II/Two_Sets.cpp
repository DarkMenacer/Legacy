#include <iostream>
#include <vector>
using namespace std;

int main(){
    int mod = 1e9+7;
    int n;
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
    else{cout<<0;}
    return 0;
}