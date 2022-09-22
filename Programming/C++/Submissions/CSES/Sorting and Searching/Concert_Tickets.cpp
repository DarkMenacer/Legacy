/*
Name:-              Concert Tickets
Platform:-          CSES
Date:-              24 January 2022
Type of Problem:-   Sorting and Searching (Bounds)
Complexity:-        O(nlogn)
Status:-            Solved

Solution in brief:

2 vectors,'tickets' and 'customers' are created, only tickets is sorted, as order matters for customers for output.
For each customer, an iterator 'tic' is always initiated at tickets.begin().
If customer's max price is smaller than smallest ticket price (&tickets.begin()) OR
    tickets is empty then '-1' printed & next customer is checked.
Else, tic is incremented till *tic is greater than the customer's max price.
tic is then decremented once, *tic is printed and the ticket is removed (tic is erased from tickets).

Sample to understand solution:
Input:-
5 5
3 5 7 9 11
3 8 9 4 6

Output:-
3
7
9
-1
5

*/

#include <iostream>
#include <set>
#include <vector>
#include <iterator>
using namespace std;
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
 
void prints_answer(multiset<int> tickets, vector<int> customers){
    multiset<int>::iterator tic;
    vector<int>::iterator cus;
    FOR(cus,customers.begin(),customers.end()){
        tic = tickets.begin();
        if(*cus < *tic || tic == tickets.end()){cout<<-1<<"\n";continue;}
        tic = tickets.upper_bound(*cus);
        --tic;
        cout<<*tic<<"\n";
        tickets.erase(tic);
    }
}
 
int main(){
    int n,m,i,x;
    cin>>n>>m;
    vector<int> customers;
    multiset<int> tickets;
    FOR(i,0,n){cin>>x;tickets.insert(x);}
    FOR(i,0,m){cin>>x;customers.push_back(x);}
    prints_answer(tickets,customers);
    return 0;
}
