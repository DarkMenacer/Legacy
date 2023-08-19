#include <iostream>
#include <vector>
#define nl cout<<'\n'
#define free_cin_cout cin.sync_with_stdio(false);cout.sync_with_stdio(false)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define INF 1e16
using namespace std;

void floyd_warshall(vector< vector<ll> > &adj_mat){
	for(unsigned i=1; i<adj_mat.size(); ++i){
		for(unsigned j=1; j<adj_mat.size(); ++j){
			if(i != j){
				for(unsigned k=1; k<adj_mat.size(); ++k){
					adj_mat[j][k] = min(adj_mat[j][k], adj_mat[j][i] + adj_mat[i][k]);
				}
			}
		}
	}
	for(unsigned i=1; i<adj_mat.size(); ++i){
		for(unsigned j=1; j<adj_mat.size(); ++j){
			if(i == j){adj_mat[i][j] = 0;}
			else if(adj_mat[i][j] == INF){adj_mat[i][j] = -1;}
		}
	}
}

int main(){
	free_cin_cout; fastIO;
	ll n, m, q, a, b, c, i=0;
	cin>>n>>m>>q;
	vector< vector<ll> > adj_mat(n+1, vector<ll> (n+1, INF));
	while(i++ < m){
		cin>>a>>b>>c;
		adj_mat[a][b]= min(adj_mat[a][b], c);
		adj_mat[b][a]= min(adj_mat[a][b], c);;
	}
	floyd_warshall(adj_mat);
	while(q--){
		cin>>a>>b;
		cout<<adj_mat[a][b];nl;
	}
	return 0;
}
