/*
Name:-              Subarray Distinct Values
Platform:-          CSES
Date:-              12 April 2022
Type of Problem:-   Two pointer, Map, Searching
Complexity:-        O(nlog(n))
Status:-            Solved

Solution in brief:
Input is taken in vector 'integers'. Two pointers, 'i' and 'j' are used.
The basic idea is that a map is used to keep track of no. of distinct values in the subarray bounded by i and j,
key representing the integer and value representing the no. of occurences.
Till the size of the map is less-than-or-equal-to k, j is kept on incremented and values are kept on added in the map.
When the size of the map becomes larger than k, integers[i] is decremented (and removed if 0 occurences), till map.size() <= k.
Now, during this decrementation, answer is added with the no. of subarrays starting strictly from the 'i'th index only.
This can be given by the [(j-i)*(j-i-1)/2] - [(j-i-1)*(j-i-2)/2] = j-i-1
                         (total subarrays      (total subarrays
                            from i to j)         from i+1 to j)
Therefore answer+=(j-i-1)
When j reaches end of the integers, there is no need to subtract 'total subarrays from i+1 to j',
(as no new element is going to be added further), therefore answer+= (j-i)*(j-i-1)/2
And then answer is printed out.

Sample to understand solution:
Input:-
6 3
1 5 3 1 2 4

Output:-
16

Explanation:-
    1 5 3 1 2 4
    i j
    
    i: 0 j: 1 map: 1(1) 
    i: 0 j: 2 map: 1(1) 5(1) 
    i: 0 j: 3 map: 1(1) 3(1) 5(1) 
    i: 0 j: 4 map: 1(2) 3(1) 5(1) 
    i: 0 j: 5 map: 1(2) 2(1) 3(1) 5(1) 
    1 decremented 
    answer: 4
    5 decremented 5 erased 
    answer: 7
    i: 2 j: 6 distinct: 1(1) 2(1) 3(1) 4(1) 
    3 decremented 3 erased 
    answer: 10
    i: 3 j: 7 distinct: 0(1) 1(1) 2(1) 4(1) 
    answer: 16

*/

#include <iostream>
#include <vector>
#include <map>
#define ll long long
#define vll vector<ll>
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
using namespace std;

ll give_me_answer(vll &integers, ll k){
    ll answer = 0;
    ll i = 0, j = 1;
    map<ll,ll> distinct;
    distinct[integers[i]]++;
    while(1){
        if(j==integers.size()+1){
            answer += (j-i)*(j-i-1)/2;
            break;
        }
        while(distinct.size() > k){
            auto it = distinct.find(integers[i]);
            it->second--;
            if(!(it->second)){distinct.erase(integers[i]);}
            answer+=j-i-1;
            i++;
        }
        distinct[integers[j++]]++;
    }
    return answer;
}

int main(){
    ll n,k;
    cin>>n>>k;
    vll integers(n);
    take_loop_input_in(integers,n);
    cout<<give_me_answer(integers,k);
    return 0;
}
