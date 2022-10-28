#include <iostream>
using namespace std;
 
long no_of_factors_of(long prime, long num){
    long count = 0;
    while(num>1){
        num = num/prime;
        count+=num;
    }
    return count;
}
 
int main(){
    long n;
    cin>>n;
    cout<<no_of_factors_of(5,n);
    return 0;
}
