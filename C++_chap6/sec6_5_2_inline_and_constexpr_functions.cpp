#include<iostream>
#include<string>
#include"constexprANDinline.h"
using std::string;

	//page 224: inline version :find the shorter of two strings
	/*inline const string &//!!!!! in header file
		shorterString(const string & s1, const string & s2)
	{
		return s1.size() <= s2.size() ? s1 : s2;
	}*/

	//constexpr functions

	/*
	A constexpr function is a function that can be used in a constant
	expression. A const expr function is defined like any other function
	but must meet certain restrictions.
	The return type and the type of each parameter in must ne a literal type, and the function
	body must contain exactly one return statement.
	*/
	//constexpr int new_sz() { return 42; }
	//scale(arg) is a constant expression if arg is a constant expression//!!! in header file
	//constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }//!!! in header file
	int main()
	{
		constexpr int i1 = 12; int i2 = 10;
		string s1, s2;
		std::cin >> s1;
		std::cin >> s2;
		std::cout << shorterString(s1, s2) << std::endl;
		constexpr int foo = new_sz();//ok:foo is a constant expression
		//The scale function return a constant expression if its argument is a constant
		//expression but not otherwise:
		std::cout << scale(i1) << std::endl;
		std::cout << scale(i2) << std::endl;

		int arr[scale(2)];//ok:scale(2) is a constant expression
		int i = 2;//i is not a constant expression
		//int a2[scale(i)];//errpr:scale(i) is not a constant expression

}