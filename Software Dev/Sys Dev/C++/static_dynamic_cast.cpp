#include <iostream>

class Parent {
	public:
		Parent(){}
		virtual ~Parent(){}
};

class ChildA: public Parent {
	public:
		ChildA(){}
		void foo(){}
};

void learn_static_cast(){
	int *integer = new int(5);
	delete integer;
	// TODO: Understand the difference between static and dynamic_cast
}

void learn_dynamic_cast(){
	// A pointer of Parent can reference it's child class
	Parent *p = new ChildA();

	// But once it cannot be type-casted back to being ChildA
	ChildA *ca = p;

	// So we need to explicitly mention it's type
	ChildA *ca_explicit = (ChildA *) p;

	// But this is dangerous. A better approach is to use dynamic_cast instead which throws null in case of incompatibility
	ChildA *ca_d = dynamic_cast<ChildA *>(p);
	ca_d->foo();
}

int main(){
	learn_static_cast();

	learn_dynamic_cast();

	return 0;
}
