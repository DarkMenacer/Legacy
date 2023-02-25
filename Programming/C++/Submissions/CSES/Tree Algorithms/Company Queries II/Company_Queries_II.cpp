#include <iostream>
#include <vector>
using namespace std;
 
void calculate_superiors_n_level(int root, int parent, vector< vector<int> > &adj_list, vector<int> &level_of, vector< vector<int> > &superiors_of){
    if(root == 1){
        level_of[root] = 1;
    }
    else{
        level_of[root] = level_of[parent] + 1;
        int ancestor = parent;
        while(1){
            superiors_of[root].push_back(ancestor);
            if(superiors_of[ancestor].empty() || superiors_of[root].size() - 1 >= superiors_of[ancestor].size()){break;}
            ancestor = superiors_of[ancestor][superiors_of[root].size()-1];
        }
    }
    for(auto vertex: adj_list[root]){
        if(vertex != parent){
            calculate_superiors_n_level(vertex, root, adj_list, level_of,superiors_of);
        }
    }
}
 
void swap(int *a, int *b){int temp = *a;*a = *b;*b = temp;}
 
void adjust_levels(int *a, int *b, vector< vector<int> > &superiors_of, vector<int> &level_of){
    if(level_of[*a] < level_of[*b]){swap(a,b);}
    bool breaker = false;
    while(!breaker){
        if(superiors_of[*a].empty()){break;}
        for(auto superior: superiors_of[*a]){
            if(level_of[*a] == level_of[*b]){breaker = true;break;}
            if(level_of[superior] < level_of[*b]){break;}
            *a = superior;
        }
    }
}
 
int lowest_common_ancestor_of(int a, int b, vector< vector<int> > &superiors_of, vector<int> &level_of){
    if(level_of[a] != level_of[b]){adjust_levels(&a, &b, superiors_of, level_of);}
    if(a==b){return a;}
    int a_side = a, b_side = b, i=0;
 
    while(!(a_side != b_side && superiors_of[a_side][0] == superiors_of[b_side][0])){
        i = superiors_of[a_side].size()-1;
        while(superiors_of[a_side][i] == superiors_of[b_side][i]){--i;}
        a_side = superiors_of[a_side][i];
        b_side = superiors_of[b_side][i];
    }
 
    return superiors_of[a_side][0];
}
 
int main(){ 
    int n, q, x, a, b, i=0;
    cin>>n>>q;
    vector <vector<int> > adj_list(n+1);
    while(++i<n){
        cin>>x;
        adj_list[i+1].push_back(x);
        adj_list[x].push_back(i+1);
    }
    vector<int> level_of(n+1);
    vector< vector<int> > superiors_of(n+1);
 
    calculate_superiors_n_level(1, 0, adj_list, level_of, superiors_of);
  
    while(q--){
        cin>>a>>b;
        cout<<lowest_common_ancestor_of(a, b, superiors_of, level_of)<<endl;
    }
 
    return 0;
}