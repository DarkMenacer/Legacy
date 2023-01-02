#include <iostream>
#include <cmath>
#define op(x,y) cout<<x<<" "<<y<<endl
using namespace std;

void swap(char *x, char *y){char temp = *x;*x = *y;*y = temp;}

void foo(int n,char a,char b,char c){
    if(n==1){op(a,c);return;}
    if(n==2){op(a,b);op(a,c);op(b,c);return;}
    swap(&b,&c);
    foo(n-1,a,b,c);
    swap(&b,&c);
    op(a,c);
    swap(&a,&b);
    foo(n-1,a,b,c);
}

int main(){
    int n;
    cin>>n;
    int k = pow(2,n)-1;
    cout<<k<<endl;
    char a = '1',b='2',c='3';
    foo(n,a,b,c);
    return 0;
}