#include <iostream>
#include <vector>
using namespace std;

void traverse_room(int n, int m, int i, int j, vector< vector<char> > &building, vector< vector<bool> > &visited){
	visited[i][j]=1;
	if(j+1 < m && building[i][j+1] == '.' && visited[i][j+1] != 1){traverse_room(n, m, i, j+1, building, visited);}
	if(i+1 < n && building[i+1][j] == '.' && visited[i+1][j] != 1){traverse_room(n,m, i+1,j,building,visited);}
	if(j-1 >= 0  && building[i][j-1] == '.' && visited[i][j-1] != 1){traverse_room(n,m, i,j-1,building,visited);}
	if(i-1 >= 0  && building[i-1][j] == '.' && visited[i-1][j] != 1){traverse_room(n,m, i-1,j,building,visited);}
}

int give_me_answer(int n, int m, vector< vector<char> > &building){
	int returner = 0;
	vector< vector<bool> > visited(n,vector<bool>(m,0));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(building[i][j] != '#' &&  visited[i][j] != 1){traverse_room(n, m, i, j, building, visited);returner++;}
		}
	}
	return returner;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector< vector<char> > building(n);
	char x;
	for(int i=0;i<n;++i){
		for(int j=0; j<m; ++j){
			cin>>x;
			building[i].push_back(x);
		}
	}
	cout<<give_me_answer(n,m,building);
	return 0;
}
