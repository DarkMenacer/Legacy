#include <iostream>
#include <vector>
#define G1 0
#define G2 1
#define G3 2
#define G4 3
#define TOT_GRPS 4
#define ll long long
using namespace std;

int main(){
    ll mod = 1e9 + 7;
    vector< vector<ll> > memoize(1e6 + 1, vector<ll>(TOT_GRPS));
    for(int j=0;j<TOT_GRPS;++j){
        memoize[0][j] = 0;
        memoize[1][j] = 0;
    }
    memoize[1][1] = 1;
    memoize[1][2] = 1;
    for(int i=2;i<1e6+1;++i){
        (memoize[i][G1] = 4*(memoize[i-1][G1] + memoize[i-1][G3]))%=mod;
        (memoize[i][G2] = memoize[i-1][G1] + memoize[i-1][G3])%=mod;
        (memoize[i][G3] = memoize[i-1][G2] + memoize[i-1][G4])%=mod;
        (memoize[i][G4] = 2*(memoize[i-1][G2] + memoize[i-1][G4]))%=mod;
    }
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll answer = 0;
        for(int j=0;j<TOT_GRPS;++j){
            (answer+=memoize[n][j])%=mod;
        }
        cout<<answer<<endl;
    }
    return 0;
}