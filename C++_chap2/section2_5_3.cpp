#include<iostream>
int main()
{
	int f = 20; double x = 20.5;
	decltype(f) sum = x;
	std::cout << sum << std::endl;
	const int ci = 0, & cj = ci;
	decltype(ci) x1 = 0;
	decltype(cj)y = x1;
	//decltype(cj)z;//error:z is a reference and must be initialized.

	//decltype of an expression can be a reference type
	int i = 42, * p = &i, & r = i;
	std::cout << i << std::endl;
	decltype(r + 0)b;//ok: add operation yields an int;b is an (uninitialized) int.
	decltype(*p)c=i;//error: c is int& and must be initialized
	c = 22;
	std::cout << i << std::endl;
	//decltype of a parenthesized variable is always a reference
	//decltype((i))d;//error:d is a reference and must be initialized.
	decltype(i)e;//OL: e is an (unitialized)int.
}