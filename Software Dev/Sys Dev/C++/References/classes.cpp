#include <iostream>
#include <string>
#include <memory>

// Use a struct only for passive objects that carry data; everything else is a class.

class Hollow_Knight {
	private:
		// Add _ suffix to private variables
		int level_;
		std::string name_;
	public:
		// This is member initialisation list constructor
		Hollow_Knight(int level, std::string name) : level_(level), name_(name.append("_san")){}

		// This is destructor
		~Hollow_Knight(){std::cout<<this->get_name()<<" destroyed\n";}

		// Prefer declaring methods as const
		int get_level() const {return this->level_;}

		virtual std::string get_name(){
			return this->name_;
		}

		// Operator overloading
		Hollow_Knight operator+(const Hollow_Knight &h){
			Hollow_Knight returner(0, this->get_name().append(h.name_));
			returner.level_ = h.get_level()+this->get_level();
			return returner;
		}
};

class Player: public Hollow_Knight {
	// Constructors and Destructors aren't inherited by default
	using Hollow_Knight::Hollow_Knight;
};

class Enemy: private Hollow_Knight {
	public:
		Enemy(int level) : Hollow_Knight(level, ""){}

		// Overriding base class function
		std::string get_name(){return "Enemy";}
};

int main(){
	// 3 ways to create an object

	Hollow_Knight hk(10, "Wall");
	std::unique_ptr<Player> p = std::make_unique<Player>(5, "Pranav");
	Enemy e = 5;

	// I am going to prefer the first one and the second one
	std::cout<<hk.get_name()<<std::endl;
	std::cout<<p->get_level()<<") "<<e.get_name()<<std::endl;

	// Operator Overloading in action
	Hollow_Knight hk2(5, "_appended");
	Hollow_Knight hk_add = hk+hk2;
	std::cout<<hk_add.get_name()<<" "<<hk_add.get_level()<<std::endl;

	return 0;
}
