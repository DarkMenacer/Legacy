#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#define all(name) name.begin(), name.end()
#define free_cin_cout cin.sync_with_stdio(false); cout.sync_with_stdio(false)
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define take_loop_input_in(name, size) for(unsigned i = 0; i < size; ++i){cin>>name[i];}
using namespace std;

int main(){
	free_cin_cout; fastIO;
	unsigned n, x, no_of_gandolas = 0;
	cin>>n>>x;
	vector<unsigned> children(n, 0);
	take_loop_input_in(children, n);
	sort(all(children));
	vector<unsigned>:: iterator itr = children.begin();
	vector<unsigned>:: reverse_iterator ritr = children.rbegin();
	while(itr <= ritr.base()-1){
		if(*itr+*ritr <= x){++itr;}
		++ritr;
		no_of_gandolas++;
	}
	cout<<no_of_gandolas;
	return 0;
}
