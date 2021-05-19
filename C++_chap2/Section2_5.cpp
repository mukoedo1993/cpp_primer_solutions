#include <iostream>
int main()
{
	//Part section 2.5.1:
	typedef char* pstring;
	pstring q = 0;
	//The base type in these declarations is const pstring.
	const pstring k = 0;//k is a constant pointer to char.
	const pstring* ps;//ps is a pointer to a constant pointer to char.

	//Part section 2.5.2:
	auto i = 0, * p = &i;//ok: i is int and p is a pointer to int
	//auto sz=0, pi=3.14; error: inconsitent types for sz and pi.

	//In particular, when we use a reference as an initializer, the initializer is the
	//corresponding object.
	int i1 = 0, & r = i1;
	auto a = r;//a is an int(r is an alias for i, which has the type int)
	//Second, auto ordinarily ignores top-level consts.
	const int ci = i1, & cr = ci;
	auto b = ci;//b is an int(top-level const in ci is dropped)
	auto c = cr;//c is an int(cr is an alias for ci whose const is top-level)
	auto d = &i1;//d is an int*(& of an int object is int*)
	*d = 23;
	std::cout <<i1<< std::endl;
	auto e = &ci;//e is const int*(& of a const object is low-level object)

	//If we want the deduced type to have a top-level const, we must say so explicitly,
	//e.g.:
	const auto f11 = ci;//deduced type of ci is int, f has the type const int.
	//int& f11 = 42; error: we can't bind a plain reference to a literal.
	const int& f111 = 422;
	std::cout << f111 << std::endl;
	// When we define several variables in the same statement, it is important to
	// remember that a reference or pointer is part of a particular declarator and...
	//not of the base type for the declaration.
	auto k1 = ci, & l = i;//k1 is an int, l is int&
	//auto& m = ci, * p = &ci; 
    //error: type deduced from i is int; type deduced from &ci is const int.
	std::cout << "Before assignment, a is: " << a<<std::endl;
	a = 42;
	std::cout << "After assignment, a is: " << a << std::endl;
	std::cout << "Before assignment, b is: " << b << std::endl;
	b = 42;
	std::cout << "After assignment, b is: " << b << std::endl;
	std::cout << "Before assignment, c is: " << c << std::endl;
	c = 42;
	std::cout << "After assignment, c is: " << c << std::endl;
	//d = 42; error: d is a pointer.
	//e = 42;error: e is a pointer.
	//e = 42;// error: e is a reference to a constant int.

}