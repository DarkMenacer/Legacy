#include <iostream>
#include <vector>
using namespace std;

long long ret_sum(vector<bool> sign, vector<int> num,int n){
    long long sum = 0;
    for(int i = 0;i<n;++i){
        if(sign[i] == 0){sum+=num[i];}
        else{sum-=num[i];}
    }
    return abs(sum);
}

void next(vector<bool> &sign,int n){
    for(int i=0;i<n;++i){
        if(sign[i]==0){sign[i]=1;break;}
        else{sign[i]=0;}
    }
}

long long give_me_answer(int n,vector<int> num,vector<bool> sign){
    long long sum = ret_sum(sign,num,n);
    bool flag = true;
    while(flag){
        next(sign,n);
        if(sum > ret_sum(sign,num,n)){sum = ret_sum(sign,num,n);}
        flag = false;
        for(int i=0;i<n;++i){if(sign[i]==0){flag = true;}}
    }
    return sum;
}

int main(){
    vector<int> num;
    vector<bool> sign;
    int n;cin>>n;
    for(int i=0;i<n;++i){
        int x;cin>>x;
        num.push_back(x);
        sign.push_back(0);
    }
    cout<<give_me_answer(n,num,sign);

    return 0;
}