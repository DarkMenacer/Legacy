/*
Name:-              Apartments
Platform:-          CSES
Date:-              3 January 2022
Type of Problem:-   Sorting and Searching
Complexity:-        O(nlogn) 
Status:-            Solved

Solution in brief:
2 multisets, 'apartments' and 'applicants' are created. 
For each element in applicants, elements in apartments are checked from the beginning.
Let e(apartments) denote current element of apartments
If e(applicants) - e(apartments) > k, then e(apartments) is removed from apartments.
Else if e(applicants) - e(apartments) < -k, next element of applicants is checked, i.e. e(applicants) occupies no room.
Else e(applicants) occupies e(apartments), and e(apartments) is removed from apartments.

Sample to understand solution:
Input:-
10 10 10
90 41 20 39 49 21 35 31 74 86
14 24 24 7 82 85 82 4 60 95

Output:-
6
*/

#include <iostream>
#include <set>
#include <iterator>
#define FOR(i,start,upper_limit) for(i=start;i!=upper_limit;++i)
using namespace std;

int give_me_answer(int k, multiset<int> applicants, multiset<int> apartments){
    multiset<int>::iterator itr1, itr2;
    int answer = 0;
    FOR(itr1,applicants.begin(),applicants.end()){
        itr2 = apartments.begin();
        while(itr2 != apartments.end()){
            if(*itr1 - *itr2 > k){itr2 = apartments.erase(itr2);}
            else if(*itr1 - *itr2 < -k){break;} 
            else{
                ++answer;
                itr2 = apartments.erase(itr2);
                break;
            }
        }
    }
    return answer;
}

int main(){
    int n,m,k;
    cin>>n;
    cin>>m;
    cin>>k;
    int i,x;
    multiset<int> applicants, apartments;
    FOR(i,0,n){
        cin>>x;
        applicants.insert(x);
    }
    FOR(i,0,m){
        cin>>x;
        apartments.insert(x);
    }
    cout<<give_me_answer(k,applicants,apartments);

    return 0;
}