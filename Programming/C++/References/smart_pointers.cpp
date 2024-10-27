#include <iostream>
#include <memory>
#include <vector>

class Entity {
	public:
		Entity(){
			std::cout<<"Entity created";
		}

		~Entity(){
			std::cout<<"Entity destroyed";
		}
};

int main(){
	// Raw pointers need manual memory management
	Entity *p = new Entity();
	// more statements
	delete p;
	// If some exception is thrown in the more statements, that can result in the memory not being destroyed

	// Smart pointers provide some relief in memory management while simulateneously providing capability to manage memory
	// They are scoped pointers
	{
		std::unique_ptr<Entity> un_p = std::make_unique<Entity>();
	}

	// unique pointers cannot be copied, i.e.
	// std::unique_ptr<Entity> dup_un_p = un_p;
	// results in compile time error
	// Instead use shared_ptr for sharing ptr
	std::shared_ptr<Entity> sh_p1 = std::make_shared<Entity>();
	std::shared_ptr<Entity> sh_p2 = sh_p1;
	// Only when all the shared pointers go out of scope does the memory get deallocated.

	// But what if you don't want that to happen, i.e. deallocate memory when few pointers go out of scope
	// That is where weak pointer comes into picture;
	std::weak_ptr<Entity> w_p = sh_p1;
	// Even if weak pointer doesn't go out of scope, but all the shared pointers do, the memory is deallocated.
	return 0;
}
