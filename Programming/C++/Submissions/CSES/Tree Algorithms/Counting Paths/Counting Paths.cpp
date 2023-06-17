#include <iostream>
#include <vector>
#include <map>
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define free_cin_cout cin.sync_with_stdio(false);cout.sync_with_stdio(false)
using namespace std;

void preprocess(int root, int parent, vector< vector<int> > &adj_list, vector< vector<int> > &ancestors_of, vector<int> &level_of, int level){
	level_of[root]  = level;
	unsigned i = 0;
	int ancestor = parent;
	while(parent != 0){
		ancestors_of[root].push_back(ancestor);
		if(ancestors_of[ancestor].size() < i+1){break;}
		 ancestor = ancestors_of[ancestor][i++];
	}
	if(adj_list[root].size() == 1 && adj_list[root][0] == parent){return;}

	for(auto vertex: adj_list[root]){
		if(vertex != parent){
			preprocess(vertex, root, adj_list, ancestors_of, level_of, level+1);
		}
	} 

}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int adjust_levels(int a, int b,vector<int> &level_of, vector< vector<int> > &ancestors_of){
	while(level_of[a] != level_of[b]){
		unsigned i = ancestors_of[a].size() - 1;
		while(level_of[ancestors_of[a][i]] < level_of[b]){--i;}
		a = ancestors_of[a][i];
	}
	return a;
}

int least_common_ancestor(int a, int b, vector<int> &level_of, vector< vector<int> > &ancestors_of){
	if(level_of[a] < level_of[b]){swap(&a, &b);}
	if(level_of[a] != level_of[b]){a = adjust_levels(a, b, level_of, ancestors_of);}	
	if(a==b){return a;}
	while(!(a != b && ancestors_of[a][0] == ancestors_of[b][0])){
		unsigned i = ancestors_of[a].size()-1;
		while(ancestors_of[a][i] == ancestors_of[b][i]){--i;}
		a = ancestors_of[a][i]; b = ancestors_of[b][i];
	}
	return ancestors_of[a][0];
}

void calculate_answer(int root, int parent, vector< vector<int> > &adj_list, map<int, int> &end_points, map<int, int> &path_count_for_lca, vector<int> &answer){
	for(auto vertex: adj_list[root]){
		if(vertex != parent){
			calculate_answer(vertex, root, adj_list, end_points, path_count_for_lca, answer);
			answer[root] += (answer[vertex] - path_count_for_lca[vertex]);
		}
	}
	answer[root] += (end_points[root] - path_count_for_lca[root]);
}

int main(){
	fastIO;free_cin_cout;
	int n,m,a,b;
	cin>>n>>m;
	vector <vector<int> > adj_list(n+1), ancestors_of(n+1);
	vector<int> level_of(n+1), answer(n+1);
	map<int, int> end_points, path_count_for_lca;

	while(--n){
		cin>>a>>b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	preprocess(1, 0, adj_list, ancestors_of, level_of, 1);

	while(m--){
		cin>>a>>b;
		path_count_for_lca[least_common_ancestor(a,b,level_of, ancestors_of)]++;
		end_points[a]++;
		end_points[b]++;
	}

	calculate_answer(1, 0, adj_list, end_points, path_count_for_lca, answer);

	for(unsigned i = 1; i<answer.size(); ++i){cout<<answer[i]<<" ";}

	return 0;
}
