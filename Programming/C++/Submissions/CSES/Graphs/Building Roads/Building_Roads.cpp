#include <iostream>
#include <vector>
#include <algorithm>
#define all(name) name.begin(),name.end()
#define nl cout<<'\n'
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void dfs(int root, int parent, vector< vector<int> > &adj_list, vector<bool> &visited){
	visited[root] = true;
	if(adj_list[root].size() == 1 && adj_list[root][0] == parent){return;}
	for(auto element: adj_list[root]){
		if(element != parent && visited[element] == false){
			dfs(element, root, adj_list, visited);
		}
	}
}

vector< pair<int, int> > give_me_answer(vector< vector<int> > &adj_list){
	vector<bool> visited(adj_list.size(), false);
	vector< pair<int, int> >returner;
	vector<int> connectors;
	dfs(1, 0, adj_list, visited);
	for(unsigned i = 2; i < adj_list.size(); ++i){
		if(!visited[i]){
			connectors.push_back(i);
			dfs(i, 0, adj_list, visited);
		}
	}
	transform(all(connectors),back_inserter(returner) , [](const int &connector){return make_pair(1, connector);});
	return returner;
}

int main(){
	fastIO;
	int n, m, a, b, i = 0;
	cin>>n>>m;
	vector< vector<int> > adj_list(n+1);
	while(i++ < m){
		cin>>a>>b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	vector<pair<int, int> > answer = give_me_answer(adj_list);
	cout<<answer.size();nl;
	for(auto element: answer ){
		cout<<element.first<<" "<<element.second;nl;
	}
	return 0;
}
