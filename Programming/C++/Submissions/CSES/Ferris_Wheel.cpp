/*
Name:-              Ferris Wheel 
Platform:-          CSES
Date:-              4 Jan 2022
Type of Problem:-   Sorting and Searching
Complexity:-        O(n)
Status:-            Solved

Solution in brief:
Input is taken into a vector 'input' and then sorted.
1 iterator 'itr' is initialised at the begin() and 1 reverse iterator 'ritr' at rbegin().
An integer 'answer' is initialised as input.size().  
A while(true) loop is run and *itr + *ritr is checked.
If *itr + *ritr <= x, then answer is decremented (both can go in a single gondola) and both itr & ritr are incremented.
Else only ritr is incremented (hoping that the next element (or the previous one because reverse_itr)) goes with itr.
The loop breaks only in 3 cases, 
    1) 2 iterators cross each other or
    2) *itr becomes more than half of weight capacity
    3) *ritr becomes less than half of weight capacity

Sample to understand solution:
Input:-
4 10
7 2 3 9

Output:-
3
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
using namespace std;

int give_me_answer(int x, vector<int> input){
    int answer = input.size();
    vector<int>::iterator itr;
    vector<int>::reverse_iterator ritr;
    itr = input.begin();
    ritr = input.rbegin();
    while(1){
        if(distance(itr,ritr.base())<=1 || *itr > x/2 || *ritr < x/2){
            if(*ritr < x/2){answer-=(distance(itr,ritr.base())/2);}
            break;
        }
        if(*itr + *ritr <= x){
            --answer;
            ++itr;
        }
        ++ritr;
    }
    return answer;
}

int main(){
    vector<int> input;
    int n,x,i,p;
    cin>>n>>x;
    FOR(i,0,n){
        cin>>p;
        input.push_back(p);
    }
    sort(input.begin(),input.end());
    cout<<give_me_answer(x,input);
    return 0;
}
