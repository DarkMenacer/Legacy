#include <iostream>
using namespace std;
 
bool check(int x, int y){
    if(x<=2*y && y<=2*x){
        if((x-2*y)%3==0){return true;}
    }
    return false;
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        bool flag = check(x,y);
        (flag == true)?cout<<"YES\n":cout<<"NO\n";
    }
    return 0;
}