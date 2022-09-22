/*
Name:-              Sum of Two Values
Platform:-          CSES
Date:-              22 January 2022
Type of Problem:-   Searching, 2 pointer method
Complexity:-        O(nlog(n))
Status:-            Solved

Solution in brief:
Input is taken in a pair with the value and its index and is stored in a vector. An iterator and a reverse iterator are used. 
If itr + ritr < x, itr is incremented, Else if itr + ritr > x, ritr is incremented, Else loop is broken and indexes are printed.

Sample to understand solution:
Input:-
4 8
2 7 5 1

Output:-
2 4
*/

#include <iostream>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define pb push_back
#define all(name) name.begin(),name.end()
#define f first
#define s second
#define mp make_pair
#define p pair
using namespace std;

void give_me_answer(vector< p<int,int> > values, int x){
    vector< p<int,int> >::iterator itr = values.begin();
    vector< p<int,int> >::reverse_iterator ritr = values.rbegin();
    bool unavailable = true;
    while(distance(itr,ritr.base())>1){
        if(itr->f + ritr->f == x){unavailable = false;break;}
        else if(itr->f + ritr->f > x){++ritr;}
        else{++itr;}
    }
    if(unavailable){cout<<"IMPOSSIBLE";return;}
    else{cout<<(ritr->s)<<" "<<(itr->s);}
}

int main(){
    int n,x,i,a;
    cin>>n;
    cin>>x;
    vector< p<int,int> > values;
    FOR(i,0,n){
        cin>>a;
        values.pb( mp(a,i+1) );
    }
    sort(all(values));
    give_me_answer(values,x);
    return 0;
}

