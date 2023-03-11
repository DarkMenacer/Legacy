/*
Name:-              Playlist
Platform:-          CSES
Date:-              24 January 2022
Type of Problem:-   Searching
Complexity:-
Status:- 

Solution in brief:

Sample to understand solution:
Input:-

Output:-

Explanation:-

*/

#include <iostream>
#include <map>
#include <iterator>
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define pb push_back
#define all(name) name.begin(),name.end()
#define f first
#define s second
#define mp make_pair
#define p pair
using namespace std;
 
int main(){
    int n,i,x,answer = 0,last_repeat = 0, last_id = 0;
    cin>>n;
    map<int,int> songs;
    FOR(i,0,n){
        cin>>x;
        if(songs.find(x)!= songs.end() || i == n-1){
            if(i==n-1){
                if(songs.find(x)!= songs.end() && last_id==x){--i;}
                answer = max(answer,i - last_repeat);
                break;
            }
            last_repeat = max(last_repeat,songs.find(x)->second);
            if(answer!=0){answer = max(answer,i - last_repeat);}
            else{answer = i;}
            songs.erase(songs.find(x));
            last_id = x;
        }
        songs.insert( mp (x,i) );
    }
    cout<<answer;
    return 0;
}