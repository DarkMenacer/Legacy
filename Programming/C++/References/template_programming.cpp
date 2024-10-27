// Templates in C++ are basically compile-time type declarations
// The compiler declares the type for you

#include <iostream>

// All the below functions can be replaced with one template function
void Print(int x){std::cout<<x;}
void Print(float x){std::cout<<x;}

template <typename T>
void PrintT(T x){std::cout<<x;}

// The template function underneath creates the Print functions itself during the compile time

// This replication nature can be used to our advantage
template <int N>
class Array {
	public:
		int arr[N];
};

// Multiple template parameters can be passed as well
template<typename T, int N>
class MultiArray {
	public:
		T arr[N];
};

// Behavior can also be specialised for certain cases
template<int N>
class MultiArray<float, N> {
	public:
		float arr[N];
};

template<>
class MultiArray<double, 10> {
	public:
		double arr[10];
};

int main(){
	PrintT(5);

	// To explicitly specific the parameter to template function
	PrintT<int> (5);
	Array<7> arr;
	MultiArray<float, 3> float_array;
	return 0;
}
