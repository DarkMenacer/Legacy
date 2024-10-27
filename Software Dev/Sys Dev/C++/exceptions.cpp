#include <iostream>

float divide(float dividend, float divisor){
	if(divisor == 0){
		throw "Division by zero";
	}
	return dividend/divisor;
}

int main(){
	try{
		int res = divide(5, 0);
	}
	catch(const std::exception &e){
		std::cerr<<"Error: "<<e.what()<<std::endl;
	}
	return 0;
}
