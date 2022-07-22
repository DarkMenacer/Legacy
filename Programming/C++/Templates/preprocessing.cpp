//header files
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>   // set and multiset
#include <map>   // map and multimap
#include <unordered_set>  // unordered set/multiset
#include <unordered_map>  // unordered map/multimap
#include <iterator>
#include <algorithm>   // includes sort(), count()
#include <numeric>    // some numeric algorithm
#include <functional>
#include <tuple>
#include <stack>
#include <queue>
using namespace std;

//Macros

//*) general purpose
#define FOR(i,start,upper_limit) for(i=start;i<upper_limit;++i)
#define pb push_back
#define all(name) name.begin(),name.end()
#define ll long long
#define inf 1e9

//*) containers
#define vi vector<int>
#define vii vector < pair<int,int> >
#define si set<int>
#define msi multiset<int>

//*) taking inputs in containers
#define take_loop_input_in(name,size) for(int i=0;i<size;++i){cin>>name[i];}
#define take_indexed_loop_input(name,size) for(int i=1;i<size+1;++i){int x;cin>>x;name.push_back(make_pair(x,i));}

//*) Pair
#define f first
#define s second
#define mp make_pair
#define p pair

//*) debugging
#define here cout<<"here\n"
#define nl cout<<'\n'
#define display(name) for(auto it: name){cout<<it<<" ";}cout<<"\n"
#define display_paired(name) for(auto it: name){cout<<it.first<<"("<<it.second<<") ";}cout<<"\n"
#define what_is_here(name) cout<<#name<<": "<<name<<"\n"

#define free_cin cin.sync_with_stdio(false)
#define free_cout cout.sync_with_stdio(false)

//Whatever this is
int32_t mod = 1e9 + 7;