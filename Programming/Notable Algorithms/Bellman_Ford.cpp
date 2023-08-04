/*
   Pranav Chatur
   Bellman-Ford Algorithm to find the shortest distance from the root vertex to all other vertices
   23 July 2023

   input:
   6 8
   1 2 2
   1 3 5
   2 4 1
   2 6 3
   2 5 1
   4 3 1
   4 6 3
   6 5 1

   where there are 6 vertices and 8 edges and all subsequent lines are the directed edges {a, b, c} 
   		where a is source, b is destination and c is the weight

   output:
   0 2 4 3 3 5

*/
#include <iostream>
#include <vector>
#include <tuple>
#define INF 1e9
using namespace std;

void give_me_answer(int n, const vector< tuple<int, int, int> > &edges){
	vector<int> distances(n+1, INF);
	int root = 1;
	distances[root] = 0;
	for(int i=1; i<edges.size()-1; ++i){ //loop m-1 times
		for(auto edge: edges){
			distances[get<1>(edge)] = min(distances[get<1>(edge)], distances[get<0>(edge)] + get<2>(edge));
		}
	}
	for(int i=1; i<n+1; ++i){cout<<distances[i]<<" ";}
}

int main(){
	int n, m, a, b, c, i = 0;
	cin>>n>>m;
	vector< tuple<int, int, int> > edges;
	while(i++ < m){
		cin>>a>>b>>c;
		edges.push_back({a, b, c});
	}
	give_me_answer(n, edges);
	return 0;
}

	
