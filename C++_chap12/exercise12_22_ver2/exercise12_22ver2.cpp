#include"Blob_ver5_1.h"
#include<iostream>
#include<string>
#include<initializer_list>
using std::initializer_list;
int main()
{
	initializer_list<std::string> str_lst = { "djsj","D","coup detat'" };
	const StrBlob Ob1(str_lst);
	ConstStrBlobPtr Ob3(Ob1, 0), * yaju_sakebi = &Ob3;
	ConstStrBlobPtr Ob4(Ob1, 1), * Ob2 = &Ob4;

	try {
		while (true)
		{
			std::cout << yaju_sakebi->deref() << " ";
			yaju_sakebi->incr();//Functio could change the object to which the pointer points.
		}
	}
	catch (std::out_of_range kskdfcje)
	{

	}





}