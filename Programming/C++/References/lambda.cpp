#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	// Lambda functions are anonymous functions i.e. nameless and to be used only where they are declared
	// General structure:
	// [](){} where
	//     [] is capture clause used for reading in-scope variables
	//     () is the argument declaration used for reading variables passed in the function
	//     {} is the function definition

	vector<int> marks({85, 93, 77, 72, 65});
	int hundred = 100;
	int change_me = 5;
	for_each(marks.begin(), marks.end(), [hundred, &change_me](int mark){cout<<mark*hundred<<" "; change_me += 1;});
	cout<<change_me;
	return 0;
}
