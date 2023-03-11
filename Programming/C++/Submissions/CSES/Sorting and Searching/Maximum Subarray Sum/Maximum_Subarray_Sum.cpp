#include <iostream>
#include <vector>
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define pb push_back
#define ll long long
using namespace std;
 
ll give_me_answer(vector<ll> &values){
    ll max_sum = values[0], sum = max_sum;
    unsigned i;
    FOR(i,1,values.size()){
        sum = max(sum + values[i], values[i]);
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}
 
int main(){
    int n,i,x;
    cin>>n;
    vector<ll> values;
    FOR(i,0,n){
        cin>>x;
        values.pb(x);
    }
    cout<<give_me_answer(values);
    return 0;
}