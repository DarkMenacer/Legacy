//CSES Towers
//Mind-Blowing Discovery
//USE MEMBER FUNCTIONS OVER ALGORITHMS

///This is slower than the code below
#include <iostream>
#include <set>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n,a;
    cin>>n;
    multiset<int> towers;
    for(int i= 0;i<n;++i){
        cin>>a;
        auto itr = upper_bound(towers.begin(),towers.end(),a);   //<---- only difference between the 2 codes
        if(itr == towers.end()){towers.insert(a);}
        else{towers.erase(itr);towers.insert(a);}
    }
    cout<<towers.size();
    return 0;
}

//This is faster as multiset.upper_bound() is used
#include <iostream>
#include <set>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
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