#include <iostream>
#include <vector>
#include <queue>
#define free_cin_cout cin.sync_with_stdio(false);cout.sync_with_stdio(false)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define INF 1e16
using namespace std;

void dijstrka(const vector< vector< pair<ll, ll> > > &adj_list){
	vector<ll> distances(adj_list.size(), INF);
	distances[1] = 0;
	vector<bool> visited(adj_list.size(), false);
	priority_queue< pair<ll, ll> > vertices;
	vertices.push({0, 1});
	while(!vertices.empty()){
		ll vertex = vertices.top().second;
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
	fastIO;free_cin_cout;
	ll n, m, a, b, c, i = 0;
	cin>>n>>m;
	vector< vector< pair<ll, ll> > > adj_list(n+1);
	while(i++ < m){
		cin>>a>>b>>c;
		adj_list[a].push_back({b,c});
	}
	dijstrka(adj_list);
	return 0;
}
