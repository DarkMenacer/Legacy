#include <iostream>
using namespace std;
 
int main(){
    long total_cases,case_counter;
    cin>>total_cases;
    long storage[total_cases+1];
    for(case_counter=1;case_counter<=total_cases;case_counter++){
        long x,y;
        cin>>y>>x;
        if(x>=y){
            if(x%2==1){storage[case_counter] = x * x - y + 1;}
            else{storage[case_counter] = (x-1)*(x-1) + y;}
        }
        else{
            if(y%2==0){storage[case_counter] = y*y - x + 1 ;}
            else{storage[case_counter] = (y-1)*(y-1) + x;}
        }
    }
    for(case_counter=1;case_counter<=total_cases;case_counter++){cout<<storage[case_counter]<<endl;}
    return 0;
}