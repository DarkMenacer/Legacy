#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

void dijstrka(const vector< vector< pair<int, int> > > &adj_list){
	vector<int> distances(adj_list.size(), INF);
	distances[1] = 0;
	vector<bool> visited(adj_list.size(), false);
	priority_queue< pair<int, int> > vertices;
	vertices.push({0, 1});
	while(!vertices.empty()){
		int vertex = vertices.top().second;
		vertices.pop();
		if(!visited[vertex]){
			visited[vertex] = true;
			for(auto edge: adj_list[vertex]){
				distances[edge.first] = min(distances[edge.first], distances[vertex] + edge.second);
				vertices.push({-distances[edge.first], edge.first});
			}
		}
	}
	for(unsigned i=1;i<distances.size();++i){cout<<distances[i]<<" ";}
}


int main(){
	int n, m, a, b, c, i = 0;
	cin>>n>>m;
	vector< vector< pair<int, int> > > adj_list(n+1);
	while(i++ < m){
		cin>>a>>b>>c;
		adj_list[a].push_back({b,c});
	}
	dijstrka(adj_list);
	return 0;
}
