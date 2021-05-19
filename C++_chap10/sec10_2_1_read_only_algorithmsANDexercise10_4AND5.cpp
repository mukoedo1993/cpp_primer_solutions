#include<vector>
#include<iostream>
#include<string>
#include<numeric>//accumulate
#include<algorithm>
#include<list>
using std::vector;
using std::list;
using std::cout; 
using std::string; using std::endl;
int main()
{
	vector<int>vec = { 1,4,5,6,7,0,10,2,3,5,6 };
	//sum the elements in vec starting the summation with the value 0
	int sum = accumulate(vec.cbegin(), vec.cend(), 0);
	//sets sum equal to the sum of the elements in vec, using 0 as the
	//starting point for the summation.

	vector<string>v = { "kk","ldsjh","den","hell","resident","biohazard" };
	string sum1 = accumulate(v.cbegin(), v.cend(), string(""));

	//Attention!
	//If we pass a string literal to sum, the type of the object used to hold the sum would 
	//be const char*. That type determines which + operator is used. Because there is no + operator
	//for type const char*, this call will not compile.
	//string sum1 = accumulate(v.cbegin(), v.cend(), "");
	cout << sum1 << endl;

	vector<string>roster1 = {"Happy","NewYear","sTAR"};
	list<const char*>roster2 = { "Happy","NewYear","sTAR" };
	cout << std::boolalpha;
	cout << equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());

	//exercise10_4
	vector<int>veci_10_4 = { 1,2,3,4,5,6,7,8,9,10 };
	vector<double>vecd_10_4 = { 1.9,2.9,3.9,4.9,5.9,6.9,7.99,8.99,9.99,10.99 };
	auto result_10_4i = accumulate(veci_10_4.cbegin(), veci_10_4.cend(), 0);
	auto result_10_4d = accumulate(vecd_10_4.cbegin(), vecd_10_4.cend(), 0);
	std::cout << endl<< "exercise 10_4's result: " << (result_10_4i - result_10_4d)
		<<endl;
	//Result: 0. 
	//Conclusion: We could see all decimal parts are lost.

	//exercise 10_5
	vector < const char* >C_style_string1= {"haha","iloveguitar"};//C_style string
	vector < const char* >C_style_string2 = { "haha","iloveguitar" };
	vector<string>CPP_style_string= { "haha","iloveguitar" };
	vector<string>CPP_style_string1 = { "haha","iloveguitar" };

	//1: C vs C++
	cout << endl << "Compare one C-style string with an identical C++ style string: "
		<< equal(C_style_string1.cbegin(), C_style_string1.cend(), CPP_style_string.cbegin());
	//error: it says C style string must have class type.

	//2: C vs C:
	cout <<endl<<"Compare both two identical C-style string: "
		 << equal(C_style_string1.cbegin(), C_style_string1.cend(), C_style_string2.cbegin());

	//3: C++ vs C++
	cout << endl << "Compare both two identical C++-style string: "
		<< equal(CPP_style_string.cbegin(), CPP_style_string.cend(), CPP_style_string1.cbegin());

	//Conclusion: all three are same(true).
}