#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#define all(name) name.begin(),name.end()
#define vp vector< pair<int,int> >
#define vpitr vector< pair<int,int> >:: iterator
#define take_indexed_loop_input(name,size) for(int i=1;i<size+1;++i){int x;cin>>x;name.push_back(make_pair(x,i));}
#define f first
#define s second
using namespace std;

bool find_two (vp &integers , vpitr start, vpitr stop, int x){
    if(x<0){return false;}
    while(start < stop){
        if(start->f + stop->f < x){++start;}
        else if(start->f + stop->f > x){--stop;}
        else{
            cout<<start->s<<" "<<stop->s<<" ";
            return true;
        }
    }
    return false;
}

void prints_answer(vp &integers, int x){
    for(int i=0;i<integers.size();++i){
        for(int j=integers.size()-1;j>i;--j){
            if(find_two(integers,integers.begin()+i+1,integers.begin()+j-1,x-integers[i].f-integers[j].f)){
                cout<<integers[i].s<<" "<<integers[j].s;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return;
}

int main(){
    int n,x;
    cin>>n>>x;
    vp integers;
    take_indexed_loop_input(integers,n);
    sort(all(integers));
    prints_answer(integers,x);
    return 0;
}