/*
Name:-              Room Allocation
Platform:-          CSES
Date:-              29 January 2022
Type of Problem:-   Priority Queues
Complexity:-        ????
Status:-            Wrong Answer (Read about priority queues)

Solution in brief:

Sample to understand solution:
Input:-

Output:-

Explanation:-

*/


#include <iostream>
#include <vector>
#include <algorithm>
#define f first
#define s second
#define mp make_pair
#define p pair
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define pb push_back
#define all(name) name.begin(),name.end()
#define here cout<<"here\n"
#define nl cout<<'\n'
#define what_is___here(name) cout<<"It is "<<name<<"\n"
#define display(name) for(auto it: name){cout<<it<<" ";}cout<<"\n"
#define ll long long
using namespace std;

int main(){
    ll n,i,a,b, rooms = 0;
    cin>>n;
    vector < p <p<ll,ll>,ll> > customers;
    vector<bool> booking(n,0);
    vector<ll> occupies(n,0);
    FOR(i,0,n){
        cin>>a>>b;
        customers.pb( mp(mp(b,a),i) );
    }
    sort(all(customers));
    FOR(i,0,n){
        if(booking[customers[i].s]==0){
            ++rooms;
            occupies[customers[i].s] = rooms;
            booking[customers[i].s] = 1;
            ll j = i+1, k = i;
            while(j<n){
                if((customers[j].f.s > customers[k].f.f) && booking[customers[j].s]==0){
                    occupies[customers[j].s] = rooms;
                    booking[customers[j].s] = 1;
                    k = j;
                }
                ++j;
            }
        }
    }
    cout<<rooms;nl;
    display(occupies);
    return 0;
}