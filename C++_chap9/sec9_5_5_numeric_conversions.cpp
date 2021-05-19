#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using std::string;

int main()
{
	int i = 42;
	string s = std::to_string(i);//converts the int i to its character representation
	std::cout << s << std::endl;
	double d = stod(s);//converts the string s to floating-point


	//convert the first substring in s that starts with a digit, d=3.14
	string s2 = "pi = 3.14"; string number = "-+.0123456789";
	d = stod(s2.substr(s2.find_first_of(number)));
	std::cout << d << std::endl;

}