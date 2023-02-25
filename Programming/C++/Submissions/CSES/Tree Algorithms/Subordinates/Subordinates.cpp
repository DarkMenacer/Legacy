#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int> > &subordinates, vector<int> &memoise, int x){
    if(subordinates[x].size() == 0){
        memoise[x] = 0;
        return;
    }
    memoise[x] = 0;
    for(auto junior: subordinates[x]){
        if(memoise[junior] == -1){
            dfs(subordinates, memoise, junior);
        }
        memoise[x]+=(memoise[junior]+1);
    }
}

int main(){
    int n, boss;
    cin>>n;
    vector<vector<int> > subordinates(n+1);
    for(int i=2; i<n+1; ++i){
        cin>>boss;
        subordinates[boss].push_back(i);
    }
    vector<int> memoise(n+1,-1);
    dfs(subordinates, memoise, 1);
    for(int i=1;i<n+1;++i){
        cout<<memoise[i]<<" ";
    }

    return 0;
}