/*
Name:-              Nested Ranges Count
Platform:-          CSES
Date:-              29 January
Type of Problem:-   Searching
Complexity:-        O(n²)
Status:-            Wrong Answer

Solution in brief:

Sample to understand solution:
Input:-

Output:-

Explanation:-

*/

#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define pb push_back
#define all(name) name.begin(),name.end()
#define here cout<<"here\n"
#define nl cout<<'\n'
#define display(name) for(auto it: name){cout<<it<<" ";}cout<<"\n"
#define f first
#define s second
#define mp make_pair
#define p pair
using namespace std;

int main(){
    int n,i,a;
    cin>>n;
    vector< p<int,int> > input;
    FOR(i, 1, n+1){
        cin>>a;input.push_back(mp(a,i));
        cin>>a;input.push_back(mp(a,-i));
    }
    sort(all(input));
    deque<int> index;
    vector<int> contains(n,0);
    vector<int> contained(n,0);

    FOR(i,0,input.size()){
        if(input[i].s > 0){index.push_back(input[i].s);}
        else{
            if(input[i].s + *index.begin() == 0){index.pop_front();}
            else{
                deque<int>::iterator itr = index.begin();
                while(abs(input[i].s) != *itr){
                    ++contains[*itr-1];
                    ++contained[abs(input[i].s) - 1];
                    ++itr;
                }
                index.erase(itr);
            }
        }
    }
    display(contains);
    display(contained);
    return 0;

}