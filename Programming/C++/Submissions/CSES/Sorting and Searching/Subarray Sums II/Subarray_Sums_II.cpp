#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#define ll long long
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> values(n);
    take_loop_input_in(values,n);
    ll sum = 0,answer = 0;
    map<ll,int> seen_before;
    seen_before[0] = 1;
    for(int i=0;i<n;++i){
        sum+=values[i];
        answer+=seen_before[sum-x];
        seen_before[sum]++;
    }
    cout<<answer;
    return 0;
}