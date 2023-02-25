#include <iostream>
#include <vector>
#define what_is_here(name) cout<<#name<<": "<<name<<"\n"
using namespace std;

void find_deepest(vector< vector<int> > &adj_list, int root, int parent, int *deepest, int deepness, int *current_deepness){
    bool all_already_visited = true;
    for(auto vertex: adj_list[root]){
        if(vertex != parent){
            find_deepest(adj_list, vertex, root, deepest, deepness + 1, current_deepness);
            all_already_visited = false;
        }
    }
    if(all_already_visited){
        if(*current_deepness < deepness){
            *deepest = root;
            *current_deepness = deepness;
        }
    }
    return;
}


int main(){
    int n,a,b;
    cin>>n;
    vector< vector<int> > adj_list(n+1);
    int i = 0;
    while(i < n-1){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
        ++i;
    }

    int initial_deepest = 0, initial_deepness = 0;
    find_deepest(adj_list, 1, 0, &initial_deepest, 0, &initial_deepness);

    // what_is_here(initial_deepest);
    // what_is_here(initial_deepness);

    int final_deepest = 0, final_deepness = 0;
    find_deepest(adj_list, initial_deepest, 0, &final_deepest, 0, &final_deepness);

    // what_is_here(final_deepest);
    // what_is_here(final_deepness);
    cout<<final_deepness;

    return 0;
}