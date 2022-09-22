/*
Name:-              Factory Machines
Platform:-          CSES
Date:-              21 February 2022
Type of Problem:-   Binary Search
Complexity:-        O(nlog(n))
Status:-            Solved

Solution in brief:
Let the minimum time required be x
Therefore x should satisfy following conditions
ⁿ∑₁(x/kᵢ) ≥ t  and
ⁿ∑₁(x-1/kᵢ) < t
Therefore we can find such an x using binary search on all natural numbers inside the bound

Sample to understand solution:
Input:-
3 7
3 2 5

Output:-
8

Explanation:-
high: 10000000000000000000 low: 1 x: 5000000000000000000 t: 5166666666666666666
high: 5000000000000000000 low: 1 x: 2500000000000000000 t: 2583333333333333333
high: 2500000000000000000 low: 1 x: 1250000000000000000 t: 1291666666666666666
high: 1250000000000000000 low: 1 x: 625000000000000000 t: 645833333333333333
high: 625000000000000000 low: 1 x: 312500000000000000 t: 322916666666666666
high: 312500000000000000 low: 1 x: 156250000000000000 t: 161458333333333333
high: 156250000000000000 low: 1 x: 78125000000000000 t: 80729166666666666
high: 78125000000000000 low: 1 x: 39062500000000000 t: 40364583333333333
....about 50 lines later
high: 35 low: 1 x: 18 t: 18
high: 18 low: 1 x: 9 t: 8
high: 9 low: 1 x: 5 t: 4
high: 9 low: 5 x: 7 t: 6
high: 9 low: 7 x: 8 t: 7
*/

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
using namespace std;

ll give_me_answer(vector<ll> &machines, ll t){
    ll high = 1e19, low = 1, answer = 0, i;
    while(high > low){
        ll mid = (high + low)/2;
        ll produce = 0, produce_less= 0;
        FOR(i,0,machines.size()){
            produce += mid/machines[i];
            produce_less += (mid-1)/machines[i];
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
    ll n,t;
    cin>>n>>t;
    vector<ll> machines(n);
    take_input(machines,n);
    cout<<give_me_answer(machines,t);
    return 0;
}