

#include <iostream>
#include <vector>
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> x(n);
    take_loop_input_in(x,n);
    vector< vector<int> > memoize(n, vector<int>(m+1,0));
    if(x[n-1]){
        memoize[n-1][x[n-1]] = 1;
    }
    else{
        vector<int> temp(m+1,1);
        temp[0] = 0;
        memoize[n-1] = temp;
    }

    int answer = 0;
    int mod = 1e9 + 7;
    for(int i=n-2;i>=0;--i){
        if(x[i]){
            //memoize[i][x[i]] = memoize[i+1][x[i]-1] + memoize[i+1][x[i]] + memoize[i+1][x[i]+1];
            (memoize[i][x[i]] += memoize[i+1][x[i]-1])%=mod;
            (memoize[i][x[i]] += + memoize[i+1][x[i]])%=mod;
            (memoize[i][x[i]] += memoize[i+1][x[i]+1])%=mod;
            //if(!i){answer=memoize[i][x[i]];}
        }
        else{
            for(int j=1;j<m+1;++j){
                //memoize[i][j] = memoize[i+1][j-1] + memoize[i+1][j] + memoize[i+1][j+1];
                (memoize[i][j] += memoize[i+1][j-1])%=mod;
                (memoize[i][j] += memoize[i+1][j])%=mod;
                (memoize[i][j] += memoize[i+1][j+1])%=mod;
                //if(!i){(answer+=memoize[i][j])%=mod;}
            }
        }
    }
    for(int j=1;j<m+1;++j){
        (answer+=memoize[0][j])%=mod;
    }

    cout<<answer%mod;
    return 0;
}