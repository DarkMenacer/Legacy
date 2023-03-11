#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define all(name) name.begin(),name.end()
#define f first
#define s second
#define p pair
#define ll long long
using namespace std;

ll give_me_answer(vector< p<ll,ll> > &tasks){
    sort(all(tasks));
    ll time = 0, answer = 0, i;
    FOR(i,0,tasks.size()){
        time+=tasks[i].f;
        answer+=(tasks[i].s - time);
    }
    return answer;
}

int main(){
    ll n,i;
    cin>>n;
    vector< p<ll,ll> > tasks(n);
    FOR(i,0,n){cin>>tasks[i].f>>tasks[i].s;}
    cout<<give_me_answer(tasks);
    return 0;
}