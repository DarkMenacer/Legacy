#include <iostream>
#include <set>
using namespace std;

int main(){
    int n,a;
    cin>>n;
    multiset<int> towers;
    for(int i= 0;i<n;++i){
        cin>>a;
        auto itr = towers.upper_bound(a);
        if(itr == towers.end()){towers.insert(a);}
        else{towers.erase(itr);towers.insert(a);}
    }
    cout<<towers.size();
    return 0;
} 