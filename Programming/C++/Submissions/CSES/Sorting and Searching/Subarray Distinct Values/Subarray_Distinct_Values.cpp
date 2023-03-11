#include <iostream>
#include <vector>
#include <map>
#define ll long long
#define vll vector<ll>
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
using namespace std;

ll give_me_answer(vll &integers, ll k){
    ll answer = 0;
    ll i = 0, j = 1;
    map<ll,ll> distinct;
    distinct[integers[i]]++;
    while(1){
        if(j==integers.size()+1){
            answer += (j-i)*(j-i-1)/2;
            break;
        }
        while(distinct.size() > k){
            auto it = distinct.find(integers[i]);
            it->second--;
            if(!(it->second)){distinct.erase(integers[i]);}
            answer+=j-i-1;
            i++;
        }
        distinct[integers[j++]]++;
    }
    return answer;
}

int main(){
    ll n,k;
    cin>>n>>k;
    vll integers(n);
    take_loop_input_in(integers,n);
    cout<<give_me_answer(integers,k);
    return 0;
}
