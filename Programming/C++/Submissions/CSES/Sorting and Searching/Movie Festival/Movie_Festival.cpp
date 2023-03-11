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