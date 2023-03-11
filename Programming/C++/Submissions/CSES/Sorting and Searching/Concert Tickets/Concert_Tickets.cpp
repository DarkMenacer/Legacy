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
