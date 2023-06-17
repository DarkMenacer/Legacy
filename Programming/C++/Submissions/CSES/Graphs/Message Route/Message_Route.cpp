#include <iostream>
#include <vector>
#include <deque>
#define nl cout<<'\n'
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void bfs(int root, int parent, vector< vector<int> > &adj_list, vector<int> &visited, vector<int> &parent_of, deque<int> &bfs_queue){
	visited[root] = 2;
	if(visited[adj_list.size()-1] == 2 || bfs_queue.empty()){return;}
	bfs_queue.pop_front();
	for(auto vertex: adj_list[root]){
		if(!visited[vertex]){
			bfs_queue.push_back(vertex);
			parent_of[vertex] = root;
			visited[vertex] = 1;
		}
	}
	if(!bfs_queue.empty()){
		bfs(bfs_queue[0], parent_of[bfs_queue[0]], adj_list, visited, parent_of, bfs_queue);
	}
}

void print_answer(bool possible, const vector<int> &parent_of){
	if(possible){
		deque<int> printer;
		int x = parent_of.size()-1;
		while(x != -1){
			printer.push_front(x);
			x = parent_of[printer[0]];
		}
		cout<<printer.size();nl;
		for(auto vertex: printer){cout<<vertex<<" ";}
	}
	else{cout<<"IMPOSSIBLE\n";}
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
	vector<int> visited(n+1, 0);
	vector<int> parent_of(n+1, -1);
	deque<int> bfs_queue{1};
	bfs(1, 0, adj_list, visited, parent_of, bfs_queue);
	print_answer(visited[n], parent_of);
	return 0;
}
