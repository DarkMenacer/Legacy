#include <iostream>
#include <vector>
using namespace std;

void find_deepest(int root, int parent, vector< vector<int> > &adj_list, int count, int *deepest, int *deepness){
    if(adj_list[root].size()==1 && adj_list[root][0]==parent){
        if(count >= *deepness){
            *deepest = root;
            *deepness = count;
        }
        return;
    }
    for(auto vertex: adj_list[root]){
        if(vertex != parent){
            find_deepest(vertex, root, adj_list, count+1, deepest, deepness);
        }
    }
}

void find_path(int target, int current, int parent, vector< vector<int> > &adj_list, vector<int> &path, bool *found){
    if(current == target){
        path.push_back(target);
        *found = true;
        return;
    }
    if(adj_list[current].size()==1 && adj_list[current][0]==parent){return;}

    path.push_back(current);
    for(auto vertex: adj_list[current]){
        if(vertex != parent){
            find_path(target, vertex, current, adj_list, path, found);
            if(*found){return;}            
        }
    }
    if(*found == false){path.pop_back();}    
}

void set_out_of_path(int root, int parent, vector< vector<int> > &adj_list, vector<int> &distances){
    if(adj_list[root].size()==1 && adj_list[root][0]==parent){
        if(distances[root] == -1){
            distances[root] = distances[parent] + 1;
        }
        return;
    }
    for(auto vertex: adj_list[root]){
        if(vertex != parent){
            if(distances[vertex] == -1){
                distances[vertex] = distances[root] + 1;
            }
            set_out_of_path(vertex, root, adj_list, distances);
        }
    }
}

int main(){
    int n,a,b;
    cin>>n;
    if(n==1){cout<<0;return 0;}
    vector< vector<int> > adj_list(n+1);
    int i = 0;
    while(++i<n){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }


    int deepest = -1, deepness = -1;
    find_deepest(1,0,adj_list, 0, &deepest, &deepness);
    int new_deepest = -1, new_deepness = -1;
    find_deepest(deepest,0, adj_list, 0, &new_deepest, &new_deepness);


    vector<int> path;
    vector<int> distances(n+1, -1);
    bool found = false;
    find_path(deepest, new_deepest, 0, adj_list, path, &found);

    for(unsigned i = 0; auto vertex: path){
        distances[vertex] = max(new_deepness - i, i);
        ++i;
    }
    set_out_of_path(deepest, 0, adj_list, distances);

    for(int i = 1; i < n+1; ++i){cout<<distances[i]<<" ";}

    return 0;
}

