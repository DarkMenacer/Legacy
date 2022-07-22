//  First Competitive coding question solved
//  Google CodeJam 2021
//  #Mention date

#include <iostream>
#include <cmath>
using namespace std;

int Find_Pos (int s ,int l ,int b[]){
    int i,r,p;
    r = b[s];
    for(i=s-1;i<l;i++){
       r = min(r,b[i]);
    }
    for(i=s-1;i<l;i++){
        if(r==b[i]){
            p=i+1;
        }
    }
    return p;
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Reversort(int l ,int b[]){
    int i,j,k,s=0;
    for(i=1;i<l;i++){
        j = Find_Pos(i,l,b);
        for(k=0;k<=(j-i)/2;k++){
            swap(&b[i-1+k],&b[j-1-k]);
        }
        s=s+j-i+1;
    }
    return s;
}

int main(){
    int n,i,t,r,b[100];
    cin>>t;
    for(r=1;r<=t;r++){
        cin>>n;
        int a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        b[r]= Reversort(n,a);
    }
    for(r=1;r<=t;r++){
        cout<<"Case #"<<r<<": "<<b[r]<<endl;
    }
    return 0;
}