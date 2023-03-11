#include <iostream>
#include <vector>
#include <algorithm>
#define all(name) name.begin(),name.end()
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> values(n);
    take_loop_input_in(values,n);
    vector<int> memoize(n,1);
    for(int i=0;i<n;++i){
        for(int k=i-1;k>=0;--k){
            if(values[k] < values[i]){
                memoize[i] = max(memoize[i],memoize[k]+1);
            }
        }
    }
    cout<<*max_element(all(memoize));
    return 0;
}