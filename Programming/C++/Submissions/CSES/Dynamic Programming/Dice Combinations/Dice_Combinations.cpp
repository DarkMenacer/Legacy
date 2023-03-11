#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long mod = 1e9 + 7;
    vector<long long> memoize(n+1);
    memoize[0] = 0;
    memoize[1] = 1;
    long long total = 1;
    for(int i=2;i<n+1;++i){
        if(i<7){memoize[i] = total + 1;}
        else{memoize[i] = total % mod;total-=memoize[i-6];}
        total+=memoize[i];
    }
    cout<<memoize[n];
    return 0;
}