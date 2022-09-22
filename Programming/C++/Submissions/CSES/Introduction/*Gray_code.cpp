#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>
#include <cmath>
#define display for(itr=num.begin();itr<num.end();++itr){cout<<*itr;}cout<<endl;
using namespace std;

void finisher(int n, deque<int> &num){
    deque<int>::iterator itr;
    display;
    bool f0 = num[n-1];bool f1 = num[n-2];
    if(f0==0 && f1==0){
        num[n-1]=1; display;
        num[n-2]=1; display;
        num[n-1]=0; display;
    }
    else if(f0==1 && f1==0){
        num[n-2]=1; display;
        num[n-1]=0; display;
        num[n-2]=0; display;
    }
    else if(f0==1 && f1==1){
        num[n-1]=0; display;
        num[n-2]=0; display;
        num[n-1]=1; display;
    }
    else{
        num[n-2]=0; display;
        num[n-1]=1; display;
        num[n-2]=1; display;
    }
}

void foo(int x,int n, deque<int> &num){
    deque<int>::iterator itr;
    if(x==1){cout<<0<<endl<<1;return;}
    else if(x==2){finisher(n,num);return;}
    else{
        foo(x-1,n,num);
        (num[n-x]==0)?(num[n-x]=1):(num[n-x]=0);
        foo(x-1,n,num);
    }
}

int main(){
    int n;
    cin>>n;
    int x = n;
    deque<int> num;
    for(int i=0;i<n;++i){num.push_back(0);}
    foo(x,n,num);
    return 0;
}
