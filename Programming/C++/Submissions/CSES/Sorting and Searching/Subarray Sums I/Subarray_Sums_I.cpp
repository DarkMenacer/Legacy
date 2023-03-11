#include <iostream>
#include <vector>
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
using namespace std;
 
int main(){
    int n,x,i = 0,j = 0,answer = 0;
    cin>>n>>x;
    vector<int> a(n);
    take_loop_input_in(a,n);
    int sum = 0;
    while(i<n){
        if(sum == x){
            ++answer;
            sum-=a[i++];
            continue;
        }
        else if(sum > x){
            sum-=a[i++];
            continue;
        }
        if(j<n){sum+=a[j];++j;}
        else{break;}
    }
    cout<<answer;
    
    return 0;
}