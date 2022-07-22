#include <iostream>
#include <cmath>
using namespace std;

// a is the number to be rounded, n is the digits to which it is rounded to
// cmath to be included
void round_off(float *a, int n){
    int t = pow(10,n);
    *a = (float)((int)((*a)*t + 0.5))/t;
}

int main(){
    float a = 10.56787;
    round_off(&a,4);
    cout<<a;
    return 0;
}