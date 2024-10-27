#include<iostream>
#include "module1.h"
// Remember to import the header and not the source file

int main(){
	Hollow_Knight hk(5);
	std::cout<<hk.get_level();
	return 0;
}

// To run this code, simple g++ main.cpp -o main && ./main won't work
// Instead the source files need to be linked using
// g++ main.cpp module1.cpp -o main && ./main
