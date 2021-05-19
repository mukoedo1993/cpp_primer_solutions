#include<iostream>
int main()
{
	int a = 3, b = 4.4;// b is converted to 5.
	decltype(a)c = a;
	decltype(a = b)d = b;// 
	d = 9;

	std::cout << b << std::endl;
}