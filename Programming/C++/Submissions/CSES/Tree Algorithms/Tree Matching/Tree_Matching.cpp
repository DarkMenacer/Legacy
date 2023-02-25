#include <iostream>
#include <vector>
#define display_2d(name, x, y) for(int i=0;i<x;++i){cout<<i<<": ";for(int j=0;j<y;++j){cout<<name[i][j]<<" ";}cout<<'\n';}
using namespace std;

int solve(int x, vector< vector<int> > &adj_list, vector< vector<int> > &memoize, int parent){
    if(memoize[x][0] == -1){
        memoize[x][0] = 0;
        memoize[x][1] = 0;
        if(adj_list[x].size() != 1 || x==1){

            for(auto vertex: adj_list[x]){
                if(vertex != parent){
                    memoize[x][0] += solve(vertex, adj_list, memoize, x);
                }
            }
            
            for(auto s: adj_list[x]){
                if(s != parent){
                    memoize[x][1] = max(memoize[x][1] , memoize[x][0] + memoize[s][0] - solve(s, adj_list, memoize, x) + 1);
                }
            }

        }
    }
    return max(memoize[x][0], memoize[x][1]);
}


int main(){
    int n;
    cin>>n;
    vector< vector<int> > adj_list(n+1);
    int i = 1;
    while(i<n){
        int a, b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
        i++;
    }

    vector< vector<int> > memoize(n+1, {-1, -1});
    cout<<solve(1,adj_list,memoize, 0)<<endl;
    // display_2d(memoize, n+1, 2);

    return 0;
}
