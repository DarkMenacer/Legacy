#include <iostream>
#include <vector>
#include <numeric>
#define all(name) name.begin(),name.end()
#define ll long long
#define INF 1e18
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
using namespace std;

ll solve(int left, int right, vector<int> &values, vector< vector<ll> > &memoize){
    if(left == right){memoize[left][right] = values[left];}
    else{if(memoize[left][right] == INF){memoize[left][right] = max(values[left] - solve(left+1,right,values, memoize), values[right] - solve(left,right-1,values,memoize));}}
    return memoize[left][right];
}

int main(){
    int n;
    cin>>n;
    vector<int> values(n);
    take_loop_input_in(values,n);
    vector< vector<ll> > memoize (n, vector<ll>(n,INF));
    

    // accumulate function interprets the value through the last digit, i.e. sum ≠ sum2 ≠ sum3
    ll sum = accumulate(all(values),0);
    ll sum2 = accumulate(all(values),(long long)0);
    ll sum3 = accumulate(all(values),0.0);

    cout<<(sum + solve(0,n-1,values,memoize))/2;
    return 0;
}