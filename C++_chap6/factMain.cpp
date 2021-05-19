#include<iostream>
#include"chapter6.h"
#include<stdexcept>
// factMain.cpp fact.cpp chapter6.h should be put together.
int fact(int t);
int main()
{
	int t12_;
	std::cin >> t12_;
	try {
		
		std::cout << fact(t12_) << std::endl;
	}
	catch (std::invalid_argument nvl) {
		std::cerr << nvl.what() << std::endl;
	}
}