#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#define nextline cout<<"\n"
using namespace std;

int fact(int n){return (n==1 || n==0) ? 1: n * fact(n - 1);}

int total(int n ,vector<int> num){
    int d1 = 1;
    for(int i=0;i<num.size();++i){d1 *= fact(num[i]);}
    return (fact(n))/d1;
}

int main(){
    string word;
    getline(cin,word);
    vector<int> num; vector<char> letter;
    vector<int>::iterator itrv; vector<char>::iterator itrc;
    for(int i=0;i<word.length();++i){
        itrc = find(letter.begin(),letter.end(),word[i]);
        if(itrc==letter.end()){
            num.push_back(count(word.begin(),word.end(),word[i]));
            letter.push_back(word[i]);
        }
    }
    cout<<total(word.length(),num);nextline;
    sort(word.begin(),word.end());
    for(int i=0;i<total(word.length(),num);++i){
        cout<<word<<endl;
        next_permutation(word.begin(),word.end());
    }
    return 0;
}