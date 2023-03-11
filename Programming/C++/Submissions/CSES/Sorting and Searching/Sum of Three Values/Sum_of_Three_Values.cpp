#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#define take_indexed_loop_input(name,size) for(int i=1;i<size+1;++i){int x;cin>>x;name.push_back(make_pair(x,i));}
#define all(name) name.begin(),name.end()
#define fr first
#define sc second
#define ll long long
using namespace std;

int main(){
    ll n,x;
    cin>>n>>x;
    vector< pair<ll,ll> > input;
    take_indexed_loop_input(input,n);
    sort(all(input));
    vector< pair<ll,ll>>::iterator i,j,k;
    for(i = input.begin();i<input.end();++i){
        j = i + 1;
        k = input.end()-1;
        while(distance(j,k)>0){
            if(i->fr + j->fr + k->fr == x){
                cout<<i->sc<<" "<<j->sc<<" "<<k->sc<<endl;
                exit(0);
            }
            else if(i->fr + j->fr + k->fr > x){--k;}
            else if(i->fr + j->fr + k->fr < x){++j;}
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}