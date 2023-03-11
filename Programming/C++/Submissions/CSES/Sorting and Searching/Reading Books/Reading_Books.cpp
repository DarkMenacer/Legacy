#include <iostream>
#include <set>
#define ll long long
using namespace std;

int main(){
    ll n,x,time = 0;
    cin>>n;
    multiset<ll, greater <ll>> duration;
    for(ll i=0;i<n;++i){
        cin>>x;
        duration.insert(x);
        time+=x;
    }
    ll time_without_max = time - *duration.begin();
    if(time_without_max < *duration.begin()){time = 2*(*duration.begin());}
    cout<<time;
    return 0;
}