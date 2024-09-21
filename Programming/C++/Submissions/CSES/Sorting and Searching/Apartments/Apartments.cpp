#include <algorithm>
#include <iostream>
#include <deque>
#define free_cin_cout cin.sync_with_stdio(false); cout.sync_with_stdio(false)
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define take_loop_input_in(name, size) for(int i = 0; i < size; ++i){cin>>name[i];}
using namespace std;

int main(){
	free_cin_cout; fastIO;
	unsigned n, m, k, i = 0, settled_applicants = 0;
	cin>>n>>m>>k;
	deque<int> applicants(n, 0), apartments(m, 0);
	take_loop_input_in(applicants, n);
	take_loop_input_in(apartments, m);
	sort(applicants.begin(), applicants.end());
	sort(apartments.begin(), apartments.end());
	while(i < applicants.size() && i < apartments.size()){
		if(abs(apartments[i]-applicants[i]) <= k){
			settled_applicants++;
			apartments.pop_front();
			applicants.pop_front();
		}
		else {
			if(applicants[i] > apartments[i]){
				apartments.pop_front();
			}
			else {
				applicants.pop_front();
			}
		}
	}
	cout<<settled_applicants;
	return 0;
}
