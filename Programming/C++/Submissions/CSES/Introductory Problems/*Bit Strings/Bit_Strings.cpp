//GIVES WRONG ANSWER FOR SOME REASON
#include <iostream>
#include <cmath>
using namespace std;
 
int main(){
    long n;
    cin>>n;
    long long x = pow(10,9) + 7;
    long long ans = pow(2,n);
    cout<< ans%x;
    return 0;