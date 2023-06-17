#include <iostream>
#include <deque>
/* #include <string> */
#include <vector>
/* #define display(name) cout<<#name<<": ";for(auto it: name){cout<<it<<" ";}cout<<"\n" */
#define nl cout<<'\n'
#define free_cin_cout cin.sync_with_stdio(false);cout.sync_with_stdio(false)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

// ATTEMPT-1: DFS, gives time limit error
//
/* void give_me_answer(int n, int m, int startx, int starty, int bx, int by, vector< vector<char> > &labyrinth, vector<char> &path, vector< vector<bool> >&visited, vector<char> &cur_path){ */
/* 	what_is_here(startx);what_is_here(starty);nl; */
/* 	visited[startx][starty] = true; */
/* 	if(startx == bx && starty == by){ */
/* 		if(!path.size() || cur_path.size() < path.size()){ */
/* 			path = cur_path; */
/* 		} */
/* 	} */
/* 	if(startx + 1 < n && labyrinth[startx+1][starty] != '#' && !visited[startx+1][starty]){ */
/* 		cur_path.push_back('D'); */
/* 		give_me_answer(n, m, startx+1, starty, bx, by, labyrinth, path, visited, cur_path); */
/* 		cur_path.pop_back(); */
/* 	} */
/* 	if(starty + 1 < m && labyrinth[startx][starty+1] != '#' && !visited[startx][starty+1]){ */
/* 		cur_path.push_back('R'); */
/* 		give_me_answer(n, m, startx, starty+1, bx, by, labyrinth, path, visited, cur_path); */
/* 		cur_path.pop_back(); */
/* 	} */
/* 	if(startx - 1 >= 0 && labyrinth[startx-1][starty] != '#' && !visited[startx-1][starty]){ */
/* 		cur_path.push_back('U'); */
/* 		give_me_answer(n, m, startx-1, starty, bx, by, labyrinth, path, visited, cur_path); */
/* 		cur_path.pop_back(); */
/* 	} */
/* 	if(starty - 1 >= 0 && labyrinth[startx][starty-1] != '#' && !visited[startx][starty-1]){ */
/* 		cur_path.push_back('L'); */
/* 		give_me_answer(n, m, startx, starty-1, bx, by, labyrinth, path, visited, cur_path); */
/* 		cur_path.pop_back(); */
/* 	} */
/* 	visited[startx][starty] = false; */
/* } */
/* */
/* int main(){ */
/* 	free_cin_cout;fastIO; */
/* 	int n, m, ax, ay, bx, by; */
/* 	cin>>n>>m; */
/* 	vector< vector<char> > labyrinth(n, vector<char>(m)); */
/* 	for(int i=0; i<n; ++i){ */
/* 		for(int j=0; j<m; ++j){ */
/* 			cin>>labyrinth[i][j]; */
/* 			if(labyrinth[i][j] == 'A'){ax = i; ay = j;} */
/* 			else if(labyrinth[i][j] == 'B'){bx = i; by = j;} */
/* 		} */
/* 	} */
/* 	vector<char> path, cur_path; */
/* 	vector < vector<bool> > visited(n, vector<bool>(m, 0)); */
/* 	give_me_answer(n, m, ax, ay, bx, by, labyrinth, path, visited, cur_path); */
/* 	if(path.size()){ */
/* 		cout<<"YES\n"; */
/* 		cout<<path.size();nl; */
/* 		for(auto element: path){cout<<element;} */
/* 	} */
/* 	else{cout<<"NO";} */
/* 	return 0; */
/* } */

//ATTEMPT-2 : BFS, gives runtime error
//
/* void give_me_answer(int n, int m, int cur_x, int cur_y, int bx, int by, vector< vector<char> > &labyrinth, string &path, vector< vector<bool> > &visited, bool *found, deque< pair<int,int> > &points, deque<string> &rel_pos){ */
/* 	if(*found){return;} */
/* 	visited[cur_x][cur_y] = true; */
/* 	if(cur_x == bx && cur_y == by){*found = true;} */
/* 	else{ */
/* 		string cur_path = rel_pos.empty()?"":rel_pos[0]; */
/* 		if(!points.empty()){ */
/* 			points.pop_front(); */
/* 			rel_pos.pop_front(); */
/* 		} */
/* 		path.clear(); */
/* 		if(cur_x + 1 < n && labyrinth[cur_x+1][cur_y] != '#' && !visited[cur_x+1][cur_y]){ */
/* 			points.push_back({cur_x+1, cur_y}); */
/* 			rel_pos.push_back(cur_path + 'D'); */
/* 		} */
/* 		if(cur_y + 1 < m && labyrinth[cur_x][cur_y+1] != '#' && !visited[cur_x][cur_y+1]){ */
/* 			points.push_back({cur_x, cur_y+1}); */
/* 			rel_pos.push_back(cur_path + 'R'); */
/* 		} */
/* 		if(cur_x - 1 >= 0 && labyrinth[cur_x-1][cur_y] != '#' && !visited[cur_x-1][cur_y]){ */
/* 			points.push_back({cur_x-1, cur_y}); */
/* 			rel_pos.push_back(cur_path + 'U'); */
/* 		} */
/* 		if(cur_y - 1 >= 0 && labyrinth[cur_x][cur_y-1] != '#' && !visited[cur_x][cur_y-1]){ */
/* 			points.push_back({cur_x, cur_y-1}); */
/* 			rel_pos.push_back(cur_path + 'L'); */
/* 		} */
/* 		if(!points.empty()){ */
/* 			path = rel_pos[0]; */
/* 			give_me_answer(n,m,points[0].first,points[0].second, bx, by, labyrinth, path, visited, found, points, rel_pos); */
/* 		} */
/* 	} */
/* } */

/* int main(){ */
/* 	free_cin_cout;fastIO; */
/* 	int n, m, ax=-1, ay=-1, bx=-1, by=-1; */
/* 	cin>>n>>m; */
/* 	vector< vector<char> > labyrinth(n, vector<char>(m)); */
/* 	for(int i=0; i<n; ++i){ */
/* 		for(int j=0; j<m; ++j){ */
/* 			cin>>labyrinth[i][j]; */
/* 			if(labyrinth[i][j] == 'A'){ax = i; ay = j;} */
/* 			else if(labyrinth[i][j] == 'B'){bx = i; by = j;} */
/* 		} */
/* 	} */
/* 	string path; */
/* 	deque< pair< int, int> >points; */
/* 	deque<string> rel_pos; */
/* 	vector < vector<bool> > visited(n, vector<bool>(m, 0)); */
/* 	bool found = false; */
/* 	give_me_answer(n, m, ax, ay, bx, by, labyrinth, path, visited, &found, points, rel_pos); */
/* 	if(path.size()){ */
/* 		cout<<"YES\n"; */
/* 		cout<<path.size();nl; */
/* 		for(auto element: path){cout<<element;} */
/* 	} */
/* 	else{cout<<"NO";} */
/* 	return 0; */
/* } */

//ATTEMPT 3: Storing the parent of each point, not the entire path, gives TLE
//
void find_path(int n, int m, int cur_x, int cur_y, int bx, int by, vector< vector<char> > &labyrinth, vector< vector< pair<int, int> > > &parent, vector< vector<bool> > &visited, bool *found, deque< pair<int,int> > &points){
	if(*found){return;}
	visited[cur_x][cur_y] = true;
	if(cur_x == bx && cur_y == by){*found = true;}
	else{
		if(!points.empty()){
			points.pop_front();
		}
		if(cur_x + 1 < n && labyrinth[cur_x+1][cur_y] != '#' && !visited[cur_x+1][cur_y]){
			parent[cur_x + 1][cur_y] = {cur_x, cur_y}; 
			points.push_back({cur_x+1, cur_y});
		}
		if(cur_y + 1 < m && labyrinth[cur_x][cur_y+1] != '#' && !visited[cur_x][cur_y+1]){
			parent[cur_x][cur_y + 1] = {cur_x, cur_y}; 
			points.push_back({cur_x, cur_y+1});
		}
		if(cur_x - 1 >= 0 && labyrinth[cur_x-1][cur_y] != '#' && !visited[cur_x-1][cur_y]){
			parent[cur_x - 1][cur_y] = {cur_x, cur_y}; 
			points.push_back({cur_x-1, cur_y});
		}
		if(cur_y - 1 >= 0 && labyrinth[cur_x][cur_y-1] != '#' && !visited[cur_x][cur_y-1]){
			parent[cur_x][cur_y - 1] = {cur_x, cur_y}; 
			points.push_back({cur_x, cur_y-1});
		}
		if(!points.empty()){
			find_path(n,m,points[0].first,points[0].second, bx, by, labyrinth, parent, visited, found, points);
		}
	}
}

void print_answer(bool found, int ax, int ay, int bx, int by, const vector< vector < pair<int, int> > > &parent){
	if(found){
		cout<<"YES\n";
		deque<char> path;
		int i = bx, j = by;
		while(i != ax || j != ay){
			if(parent[i][j].first != i){
				if(parent[i][j].first > i){path.push_front('U');}
				else{path.push_front('D');}
			}
			else{
				if(parent[i][j].second > j){path.push_front('L');}
				else{path.push_front('R');}
			}
			int temp = parent[i][j].second;
			i = parent[i][j].first;
			j = temp;
		}
		cout<<path.size();nl;
		for(auto direction: path){cout<<direction;}
	}
	else{cout<<"NO\n";}
}
 
int main(){
	free_cin_cout;fastIO;
	int n, m, ax=-1, ay=-1, bx=-1, by=-1;
	cin>>n>>m;
	vector< vector<char> > labyrinth(n, vector<char>(m));
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cin>>labyrinth[i][j];
			if(labyrinth[i][j] == 'A'){ax = i; ay = j;}
			else if(labyrinth[i][j] == 'B'){bx = i; by = j;}
		}
	}
	deque< pair< int, int> >points;
	vector < vector<bool> > visited(n, vector<bool>(m , 0));
	vector< vector< pair<int, int> > > parent(n, vector<pair<int, int> >(m, {-1, -1}));
	bool found = false;
	find_path(n, m, ax, ay, bx, by, labyrinth, parent, visited, &found, points);
	print_answer(found, ax, ay, bx, by, parent);
	return 0;
}
