#include <iostream>
#include <stack>
#define p pair
#define mp make_pair

using namespace std;

int main(){
    int n,x;
    cin>>n;
    stack <p<int,int> > low;
    for(int i = 0; i<n; ++i){
        cin>>x;
        if(low.empty()){cout<<0<<" ";}
        else{
            while(low.top().first >= x){
                low.pop();
                if(low.empty()){break;}
            }
            if(low.empty()){cout<<0<<" ";}
            else{cout<<low.top().second<<" ";}
        }
        low.push(mp(x,i+1));
    }
    return 0;
}