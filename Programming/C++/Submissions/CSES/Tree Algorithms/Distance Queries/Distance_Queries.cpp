#include <iostream>
#include <vector>
#define free_cin cin.sync_with_stdio(false)
#define free_cout cout.sync_with_stdio(false)
using namespace std;
 
void calculate_superiors_n_level(int root, int parent, vector< vector<int> > &adj_list, vector< vector<int> > &superiors_of, vector<int> &level_of){
    if(root == 1){
        level_of[root] = 1;
    }
    else{
        level_of[root] = level_of[parent] + 1;
        int ancestor = parent;
        while(1){
            superiors_of[root].push_back(ancestor);
            if(superiors_of[ancestor].empty() || superiors_of[root].size() - 1 >= superiors_of[ancestor].size()){break;}
            ancestor = superiors_of[ancestor][superiors_of[root].size() - 1];
        }
    }
 
    for(auto vertex: adj_list[root]){
        if(vertex != parent){
            calculate_superiors_n_level(vertex, root, adj_list, superiors_of, level_of);
        }
    }
 
}
 
void swap(int *a, int *b){int temp = *a; *a = *b; *b = temp;}
 
void adjust_levels(int *a, int b, vector< vector<int> > &superiors_of, vector<int> &level_of){
    while(level_of[*a] != level_of[b]){
        int i = superiors_of[*a].size() - 1;
        while(level_of[superiors_of[*a][i]] < level_of[b]){--i;}
        *a = superiors_of[*a][i];
    }
}
 
int lowest_common_ancestor(int a, int b, vector< vector<int> > &superiors_of, vector<int> &level_of){
    if(level_of[a] < level_of[b]){swap(&a,&b);}
    if(level_of[a] != level_of[b]){adjust_levels(&a, b, superiors_of, level_of);}
    if(a==b){return a;}
    int i = 0;
    while(!(a != b && superiors_of[a][0] == superiors_of[b][0])){
        i = superiors_of[a].size() - 1;
        while(superiors_of[a][i] == superiors_of[b][i]){--i;}
        a = superiors_of[a][i];
        b = superiors_of[b][i];
    }
    return superiors_of[a][0]; 
}
 
 
int main(){

    //THESE 3 HELPED PASS ALL TEST CASES WHICH GAVE TLE IF THESE WERE NOT INCLUDED
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    free_cin;free_cout;

    int n, q, a, b, i = 0;
    cin>>n>>q;
    vector< vector<int> > adj_list(n+1);
    vector< vector<int> > superiors_of(n+1);
    vector<int> level_of(n+1);

    while(++i < n){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
 
    calculate_superiors_n_level(1, 0, adj_list, superiors_of, level_of);
    while(q--){
        cin>>a>>b;
        cout<< level_of[a] + level_of[b] - 2 * level_of[lowest_common_ancestor(a, b, superiors_of, level_of)];cout<<"\n";
    }

    return 0;
}