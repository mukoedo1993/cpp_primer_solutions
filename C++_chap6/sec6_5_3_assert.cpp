#include<iostream>
#include<cassert>
#include<string>
using std::string;
int main()
{
	//Aids for debugging
	/*
	C++ programmers sometimes use a technique similar to header guards to 
	conditionally execute debugging code.
	*/
	/**/
	string word = "sfdsdffshehe";
	int threshold;
	std::cin >> threshold;
	/*
	If we input a negative number, the Visual Studio will pop out 
	a window notices us that there is a debug error.
	*/
	assert(threshold > 0);

	//std::cout << std::boolalpha;
	if (word.size() > threshold)
		(std::cout << "NMSL!");
	else(std::cout << "gougou!");
}

