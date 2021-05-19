//exercise 13_53:
#include"hasptr_ver2.h"
int main()
{

	std::string str1("dojo");
	std::string str2("ranch");
	std::cout << "part 1: ";
	HasPtr H(str1), H2(str2);
	std::cout << "\npart 2: ";
	HasPtr* H3 = new HasPtr("karaoke");
		std::cout << "\npart 3: ";
	H = H2;//copy constructor called(in a copy-and-move assignment )
	std::cout << "\npart 4: ";
	H = std::move(*H3);//move constructor called(in a copy-and-move assignment)

}