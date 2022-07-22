#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int k,r,c;
        cin>>k;
        int min = sqrt(k),max = sqrt(k)+1;
        if(round(sqrt(k))-sqrt(k)==0){
            r = min;
            c = 1;
            cout<<r<<" "<<c<<endl;
            continue;
        }
        if(k>(min*min)+max){
            r = max;
            c = max - (k - (min*min+max));
            cout<<r<<" "<<c<<endl;
        }
        else{
            c = max;
            r = (k-(min*min));
            cout<<r<<" "<<c<<endl;
        }
    }    
    return 0;
}