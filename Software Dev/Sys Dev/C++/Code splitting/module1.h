#pragma once //For header file to be included only once even if it is used in multiple files

// This file only contains declarations
void complex_function(int, int);

class Hollow_Knight {
	private:
		int level;
	public:
		Hollow_Knight(int);
		int get_level();
};

// NOTE: It is recommended to not have any function definitions here as it leads to redefinition error
