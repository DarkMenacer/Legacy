#include <iostream>
#include <vector>
#define free_cin_cout cin.sync_with_stdio(false);cout.sync_with_stdio(false)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void dfs(int root, int parent, vector< vector<int> > &adj_list, vector<int> &team_of, bool *impossible){
	if(*impossible){return;}
	team_of[root] = team_of[parent] == 1? 2 : 1; 
	for(auto vertex: adj_list[root]){
		if(team_of[vertex] == team_of[root]){*impossible = true;return;}
		if(vertex != parent && team_of[vertex] == -1){
			dfs(vertex, root, adj_list, team_of, impossible);
		}
	}
}

int main(){
	free_cin_cout;fastIO;
	int n, m, a, b, i = 0;
	cin>>n>>m;
	vector< vector<int> > adj_list(n+1);
	while(i++ < m){
		cin>>a>>b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	vector<int> team_of(n+1, -1);
	bool impossible = false;
	team_of[0] = 2;
	for(int j=1; j<=n; ++j){
		if(team_of[j] == -1){
			dfs(j, 0, adj_list, team_of, &impossible);
		}
		if(impossible){break;}
	}
	if(impossible){cout<<"IMPOSSIBLE";}
	else{
		for(int j=1; j<=n; ++j){cout<<team_of[j]<<" ";}
	}
	return 0;
}
