#include <iostream>
#include <vector>
#include <tuple>
#define nl cout<<'\n'
#define INF 1e9
#define display(name) cout<<#name<<": ";for(auto it: name){cout<<it<<" ";}cout<<"\n"
using namespace std;
void bellman_ford(const vector< tuple<int, int, int> > &edges, vector<int> &distances){
	distances[1] = 0;
	for(unsigned i = 1; i < edges.size()-1; ++i){
		for(auto edge: edges){
			distances[get<1>(edge)] = max(distances[get<1>(edge)], get<2>(edge) + distances[get<0>(edge)]);
		}
	}
	for(auto edge: edges){
		if(distances[get<1>(edge)] < get<2>(edge) + distances[get<0>(edge)]){cout<<-1;nl;return;}
	}
	display(distances);
}

int main(){
	int n, m, a, b, c, i=0;
	cin>>n>>m;
	vector< tuple<int, int, int> > edges;
	while(i++ < m){
		cin>>a>>b>>c;
		edges.push_back({a,b,c});
	}
	vector<int> distances(n+1, -INF);
	bellman_ford(edges, distances);
	return 0;
}
