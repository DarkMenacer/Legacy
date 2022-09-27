/*
Breaking the Caeser Cipher.

Dynamic code hence input can be given on the way.

Sample input = xultpaajcxitltlxaarpjhtiwtgxktghidhipxciwtvgtpilpitghlxiwiwtxgqadds

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void check_n_change_range(int *x){
    if(*x<97){*x = 123-(97-*x);}
    else if(*x>122){*x = 96 + (*x-122);}
    return;
}

void display_shifted_ref_e(char c, string input){
    cout<<"Substituting "<<c<<" as e"<<endl;
    int cipher = (int)c - int('e');
    for(auto it: input){
        int shift = int(it) + cipher;
        check_n_change_range(&shift);
        cout<<(char)shift;
    }
    cout<<endl<<endl;
}

int main(){
    cout<<"Enter the encypted message: ";
    string input;
    cin>>input;
    map<char, float> occurences; 
    vector< pair<char, float> > frequencies;
    for(auto it: input){occurences[it]++;}
    for(auto it: occurences){frequencies.push_back(make_pair(it.first,it.second/input.size()*100));}
    sort(frequencies.begin(),frequencies.end(),[](auto &left, auto &right){return left.second > right.second;});
    cout<<"Frequency distribution of letters:"<<endl;
    for(auto it: frequencies){cout<<it.first<<"| "<<it.second<<"%"<<endl;}
    cout<<endl;
    for(auto it: frequencies){
        display_shifted_ref_e(it.first,input);
    }
    return 0;
}