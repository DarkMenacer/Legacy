#include <iostream>
#include <iterator>
#include <set>
#define nl cout<<'\n'
#define free_cin_cout cin.sync_with_stdio(false); cout.sync_with_stdio(false)
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
	free_cin_cout; fastIO;
	int n, m, x;
	cin>>n>>m;
	multiset<int> tickets;
	while(n--){
		cin>>x;
		tickets.insert(x);
	}
	while(m--){
		cin>>x;
		set<int>::iterator placer = tickets.lower_bound(x);
		if(x == *placer){
			cout<<*placer;
			tickets.erase(placer);
		}
		else if(placer == tickets.begin()){
			cout<< -1;
		}
		else{
			--placer;
			cout<<*placer;
			tickets.erase(placer);
		}
		nl;
	}
	return 0;
}
