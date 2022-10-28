#include <iostream>
#include <string>
#include <iterator>
using namespace std;
 
int main(){
    string s;
    int count = 0, max = 0;
    getline(cin,s);
    for(int i = 0;i<s.size();++i){
        if(s[i]==s[i+1]){++count;}
        else{
            if(max<count){max = count;}
            count = 0;
        }
    }
    cout<<max+1;
}