#include <iostream>
#define ull unsigned long long
using namespace std;

ull pow10(ull n){
    ull x = 1;
    while(n--){x*=10;}
    return x;
}

ull total_digits_of(ull n){
    ull count = 0;
    while (n != 0){
        n = n / 10;
        ++count;
    }
    return count;
}

ull nth_digit_of(ull num, ull rem){
    if(rem==0){return num % 10;}
    num++;
    return ((ull)((num - (num % (long long)pow10(total_digits_of(num)-rem)))/pow10(total_digits_of(num)-rem)))%10;
}

ull give_me_answer(ull n){
    ull c = 0;
    while(1){
        if(n <=(9*(c+1)*pow10(c))){c++;break;}
        else{n-=9*(c+1)*pow10(c);c++;}
    }
    ull the_og_number = pow10(c-1) - 1 + n/c; 
    return nth_digit_of(the_og_number,n%c);    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ull n;
        cin>>n;
        cout<<give_me_answer(n)<<endl;
    }
    return 0;
}
