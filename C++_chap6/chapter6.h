#ifndef CHAPTER6_H
#define CHAPTER6_H
#include<iostream>
struct t {
	int f() { int s=1; return s; }
	 void f2() {
		std::cout << "f2 function is executed!" << std::endl;
	}
	int calc(int v1, int v2) { return (v1 % v2); }
	double square(double x) { return (x * x); }
};
static int kk()
{
	int k1 = 20;
	return k1;
};// the kk function will be internal, it will not run out of the range.
#endif