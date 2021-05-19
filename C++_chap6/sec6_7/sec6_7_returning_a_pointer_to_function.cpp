#include<iostream>
#include<string>
using std::cout;
using std::string;
using std::boolalpha; using std::endl;
int main() 
{
	using F = int(int*, int);//F is a function type.
	using PF = int(*)(int*, int);//PF is a pointer type.
	/*
	Here we used type alias declarations to define F as a function type
	and PF as a pointer to function type. The things to keep in mind is
	that, unlike what happens to parameters that have function type, the return
	type is not automatically converted to a pointer type. We must explicitly
	specify that the return type is a pointer type.
	*/
	PF f1(int);//ok:
	//F f1(int);//error: F is a function type; f1 cannot return a function.
	F* f1(int);//ok: explicitly specify that the return type is a pointer to function.

	//other ways:
	//directly:
	int(*f2(int))(int*, int);
	//trailing return:
	auto f3(int)->int(*)(int*, int);
}