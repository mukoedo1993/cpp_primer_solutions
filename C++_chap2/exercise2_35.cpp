#include<iostream>
int main()
{
	const int i = 42; const int i2 = 49;
	auto j = i;
	j = 43;
	const auto& k = i;
	auto p = &i;
	p = &i2;
	std::cout << *p << std::endl;
	const auto j2 = i, & k2 = i;
	auto k3 = i2;
	std::cout << k3 << std::endl;
	const auto& j4 = 64.5,&j5=64.;
	std::cout << j4 << " " << std::endl;

}