#include <iostream>
#include <vector>
using namespace std;

void foo(int x, int y,int n, vector< vector<int> > &memoize, vector< vector<char> > &grid){
    if(x == 0 && y == 0){return;}
    if(grid[x][y] == '.' && x-1 >= 0 && y-1 >= 0){
        memoize[x][y] = memoize[x-1][y] + memoize[x][y-1];
    }
    else if(grid[x][y] == '.' && y-1 < 0){
        memoize[x][y] = memoize[x-1][y];
    }
    else if(grid[x][y] == '.' && x-1 < 0){
        memoize[x][y] = memoize[x][y-1];
    }
    memoize[x][y] %= (1000000007);
}

int main(){
    int n;
    cin>>n;
    vector< vector<char> > grid(n);
    for(int i=0;i<n;++i){
        vector<char> temp(n);
        for(int j=0;j<n;++j){cin>>temp[j];}
        grid[i] = temp;
    }
    vector< vector<int> > memoize(n);
    vector<int> temp(n,0);
    for(int i = 0;i<n;++i){memoize[i] = temp;}
    if(grid[0][0]!='*'){memoize[0][0] = 1;}
    else{cout<<0;return 0;}
    int i,j,k;
    for(k=0; k<n;++k){
        i = k;
        for(int j=i;j<n;j++){foo(i,j,n,memoize,grid);}
        j = k;
        for(int i=j;i<n;++i){foo(i,j,n,memoize,grid);}
    }
    int answer = memoize[n-1][n-1] % (1000000007);
    cout<<answer;
    return 0;
}