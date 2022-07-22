//  First problem solved using STLs
//  CSES Problem 2
//  15 May 2021

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


int main(){
    int n;cin>>n;
    vector<int> vec;
    vec.reserve(n-1);
    for(int i = 0;i<n-1;++i){
        int x;cin>>x;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    int num;
    for(num = 1;num<n;++num){
        if(!(binary_search(vec.begin(),vec.end(),num))){break;}
    }
    cout<<num;

    return 0;
}