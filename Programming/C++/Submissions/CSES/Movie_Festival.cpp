/*
Name:-              Movie Festival
Platform:-          CSES
Date:-              17 January 2022
Type of Problem:-   Greedy Algorithmic
Complexity:-        O(n)
Status:-            Solved

Solution in brief:
The problem follows the basic premise of 
"Choosing maximum events such that no event can be selected partially within a given set of overlapping events".
First, a vector with pair of ints, 'movies' is initialised and input is taken in the format <end_time, begin_time>
(so as to sort movies based on end_time). 
Movies are selected on the principle that next movie should end as soon as possible.

Sample to understand solution:

Input:-
5
1 6
3 4
4 7
6 10
7 9
Output:-
3
*/

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

int give_me_answer(vector<p<int,int> > movies){
    int answer = 0, time = 0;
    vector<p<int,int> >::iterator watching = movies.begin();
    while(watching<movies.end()){
        while(time>watching->s && watching!=movies.end()){++watching;}
        if(watching==movies.end()){break;}
        time = watching->first;
        ++answer;
        ++watching;
    }
    return answer;
}

int main(){
    int n,a,b,i;
    cin>>n;
    vector<p<int,int> > movies;
    FOR(i,0,n){
        cin>>a;
        cin>>b;
        movies.pb(mp(b,a));
    }
    sort(all(movies));
    cout<<give_me_answer(movies);
    return 0;
}