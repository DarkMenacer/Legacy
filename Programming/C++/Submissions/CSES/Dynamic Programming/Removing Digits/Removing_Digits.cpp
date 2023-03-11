#include <iostream>
#include <vector>
#include <cmath>
#define inf 1e9
using namespace std;

vector<int> digits(int x){
    int no = floor(log10(x)) + 1;
    vector<int> returner(no,-1);
    for(int i = 0; i < no; ++i){
        returner[i] = x%10;
        x = trunc(x/10);
    }
    return returner;
}

int main(){
    int n;
    cin>>n;
    if(n<10){
        cout<<1;
    }
    else{
        vector<int> memoize(n+1,inf);
        for(int i=0;i<n+1;++i){
            if(i<10){memoize[i] = 1;}
            else{
                vector<int> temp = digits(i);
                for(unsigned j=0;j<temp.size();++j){
                    memoize[i] = min(memoize[i], memoize[i - temp[j]] + 1);
                }
            }
        }
        cout<<memoize[n];
    }
    return 0;
}
