#include <iostream>
using namespace std;
 
long counter(int n, int arr[]){
    long count=0;
    for(int i=0;i<n-1;++i){
        while(arr[i]>arr[i+1]){
            ++arr[i+1];
            count++;
        }
    }
    return count;
}
 
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;++i){cin>>arr[i];}   
    cout<<counter(n,arr);
}