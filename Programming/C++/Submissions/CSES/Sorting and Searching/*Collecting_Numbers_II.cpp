/*
Name:-              Collecting Numbers II
Platform:-          CSES
Date:-              22 January 2022
Type of Problem:-   Sorting and Searching
Complexity:-        O(n²)(??)
Status:-            Time Limit Error (Re-implement algorithm)

Solution in brief:

Sample to understand solution:
Input:-

Output:-

Explanation:-

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
 
void swapper(vector< p<int,int> > &values, int a, int b){
    int temp = values[a].first;
    values[a].first = values[b].first;
    values[b].first = temp;
}
 
int give_me_answer(vector< p<int,int> > values){
    //sort(all(values));
    int answer = 1;
    vector< p<int,int> >:: iterator itr,itr2;
    FOR(itr,values.begin(),values.end()-1){
        itr2 = itr + 1;
        if(itr->s > itr2->s){++answer;}
    }
    return answer;
}
 
int main(){
    int n,i,a,b,m;
    cin>>n;
    cin>>m;
    vector< p<int,int> > values;
    FOR(i,0,n){
        cin>>a;
        values.pb( mp(a,i) );
    }
    FOR(i,0,m){
        cin>>a;
        cin>>b;
        swapper(values,a-1,b-1);
        cout<<give_me_answer(values)<<"\n";
    }
 
    return 0;
}