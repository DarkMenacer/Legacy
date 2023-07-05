#include <iostream>
#include <vector>
#include <deque>
#define nl cout<<'\n'
#define free_cin_cout cin.sync_with_stdio(false);cout.sync_with_stdio(false)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void print_path(int length, pair<int, int> start, pair<int, int> stop, const vector< vector<pair<int, int> > > &parent_of){
	cout<<"YES\n"<<length;nl;
	deque<char> path;
	while(stop != start){
		if(parent_of[stop.first][stop.second].second < stop.second){path.push_front('R');}
		else if(parent_of[stop.first][stop.second].first > stop.first){path.push_front('U');}
		else if(parent_of[stop.first][stop.second].second > stop.second){path.push_front('L');}
		else if(parent_of[stop.first][stop.second].first < stop.first){path.push_front('D');}
		stop = parent_of[stop.first][stop.second];
	}
	for(auto direction: path){cout<<direction;}
}

void monster_bfs(pair<int, int> target, const vector< vector<char> > &labyrinth, deque< pair<int, int> > bfs_queue, vector< vector<int> > &visited, bool *found, vector< vector<int> > &distance){
	if(*found || bfs_queue.empty()){return;}
	pair <int, int> root = bfs_queue[0];
	bfs_queue.pop_front();
	visited[root.first][root.second] = 2;
	if(root == target){
		*found = true;
		return;
	}
	if(root.second + 1 < labyrinth[0].size() && labyrinth[root.first][root.second + 1] != '#' && !visited[root.first][root.second+1]){
		bfs_queue.push_back({root.first, root.second + 1});
		visited[root.first][root.second + 1] = 1;
		distance[root.first][root.second + 1] = distance[root.first][root.second] + 1;
	}
	if(root.first - 1 >= 0  && labyrinth[root.first - 1][root.second] != '#' && !visited[root.first - 1][root.second]){
		bfs_queue.push_back({root.first - 1, root.second});
		visited[root.first - 1][root.second] = 1;
		distance[root.first - 1][root.second] = distance[root.first][root.second] + 1;
	}
	if(root.second - 1 >= 0 && labyrinth[root.first][root.second - 1] != '#' && !visited[root.first][root.second - 1]){
		bfs_queue.push_back({root.first, root.second - 1});
		visited[root.first][root.second - 1] = 1;
		distance[root.first][root.second - 1] = distance[root.first][root.second] + 1;
	}
	if(root.first + 1 < labyrinth.size() && labyrinth[root.first + 1][root.second] != '#' && !visited[root.first + 1][root.second]){
		bfs_queue.push_back({root.first + 1, root.second});
		visited[root.first + 1][root.second] = 1;
		distance[root.first + 1][root.second] = distance[root.first][root.second] + 1;
	}
	monster_bfs(target, labyrinth, bfs_queue, visited, found, distance);
}

void bfs(pair<int, int> start, const vector< vector<char> > &labyrinth, const vector< pair<int, int> > &monsters, deque< pair<int, int> > bfs_queue, vector< vector<int> > &visited, vector< vector<int> > &distance, vector< vector< pair<int, int> > > &parent_of, bool *found){
	if(*found || bfs_queue.empty()){return;}
	pair <int, int> root = bfs_queue[0];
	bfs_queue.pop_front();
	visited[root.first][root.second] = 2; 

	if(root.first == labyrinth.size() - 1 || root.first == 0 || root.second == labyrinth[0].size() - 1 || root.second == 0){
		bool found_safe_point = true;
		for(auto monster: monsters){
			bool found_target = false;
			deque< pair<int, int> > monster_queue({monster});
			vector< vector<int> > monster_visited(labyrinth.size(), vector<int>(labyrinth[0].size(), 0)); 
			vector< vector<int> > monster_distance(labyrinth.size(), vector<int>(labyrinth[0].size(), 0));
			monster_bfs(root, labyrinth, monster_queue, monster_visited, &found_target, monster_distance);
			if(distance[root.first][root.second] >= monster_distance[root.first][root.second] && monster_distance[root.first][root.second] != 0){
				found_safe_point = false;
				break;
			}
		}
		if(found_safe_point){
			*found = true;
			print_path(distance[root.first][root.second], start, root, parent_of);
			return;
		}
	}

	if(root.second + 1 < labyrinth[0].size() && labyrinth[root.first][root.second + 1] == '.' && !visited[root.first][root.second+1]){
		bfs_queue.push_back({root.first, root.second + 1});
		parent_of[root.first][root.second + 1] = root;
		visited[root.first][root.second + 1] = 1;
		distance[root.first][root.second + 1] = distance[root.first][root.second] + 1;
	}
	if(root.first - 1 >= 0  && labyrinth[root.first - 1][root.second] == '.' && !visited[root.first - 1][root.second]){
		bfs_queue.push_back({root.first - 1, root.second});
		parent_of[root.first - 1][root.second] = root;
		visited[root.first - 1][root.second] = 1;
		distance[root.first - 1][root.second] = distance[root.first][root.second] + 1;
	}
	if(root.second - 1 >= 0 && labyrinth[root.first][root.second - 1] == '.' && !visited[root.first][root.second - 1]){
		bfs_queue.push_back({root.first, root.second - 1});
		parent_of[root.first][root.second - 1] = root;
		visited[root.first][root.second - 1] = 1;
		distance[root.first][root.second - 1] = distance[root.first][root.second] + 1;
	}
	if(root.first + 1 < labyrinth.size() && labyrinth[root.first + 1][root.second] == '.' && !visited[root.first + 1][root.second]){
		bfs_queue.push_back({root.first + 1, root.second});
		parent_of[root.first + 1][root.second] = root;
		visited[root.first + 1][root.second] = 1;
		distance[root.first + 1][root.second] = distance[root.first][root.second] + 1;
	}
	bfs(start, labyrinth, monsters, bfs_queue, visited, distance, parent_of, found);
}

void give_me_answer(const pair<int, int> start, const vector< vector<char> > &labyrinth, const vector< pair<int, int> > &monsters){
	deque< pair<int, int> > bfs_queue ({start});
	vector< vector<int> > visited(labyrinth.size(), vector<int> (labyrinth[0].size(), 0)), distance(labyrinth.size(), vector<int> (labyrinth[0].size(), 0));
	vector< vector< pair<int, int> > > parent_of(labyrinth.size(), vector< pair<int, int> > (labyrinth[0].size(), {-1, -1}));
	bool found = false;
	bfs(start, labyrinth, monsters, bfs_queue, visited, distance, parent_of, &found);
	if(!found){cout<<"NO";}
}

int main(){
	fastIO; free_cin_cout;
	int n, m;
	cin>>n>>m;
	vector< vector<char> > labyrinth(n, vector<char> (m));
	vector< pair<int, int> > monsters;
	pair<int, int> start;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin>>labyrinth[i][j];
			if(labyrinth[i][j] == 'M'){monsters.push_back({i, j});}
			else if(labyrinth[i][j] == 'A'){start = {i, j};}
		}
	}
	give_me_answer(start, labyrinth, monsters);
	return 0;
}
