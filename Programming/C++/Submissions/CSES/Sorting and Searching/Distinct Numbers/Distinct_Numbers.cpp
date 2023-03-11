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