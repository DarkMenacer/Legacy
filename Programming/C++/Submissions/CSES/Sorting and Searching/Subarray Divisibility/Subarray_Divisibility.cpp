#include <vector>
#include <iostream>
#define ll long long
#define vl vector<ll>
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
using namespace std;

int main(){
    int n;
    cin>>n;
    vl integers(n);
    take_loop_input_in(integers,n);
    vl remainder(n);
    ll sum = 0, answer = 0;
    remainder[0]++;
    for(int i=0;i<n;++i){
        sum+=integers[i];
        remainder[(sum%n + n)%n]++;
    }
    for(int i=0;i<n;++i){
        if(remainder[i]){
            ll x = remainder[i];
            answer+= x*(x-1)/2;
        }
    }
    cout<<answer;
    return 0;
}