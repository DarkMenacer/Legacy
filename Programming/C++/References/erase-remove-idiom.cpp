#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	std::vector<int> vec ({1, 2, 3, 4, 5});
	for (auto it: vec){
		std::cout<<it<<" ";
	}
	std::cout<<std::endl;
	vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());
	for (auto it: vec){
		std::cout<<it<<" ";
	}
	std::cout<<std::endl;
	vec.erase(std::remove_if(vec.begin(), vec.end(), [](int i){return i%2==0;}), vec.end());
	for (auto it: vec){
		std::cout<<it<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
