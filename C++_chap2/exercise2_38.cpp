#include<iostream>
int main()
{
	int a = 3, * b = &a;
	int a1 = 20;
	auto c = a1;
	auto d = a;
	decltype(*b)d2 = a;
	decltype(a1)c2 = a1;
	d2 = 22;
	//part 1: deduce different types:
	std::cout << a << std::endl;//d2 is reference to the int a.
	std::cout << d << std::endl;//d is an int.
	//part 2: deduce same types:
	std::cout << c << std::endl;
	std::cout << c2 << std::endl;
}