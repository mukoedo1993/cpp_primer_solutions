#include<iostream>
int main()
{
	int i = 0;
	int* const pi1 = &i;//We cannot change the value of p1, const is top-level.
	const int ci = 42;//We cannot change ci; const is top-level.
	const int* p2 = &ci;//We can change p2, const is low level.
	const int* const p3 = p2;//right-most const is top-level, left-most is not.
	const int& r = ci;//const in reference types is always low-level
	i = ci; //ok: copying the value of ci; top-level const in ci is ignored.
	std::cout << *pi1 <<std::endl;//*pi1 42
	const int ddt = 27;
	p2 = &ddt;//ok: pointed-to typematches; top-level const in p3 is ignored.
	std::cout << *p3 << std::endl;//*p3 42<-top-level constant<-cannot be changed
	std::cout << *p2 << std::endl;//*p2 27<-low_level constant<-can be changed
	//int *p=p3; <-ERROR: p3 has a low-level const but p doesn't
	p2 = p3;//ok:p2 has the same low-level const qualification as p3
	p2 = &i;//OK: we can convert int* to const int*
	//int &r=ci; <-ERROR"can't bind an ordinary int& to a const int object.
	const int& r2 = i;//ok: can bind const int& to plain int
}