#include <iostream>
#include <deque>
#include <vector>
#define display(name) for(auto it: name){cout<<it<<" ";}cout<<"\n"
#define nl cout<<'\n'
#define free_cin_cout cin.sync_with_stdio(false);cout.sync_with_stdio(false)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void dfs(int root, int parent, vector< vector<int> > &adj_list, vector<bool> &visited, vector<int> &parent_of, bool *found, int *start, int *finish){
	if(*found){return;}
	visited[root] = true;
	for(auto vertex: adj_list[root]){
		if(vertex != parent){
			if(visited[vertex] == true){
				*found = true;
				*start = root;
				*finish = vertex;
				return;
			}
			else{
				parent_of[vertex] = root;
				dfs(vertex, root, adj_list, visited, parent_of, found, start, finish);
			}
		}
	}
}

void print_answer(bool found, const vector<int> &parent_of, int start, int finish){
	if(!found){cout<<"IMPOSSIBLE";}
	else{
		deque<int> path;
		path.push_front(start);
		path.push_front(finish);
		while(finish != start){
			finish = parent_of[finish];
			path.push_front(finish);
		}
		cout<<path.size();nl;
		display(path);
	}
}

int main(){
	fastIO;free_cin_cout;
	int n, m, a, b, i = 0;
	cin>>n>>m;
	vector< vector<int> > adj_list(n+1);
	while (i++ < m){
		cin>>a>>b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
	vector<bool> visited(n+1, false);
	vector<int> parent_of(n+1, -1);
	bool found = false;
	int start = -1, finish = -1;
	for(int j = 1; j <=n; ++j){
		if(!visited[j] && !found){dfs(j, 0, adj_list, visited, parent_of, &found, &start, &finish);}
	}
	print_answer(found, parent_of, start, finish);
	return 0;
}
