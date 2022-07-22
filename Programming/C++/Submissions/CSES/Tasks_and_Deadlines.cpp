/*
Name:-              Tasks and Deadlines
Platform:-          CSES
Date:-              22 February 2022
Type of Problem:-   Greedy 
Complexity:-        O(n)
Status:-            Solved

Solution in brief:
Firstly all tasks are sorted(increasing order) according to their durations and then they are executed.
This approach works and can be proved because 
Let taskᵢ end at xᵢ, then the answer will be ∑(dᵢ - xᵢ), now dᵢs are constant (i.e we can't affect them).
Therefore now the answer is ∑dᵢ - ∑xᵢ, so the objective naturally is to minimise ∑xᵢ
That implies tasks should finish as soon as possible. Hence the greedy approach works

Sample to understand solution:
Input:-
4
4 2
3 5
2 7
4 5

Output:-
-10

Explanation:-
Sorted order
2 7
3 5
4 2
4 5
and this is the order
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define pb push_back
#define all(name) name.begin(),name.end()
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
#define here cout<<"here\n"
#define nl cout<<'\n'
#define display(name) for(auto it: name){cout<<it<<" ";}cout<<"\n"
#define what_is___here(name) cout<<"It is "<<name<<"\n"
#define f first
#define s second
#define mp make_pair
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