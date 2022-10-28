#include <iostream>
using namespace std;
 
void check(int n){
    if(n%4==1 || n%4==2){
        cout<<"NO";exit(0);
    }
}
 
int main(){
    int n;
    cin>>n;
    check(n);
    cout<<"YES\n";
    if(n%2==0){
        cout<<n/2<<"\n";
        for(int i = 1;i<=n/4;++i){cout<<i<<" ";}
        for(int i = n-n/4 + 1;i<=n;++i){cout<<i<<" ";}
        cout<<endl;
        cout<<n/2<<"\n";
        for(int i = n/4+1;i<=n-n/4;++i){cout<<i<<" ";}
    }
    else{
        cout<<(n+1)/2<<"\n";
        for(int i=1;i<=(n+1)/4;++i){cout<<i<<" ";}
        cout<<(n+1)/2<<" ";
        for(int i= n-((n+1)/4 - 2);i<=n;++i){cout<<i<<" ";}
        cout<<endl<<(n-1)/2<<"\n";
        for(int i = (n+1)/4 + 1 ;i<n-((n+1)/4 - 2);++i){if(i!= (n+1)/2){cout<<i<<" ";}}
    }
    return 0;