#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>
#include <cmath>
using namespace std;

void foo(int n, deque<int> &num){
    deque<int>::iterator itr;
    if(n==1){
        num.push_back(0);
        for(itr=num.begin();itr<num.end();++itr){cout<<*itr;}cout<<endl;
        num.pop_back();
        num.push_back(1);
        for(itr=num.begin();itr<num.end();++itr){cout<<*itr;}cout<<endl;
        return;
    }
    else{
       num.push_back(0);
       foo(n-1,num);
       for(int i=0 ;i<n;++i){num.pop_back();}
       num.push_back(1);
       foo(n-1,num);       
    }
}

int main(){
    int n;
    cin>>n;
    deque<int> num;
    foo(n,num);
    return 0;
}
