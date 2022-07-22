#include <iostream>
using namespace std;

void swap(int *a, int *b){int temp = *a;*a=*b;*b=temp;}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b){swap(&a,&b);}
        int n = (b-a)*2;
        if(n<max(b,c)){cout<<-1<<endl;continue;}
        if(c>=n/2 + 1){cout<<c-n/2<<endl;}
        else{cout<<n/2+c<<endl;}
    }    
    return 0;
}