/*
Name:-              Distinct Numbers
Platform:-          CSES
Date:-              2 Nov 2021
Type of Problem:-   Searching
Complexity:-        O(log n) 
Status:-            Solved

Solution in brief:  
Used the basic property of sets. find() function tries to search for the element.
If not present, points to end(), meaning number is unique. Answer++ and number added to set.

*/

#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<int> myset;
    set<int>::iterator itr;
    int answer = 0;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        if(myset.find(x)==myset.end()){++answer;myset.insert(x);}
    }
    cout<<answer<<endl;
}