#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
using namespace std;

int give_me_answer(int x, vector<int> input){
    int answer = input.size();
    vector<int>::iterator itr;
    vector<int>::reverse_iterator ritr;
    itr = input.begin();
    ritr = input.rbegin();
    while(1){
        if(distance(itr,ritr.base())<=1 || *itr > x/2 || *ritr < x/2){
            if(*ritr < x/2){answer-=(distance(itr,ritr.base())/2);}
            break;
        }
        if(*itr + *ritr <= x){
            --answer;
            ++itr;
        }
        ++ritr;
    }
    return answer;
}

int main(){
    vector<int> input;
    int n,x,i,p;
    cin>>n>>x;
    FOR(i,0,n){
        cin>>p;
        input.push_back(p);
    }
    sort(input.begin(),input.end());
    cout<<give_me_answer(x,input);
    return 0;
}
