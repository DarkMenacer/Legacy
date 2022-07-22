#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> polycarp;
    polycarp.push_back(-1);
    for(int i = 1; i<1667;++i){if(!(i%3==0 || i%10 ==3)){polycarp.push_back(i);}}
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<polycarp[n]<<endl;
    }
    return 0;
}