#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

string Palin(string n){
    vector<int> vec;
    vector<char> in;
    string out = n;
    for(string::iterator itr = n.begin();itr<n.end();++itr){
        if(find(n.begin(),itr,*itr) == itr){
            vec.push_back(count(n.begin(),n.end(),*itr));
            in.push_back(*itr);
        }
    }

    if(n.length() % 2 == 0){
        for(vector<int>::iterator itr = vec.begin();itr<vec.end();++itr){
            if(*itr % 2!= 0){return "NO SOLUTION";}
        }
        int pos1 = 0,i1=0;
        for(string::const_iterator itr = in.begin();itr<in.end();++itr,++i1){
            for(int j = vec[i1];j>0;j-=2){
                out[pos1] = *itr;
                out[n.length()-1-pos1] = *itr;
                ++pos1;
            }
        }
    }
    else{
        bool flag = false;
        for(vector<int>::iterator itr = vec.begin();itr<vec.end();++itr){
            if(*itr % 2 != 0 && flag == true){return "NO SOLUTION";}
            if(*itr % 2!= 0 && flag == false){flag = true;}
        }
        int pos2=0,i2 =0;
        for(string::iterator itr = in.begin();itr<in.end();++itr,++i2){
            for(int j = vec[i2];j>0;j-=2){
                if(j!=1){
                    out[pos2] = *itr;
                    out[n.length()-1-pos2] = *itr;
                    ++pos2;
                }
                else{out[n.length()/2] = *itr;}
            }
        }
    }


    return out;
}



int main(){
    string n;
    getline(cin,n);
    cout<<Palin(n)<<endl;
    return 0;
}