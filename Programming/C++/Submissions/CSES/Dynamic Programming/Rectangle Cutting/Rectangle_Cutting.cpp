#include <iostream>
#include <vector>
#define inf 1e9
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    vector< vector<int> > memoize(a+1, vector<int>(b+1));
    for(int i=0;i<a+1;++i){
        for(int j=0;j<b+1;++j){
            if(i==j){memoize[i][j] = 0;}
            else{memoize[i][j] = inf;}
        }
    }
    for(int i=0; i<a+1;++i){
        for(int j=0; j<b+1;++j){
            for(int k=0;k<i;++k){
                memoize[i][j] = min(memoize[i][j], memoize[i-k][j] + memoize[k][j] + 1);
            }
            for(int k=0;k<j;++k){
                memoize[i][j] = min(memoize[i][j], memoize[i][j-k] + memoize[i][k] + 1);
            }
        }
    }
    cout<<memoize[a][b];
    return 0;
}