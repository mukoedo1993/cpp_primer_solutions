#include<iostream>
#include<vector>
#include<stdexcept>
using std::vector;

using std::string;

int main()
{
	vector<int>empty_;


	vector<int>::iterator it1 = empty_.begin();
	//std::cout << *it1;


	//int in2 = empty_.front();
	//std::cout << in2;

	std::out_of_range Ob1("Out of range!");
	try {
		std::cout << empty_.at(0);
	}
	catch (...) { std::cerr << Ob1.what(); }//print Out of range!

	//std::cout << empty_[0];
}