#include <vector>
#include <iostream>
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
#define all(name) name.begin(),name.end()
using namespace std;

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> price(n), pages(n), temp(x+1,0);
    take_loop_input_in(price,n);
    take_loop_input_in(pages,n);
    vector< vector<int> > memoize(n+1);
    for(int i=0;i<n+1;++i){memoize[i] = temp;}
    for(int i=0;i<n;++i){
        for(int j=0;j<x+1;++j){
            if(memoize[i][j] != 0){
                memoize[i+1][j] = memoize[i][j]; 
            }
            if(j>=price[i]){
                memoize[i+1][j] = max(memoize[i+1][j], pages[i] + memoize[i][j-price[i]]);
            }
        }
    }
    cout<<memoize[n][x];
    return 0;
}