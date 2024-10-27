#include <iostream>
#include <vector>

// Namespaces can be used to seperate identifiers with same names
namespace pranavstl {
	class vector {
		public:
			vector(){std::cout<<"This is my vector";}
	};
}

// Or group similar type of entities together into one space
namespace Errors {}

int main(){
	pranavstl::vector();
	std::vector<int> ({1, 2});
	return 0;
}
