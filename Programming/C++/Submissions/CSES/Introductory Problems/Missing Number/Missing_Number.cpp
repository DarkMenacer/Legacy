// Edit: 20 Oct '22 
// Very very bad solution, please do yourself a favour
// use (n)(n+1)/2 - sum

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
 
 
int main(){
    int n;cin>>n;
    vector<int> vec;
    vec.reserve(n-1);
    vector<int>::iterator itr = vec.begin();
    for(int i = 0;i<n-1;++i){
        int x;cin>>x;
        vec.push_back(x);
    }
 
    /*int num;
    for(num = 1;num<n;++num){
        if((find(vec.begin(),vec.end(),num)==vec.end())){break;}
    }
    cout<<num;*/
 
    sort(vec.begin(),vec.end());
    int num;
    for(num = 1;num<n;++num){
        if(!(binary_search(vec.begin(),vec.end(),num))){break;}
    }
    cout<<num;
 
    return 0;