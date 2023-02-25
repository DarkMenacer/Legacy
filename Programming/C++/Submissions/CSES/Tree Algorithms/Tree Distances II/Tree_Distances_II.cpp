#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll depth_first_counter(int root, int parent, vector< vector<int> > &adj_list, ll *count, int level, vector<ll> &children){
    *count+=level;
    if(adj_list[root].size() == 1 && adj_list[root][0]==parent){return 0;}
    for(auto vertex: adj_list[root]){
        if(vertex != parent){
            children[root] += depth_first_counter(vertex, root, adj_list, count, level+1, children) + 1;
        }
    }
    return children[root];
}

void calculate_distance_sums(int root, int parent, vector< vector<int> > &adj_list, vector<ll> &distance_sums, vector<ll> &children){
    if(root != 1){
        distance_sums[root] = distance_sums[parent] - 2 + adj_list.size() - 1 - (children[root] * 2); 
    }
    if(adj_list[root].size() == 1 && adj_list[root][0]==parent){return;}
    for(auto vertex: adj_list[root]){
        if(vertex != parent){
            calculate_distance_sums(vertex, root, adj_list, distance_sums, children);
        }
    }
}

int main(){
    int n, a, b, i = 0;
    cin>>n;
    vector< vector<int> > adj_list(n+1);
    vector<ll> distance_sums(n+1, 0);
    vector<ll> children(n+1, 0);
    while(++i<n){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    depth_first_counter(1, 0, adj_list, &distance_sums[1], 0, children);

    calculate_distance_sums(1, 0, adj_list, distance_sums, children);

    for(int i = 1; i < n+1; ++i){cout<<distance_sums[i]<<" ";}

    return 0;
}
