/*
Name:-              Reverse words in a string
Platform:-          LeetCode
Date:-              25 August 2022
Type of Problem:-   Two Pointer
Complexity:-        O(n²)
Status:-            Solved

Solution in brief:
For any string, a₁a₂...aₙ, start with 2 pointers, i and j both at begin.
Increment j till a space is reached. After that keep pushing back s[j] and decrement j till j again reaches i.
Remember to store the value of j before first decrementing because after j reaches i, 
and all of the word is pushed backwards in reverse order, move both pointers to j's earlier position (to the next word).
Once all of the string is traversed this way, reverse the string and erase the last half of the string to get the final answer.

Sample to understand solution:
Input:-
the sky is blue

Output:-
blue is sky the

Explanation:-
the sky is blue e
the sky is blue eh
the sky is blue eht
the sky is blue eht 
the sky is blue eht y
the sky is blue eht yk
the sky is blue eht yks
the sky is blue eht yks 
the sky is blue eht yks s
the sky is blue eht yks si
the sky is blue eht yks si e
the sky is blue eht yks si eu
the sky is blue eht yks si eul
the sky is blue eht yks si eulb
Reverse the string
blue is sky the eulb si yks eht
Kill the last half
blue is sky the
*/

#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s) {
    int f = 0,e = f;
    int n = s.length(), new_n = n;
    int flag = 0;
    if(s[n-1] == ' '){flag = 1;}
    int i = 0;
    while(i<n){
        while(s[e] != ' '){
            ++e;++i;
            if(i==n+1){break;}
        }
        while(e != f){
            s.push_back(s[e]);
            e--;
        }
        if(s[e] != ' '){s.push_back(s[e]);}
        else{new_n--;}
        f=0;
        ++i;
        f+=i;
        e=f;
    }
    reverse(s.begin(),s.end());
    s.erase(new_n-flag);
    return s;
}

int main(){
    string input;
    cin>>input;
    cout<<reverseWords(input);
    return 0;
}