#include<iostream>
int main()
{
	const int v2 = 13; int v1 = v2;
	std::cout << v1 << std::endl;
	int* p1 = &v1, & r1 = v1;
	const int i = 20;
	const int* p2 = &v2, *const p3 = &i, & r2 = v2;
	std::cout << *p3 << std::endl;
	//exercise 2.31
	r1 = v2;
	//p1 = p2;<-ERROR: We may store the address of a const object only in a pointer to const:
	p2 = p1;
	std::cout << *p2 << std::endl;
	//But not vice versa.
	//p3 = p1;<-ERROR
	p2= p3;

}