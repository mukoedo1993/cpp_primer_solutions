#include<string>
#include<iostream>
#include<fstream>
using std::string;

int main()
{
	std::ofstream output("ex9_48o.txt");
	string name("AnnaBelle");
	string Numbers("0123456789");

	/* 
	*s.find(s2,pos)
	* Look for the string s2 starting at position pos 
	*in s.pos defaults to 0.
	*/

	auto pos = Numbers.find(name);
	output<<"Our result is: " << pos << std::endl;
}