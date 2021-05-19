#include<iostream>
#include<string>
#include<vector>
using std::cout; using std::vector;
using std::string;
using std::boolalpha; using std::endl;
int exercise6_54_1(int a, int b)
{
	int c = a + b;
	return c;
}
int add(int a, int b)
{
	int c = a + b;
	return c;
}
int minus(int a, int b)
{
	int c = a - b;
	return c;
}
int multiple(int a, int b)
{
	int c = a * b;
	return c;
}

int divide(int a, int b)
{
	int c = a / b;
	return c;
}
//ptr1_1 is a pointer that points

int main()
{
	vector<decltype(exercise6_54_1)*>kk;
	int a = 124, b = 4;
	kk.push_back(*add);
	kk.push_back(*minus);
	kk.push_back(*multiple);
	kk.push_back(*divide);
	//For the exercise 6.56 part:
	cout << (*(kk[0]))(124, 4)<<endl;//add
	cout << (*(kk[1]))(124, 4) << endl;//minus
	cout << (*(kk[2]))(124, 4) << endl;//multiple
	cout << (*(kk[3]))(124, 4) << endl;//division
	//Correct solutions are given respectively.
}
