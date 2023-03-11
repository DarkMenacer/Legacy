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
using namespace std;

int main(){
    int n,i,x,answer = 0, current=0;
    cin>>n;
    vector <p <int, int> > customers_moving;
    FOR(i,0,n){
        cin>>x;
        customers_moving.push_back( mp(x,1) );
        cin>>x;
        customers_moving.push_back( mp(x,-1) );
    }
    sort(all(customers_moving));
    for(auto time: customers_moving){
        current+=time.second;
        answer = max(answer,current);
    }
    cout<<answer;
    return 0;
}