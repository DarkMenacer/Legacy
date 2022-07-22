/*
Name:-              Collecting Numbers
Platform:-          CSES
Date:-              22 January 2022
Type of Problem:-   Searching & Sorting using vector pair 
Complexity:-        O(n)
Status:-            Solved

Solution in brief:
Input is taken as a pair and stored in a vector. The pair contains the input value and its initial index before sorting.
Then the vector is sorted using the first, i.e. the input values.
Variable 'answer' is set to 1. Now the vector is traversed using an iterator and second values of consecutive elements are compared.
If the second value of next element is smaller than the current element, then answer is incremented as an extra round will be required. 

Sample to understand solution:
Input:-
5
4 2 1 5 3

Output:-
3

Explanation:-
    Input:-                 4 2 1 5 3
    Corresponding index:-   0 1 2 3 4

    After sorting:-         1 2 3 4 5
    Index:-                 2 1 4 0 3

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

int give_me_answer(vector< p<int,int> > values){
    int answer = 1;
    vector< p<int,int> >:: iterator itr,itr2;
    FOR(itr,values.begin(),values.end()-1){
        itr2 = itr + 1;
        if(itr->s > itr2->s){++answer;}
    }
    return answer;
}

int main(){
    int n,i,a;
    cin>>n;
    vector< p<int,int> > values;
    FOR(i,0,n){
        cin>>a;
        values.pb( mp(a,i) );
    }
    sort(all(values));
    cout<<give_me_answer(values);
    return 0;
}