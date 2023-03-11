#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
T min(T a, T b, T c){return ((a<b)? a:b) < c ? ((a<b)? a:b) : c;}
int cost(char i, char j){return (i==j? 0 : 1);}

int main(){
    string one, two;
    cin>>one>>two;
    vector< vector<int> > memoize (one.size()+1, vector<int> (two.size()+1));
    memoize[0][0] = 0;
    for(unsigned j=1; j<two.size()+1; ++j){
        memoize[0][j] = memoize[0][j-1] + 1;
    }
    for(unsigned i=1; i<one.size()+1; ++i){
        memoize[i][0] = memoize[i-1][0] + 1;
    }
    for(unsigned i=1; i<one.size()+1; ++i){
        for(unsigned j=1; j<two.size()+1; ++j){
            memoize[i][j] = min(memoize[i-1][j]+1, 
                                memoize[i][j-1]+1, 
                                memoize[i-1][j-1] + cost(one[i-1], two[j-1])
                                );
        }
    }
    cout<<memoize[one.size()][two.size()];
    return 0;
}