#include<iostream>
#include<vector>
using std::vector;
using std::string;
/*
1:We can define vectors to hold objects of most any type.
2: Because references are not objects, we cannot have a vector of references.
*/
int main()
{
	vector<string> svec;//default initialization: svec has no elements
	vector<int> ivec;//initially empty
	//give ivec some values
	vector<int> ivec2(ivec);//copy elements of ivec into ivec2
	vector<int>ivec3 = ivec2;//copy elements of ivec into ivec3
	//vector<string>svec(ivec2);//error: svec holds strings, not ints.
	vector<string>articles = { "a","an","the" };//list initialization
	vector<int>ivec4(10, -1);
	std::cout << ivec4[1] << std::endl;
	vector<string> svec2(9, "Hi");
	/*
	1: If the vector holds elements of a built-in type, such as int, then the element
	initializer has a value of 0.
	2:If the elements are of a class type, such as string, then the element initializer is itself
	default initialized.
	*/
	vector<string> svec5(10);//ten elements, each an empty string.
	vector<int>ivec5(10);//ten elements, each initialized to 0.
	int unit_gold{ 1};
	vector<vector<int>>ivec7;
	//vector<string>svec6 = ivec7;
	vector<string> svec6(10, "null");
	vector<string>v6{ 10 };
	std::cout << v6[1] << std::endl;
	// v6 is initialized as a vector of empty strings.
	vector<string>v7{ 10,"Hi" };
	std::cout << v7[1] << std::endl;
}