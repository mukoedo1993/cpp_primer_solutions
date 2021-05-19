#include<iostream>
int main()
{
	int a = 3, b = 4;
	decltype(a)c = a;
	decltype((b))d = a;
	++c;
	++d;
	std::cout <<a<< std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
}