#include <iostream>
#include <boost/filesystem.hpp>

int main(){
	// boost::filesystem::path filePath{"./CMakeLists.txt"};

	// Check if the file exists
	if(boost::filesystem::exists(filePath)){
		std::cout<<filePath<<" exists."<<std::endl;

		// Open the file for reading
		std::ifstream file(filePath.string());

		if(file.is_open()){
			std::string line;
			while(std::getline(file, line)){
				std::cout<<line<<std::endl; // Print each line of the file
			}
			file.close();
		}
		else{
			std::cerr<<"Failed to open the file."<<std::endl;
		}
	}
	else{
		std::cout<<filePath<<" does not exist."<<std::endl;
	}
	return 0;
}
