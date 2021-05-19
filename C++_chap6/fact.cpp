#include<iostream>
#include<stdexcept>
// factMain.cpp fact.cpp chapter6.h should be put together.
int fact(int k)
{
	int t = 1;
	if (k > 12 || k < 0)throw(std::invalid_argument("too large or too small!"));
	while (k > 1)
		t = t * k--;
	return t;
}