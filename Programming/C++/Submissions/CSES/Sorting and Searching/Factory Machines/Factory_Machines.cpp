#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define pb push_back
#define all(name) name.begin(),name.end()
#define here cout<<"here\n"
#define nl cout<<'\n'
#define display(name) for(auto it: name){cout<<it<<" ";}cout<<"\n"
#define what_is___here(name) cout<<" It is "<<name<<"\n"
#define take_input(name,size) for(ll i=0;i<size;++i){cin>>name[i];}
#define ll unsigned long long
#define free_cin_cout cin.sync_with_stdio(false);cout.sync_with_stdio(false)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

ll give_me_answer(vector<ll> &machines, ll t){
    ll high = 1e19, low = 1, answer = 0, i;
    while(high > low){
        ll mid = (high + low)/2;
        ll produce = 0, produce_less= 0;
        FOR(i,0,machines.size()){
            produce += mid/machines[i];
            produce_less += (mid-1)/machines[i];
            if(produce_less > t){break;}
        }
        cout<<"high: "<<high<<" low: "<<low<<" x: "<<mid<<" t: "<<produce;nl;
        if(produce >= t && produce_less < t){answer = mid;break;}
        else{
            if(produce < t){low = mid;}
            else{high = mid;}
        }
    }
    return answer;
}

int main(){
    free_cin_cout;fastIO;
    ll n,t;
    cin>>n>>t;
    vector<ll> machines(n);
    take_input(machines,n);
    cout<<give_me_answer(machines,t);
    return 0;
}