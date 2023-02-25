#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void calculate_superiors(int root, int parent, vector< vector<int> > &adj_list, vector< vector<int> > &superiors_of){
    int ancestor = parent;
    if(ancestor != 0){superiors_of[root].push_back(ancestor);}
    while(1){
        if(superiors_of[ancestor].empty() || superiors_of[root].size() - 1 >= superiors_of[ancestor].size()){break;}
        ancestor = superiors_of[ancestor][superiors_of[root].size() - 1];
        if(ancestor != 0){superiors_of[root].push_back(ancestor);}
    }
    for(auto vertex: adj_list[root]){
        if(vertex != parent){calculate_superiors(vertex, root, adj_list, superiors_of);}
    }
}

int go_to_right_ancestor(int vertex, int go_back_by, vector< vector<int> > &superiors_of){
    while(go_back_by){
        if(superiors_of[vertex].empty() || (int)log2(go_back_by) > superiors_of[vertex].size() - 1){return -1;}
        vertex = superiors_of[vertex][log2(go_back_by)];
        go_back_by -= pow(2, (int)log2(go_back_by));
    }
    return vertex;
}


int main(){
    int n, q, x, a, b, i = 0;
    cin>>n>>q;
    vector< vector<int> > adj_list(n+1);
    vector< vector<int> > superiors_of(n+1);

    while(++i<n){
        cin>>x;
        adj_list[i+1].push_back(x);
        adj_list[x].push_back(i+1);
    }

    calculate_superiors(1, 0, adj_list, superiors_of);

    while(q--){
        cin>>a>>b;
        cout<<go_to_right_ancestor(a, b, superiors_of)<<endl;
    }

    return 0;
}