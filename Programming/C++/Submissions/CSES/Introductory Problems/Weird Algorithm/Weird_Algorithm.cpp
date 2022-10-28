#include <iostream>
#define ll long long
using namespace std;
 
int main(){
    ll x;
    cin>>x;
    while(x!=1){
        cout<<x<<" ";
        if(x%2==0){x = x /2;}
        else{x = x*3 + 1;}
    }
    cout<<1;
    return 0;
}