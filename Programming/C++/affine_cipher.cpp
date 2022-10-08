/* 
KQEREJEBCPPCJCRKIEACUZBKRVPKRBCIBQCARBJCVFCUPKRIOFKPACUZQEPBKRXPEIIEABDKPBCPFCDCCAFIEABDKPBCPFEQPKAZBKRHAIBKAPCCIBURCCDKDCCJCIDFUIXPAFFERBICZDFKABICBBENEFCUPJCVKABPCYDCCDPKBCOCPERKIVKSCPICBRKIJPKABI
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#define all(name) name.begin(),name.end()
#define display_paired(name) for(auto it: name){cout<<it.first<<"("<<it.second<<") ";}cout<<"\n"
#define what_is_here(name) cout<<#name<<": "<<name<<"\n"
using namespace std;

map<char, float> english_stats = {
    {'A',8.2},
    {'B',1.5},
    {'C',2.8},
    {'D',4.3},
    {'E',12.7},
    {'F',2.2},
    {'G',2.0},
    {'H',6.1},
    {'I',7.0},
    {'J',0.2},
    {'K',0.8},
    {'L',4.0},
    {'M',2.4},
    {'N',6.7},
    {'O',7.5},
    {'P',1.9},
    {'Q',0.1},
    {'R',6.0},
    {'S',6.3},
    {'T',9.1},
    {'U',2.8},
    {'V',1.0},
    {'W',2.3},
    {'X',0.1},
    {'Y',2.0},
    {'Z',1.5}
};

template <class T1, class T2>
vector< pair<T1,T2> > sort_map_by_value(map<T1,T2> &input){
    vector< pair<T1,T2> > sorter(input.begin(),input.end());
    sort(sorter.begin(),sorter.end(),[](auto &left, auto &right){return left.second > right.second;});
    return sorter;
}

string take_input(){
    cout<<"Enter the encypted message: ";
    string input;
    cin>>input;
    return input;
}


//Problem is here for sure
void check_n_change_range(int *x){
    if(*x<0){
        *x=26+(*x%26)+64;
    }
    else{
        //here, problem is here
        if(*x<65){*x = 91-(65-*x);}
        else if(*x>90){*x = 64 + (*x-90);}
    }
    return;
}

int adjust_ascii(char c){return (int)c-64;}

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

void print_possible_combos(float a, int b, string input){
    if(a==1){
        for(auto in: input){
            int temp = b-(int)in;
            check_n_change_range(&temp);
            cout<<(char)temp;
        }
    }
    if(a==-1){
        for(auto in: input){
            int temp = (int)in - b;
            check_n_change_range(&temp);
            cout<<(char)temp;
        }
    }
    cout<<endl<<endl;
}


void break_affine_cipher(vector < pair<char, float> > &sorted_stats, vector< pair<char, float> > &frequencies, string &input){
    pair <int, int> key;
    float deno = (int)sorted_stats[0].first - (int)sorted_stats[1].first;
    for(int j=0; j<21;++j){
        for(int i=0;i<21;++i){
            float nume = (int)frequencies[j].first - (int)frequencies[i].first;
            if(nume){
                float a = nume/deno;
                if(ceilf(a) == a && floorf(a) == a){
                    int b = adjust_ascii(frequencies[j].first) - 5 * a;
                    cout<<"E-> "<<frequencies[j].first<<" and";
                    cout<<" T-> "<<frequencies[i].first<<" ";cout<<"a: "<<a<<" and b: "<<b<<" Enc(x)= "<<a<<"x+("<<b<<") "<<endl;
                    //Also try checking whether A maps to a correct alphabet using the above values of a and b.
                    //print_possible_combos(a, b, input);
                }
            }
        }
    }
}

int main(){
    string input = take_input();
    cout<<"English Stats:\n";
    vector< pair<char, float> > sorted_stats = sort_map_by_value(english_stats);    
    for(auto it: sorted_stats){cout<<it.first<<"| "<<it.second<<"%"<<endl;}

    map<char, float> occurences; 
    for(auto it: input){occurences[it]++;}
    vector< pair<char, float> > frequencies = sort_map_by_value(occurences);
    for(auto it: frequencies){it.second = it.second/input.size()*100;}
    cout<<"Frequency distribution of letters:"<<endl;
    for(auto it: frequencies){cout<<it.first<<"| "<<it.second<<"%"<<endl;}
    cout<<endl;

    break_affine_cipher(sorted_stats,frequencies, input);

    for(auto in: input){
        int temp = (int)in-21;
        check_n_change_range(&temp);
        cout<<(char)temp;
    }

    return 0;
}

/*
E-> C and T-> R a: 1 and b: -2 Enc(x)= 1x+(-2) 
E-> B and T-> Q a: 1 and b: -3 Enc(x)= 1x+(-3) 
E-> P and T-> A a: -1 and b: 21 Enc(x)= -1x+(21) 
E-> K and T-> Z a: 1 and b: 6 Enc(x)= 1x+(6) 
E-> I and T-> X a: 1 and b: 4 Enc(x)= 1x+(4) 
E-> A and T-> P a: 1 and b: -4 Enc(x)= 1x+(-4) 
E-> R and T-> C a: -1 and b: 23 Enc(x)= -1x+(23) 
E-> F and T-> U a: 1 and b: 1 Enc(x)= 1x+(1) 
E-> D and T-> S a: 1 and b: -1 Enc(x)= 1x+(-1) 
E-> J and T-> Y a: 1 and b: 5 Enc(x)= 1x+(5) 
E-> U and T-> F a: -1 and b: 26 Enc(x)= -1x+(26) 
E-> Z and T-> K a: -1 and b: 31 Enc(x)= -1x+(31) 
E-> Q and T-> B a: -1 and b: 22 Enc(x)= -1x+(22) 
E-> X and T-> I a: -1 and b: 29 Enc(x)= -1x+(29) 
E-> S and T-> D a: -1 and b: 24 Enc(x)= -1x+(24) 
E-> Y and T-> J a: -1 and b: 30 Enc(x)= -1x+(30) 
*/