#include <iostream>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    if(n<4 && n!= 1){
        cout<<"NO SOLUTION";
        exit(0);
    }
    int num;
    if(n%2==0){num = 0;}
    else{num = 0;}
    for(int i=0;i<n;++i){
        num+=2;
        if(num>n){num = 1;}
        cout<<num<<" ";
    }
    return 0;