/*
Name:-              Josephus Problem -II
Platform:-          CSES
Date:-              29 January 2022
Type of Problem:-   Number Theory, Searching
Complexity:-        
Status:-            Incompletely implemented algoritm?????

Solution in brief:

Sample to understand solution:
Input:-

Output:-

Explanation:-

*/

#include <iostream>
#include <vector>
#include <numeric>
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define ll long long
#define here cout<<"here\n"
using namespace std;
 
ll lowest(vector<bool> picked){
    ll i = -1;
    FOR(i,1,picked.size()+1){
        if(!picked[i]){break;}
    }
    return i;
}

ll highest(vector<bool> picked){
    int i = -1;
    for(i = picked.size()-1;i>0;--i){
        if(!picked[i]){break;}
    }
    return i;
}

int main(){
    /* ll n,num_printed = 1,k,j,i;
    cin>>n>>k;
    vector<ll> children;
    vector<ll> :: iterator pick;
    ll nk = k % n;
    for(i = 1, j = 0; i<=n;++i,++j){
        if(j==nk){
            j=-1;
            cout<<i<<" ";
            ++num_printed;
            if(k>n){nk++;if(nk==n){nk=0;}}
            continue;
        }
        children.push_back(i);
    }
    pick = children.begin();
    if(pick==children.end()){return 0;}
 
    if(k>n){nk = k % children.size();}
    while(nk-j>0){
        ++pick;
        if(pick == children.end()){pick = children.begin();}
        ++j;
    }
    cout<<*pick<<" ";
    ++num_printed;
    pick = children.erase(pick);
    if(k>n){nk = k % children.size();}
 
    while(num_printed<n){
        if(pick == children.end()){pick = children.begin();}
        int dist = distance(pick,children.end());
        int diff =  nk - distance(pick,children.end());
        diff = diff % children.size();
        if(dist > nk ){advance(pick,nk);}
        else{
            //cout<<"nk: "<<nk<<" dist: "<<dist<<" pick: "<<*pick<<endl;
            pick = children.begin();
            advance(pick,diff);
        }
        if(pick == children.end()){pick = children.begin();}
        cout<<*pick<<" ";
        ++num_printed;
        pick = children.erase(pick);
        if(k>n){nk = k % children.size();}
    }
    if(!children.empty()){cout<<children[0];} */


    ll n,num_printed = 1,k,i = 1;
    cin>>n>>k;
    vector<bool> picked(n+1,0);
    picked[0] = 1;
    ll nk = k % n;
    while(num_printed<n){
        int last = highest(picked), first = lowest(picked), left = n - num_printed + 1;
         
        if(i > last){i = first;}
        int dist = last - i;
        for(int x = i;x<=last;++x){if(x==0){continue;}dist+=picked[x];}
        int diff =  nk - dist - 1;

        if(k>n){diff = diff % left;}
        cout<<"nk: "<<nk<<" dist: "<<dist<<" diff: "<<diff<<endl;

        if(dist >= nk ){diff = nk;}
        else{i = first;}
        while(diff){
            ++i;
            if(i==last+1){i = first;}
            if(picked[i]){continue;}
            else{--diff;}
        }
        if(i==last+1){i = first;}
        cout<<i<<" ";
        ++num_printed;
        picked[i] = 1;
        ++i;
        if(k>n){nk = k % (left-1);}
    }
    if(lowest(picked)!=-1){cout<<lowest(picked);}
    
    return 0;
}

//7 1 3 6 2 4 5