#include<memory>
#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<initializer_list>
#include"blob_ex12_2.h"
using std::string;
using std::vector;
using std::make_shared;
int main()
{
	//Some tests:
	std::initializer_list<string>str1 = {"jf","fdj","tk"};
	std::initializer_list<string>str2 = {  };
	std::initializer_list<string>str3 = { "","fdj","tk" };
	StrBlob Ob1(str1);  const StrBlob Ob2(str2);
	const StrBlob Ob3(str3);
	try {
		Ob2.back();
	}
	catch (...)
	{
		std::cout << "error!\n";//It prints out
	}
	Ob1.push_back(string("jshf"));
	//Ob2.back();//out_of_range error
	std::cout<<Ob1.back()<<std::endl;
	std::cout<<Ob1.front();

	std::cout << Ob3.back() << std::endl;
	std::cout << Ob3.front() << std::endl;
}
