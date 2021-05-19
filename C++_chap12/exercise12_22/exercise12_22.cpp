#include"Blob_ver5.h"
#include<iostream>
#include<string>
#include<initializer_list>
using std::initializer_list;
int main()
{
	initializer_list<string> str_lst = {"djsj","D","coup detat'"};
	const StrBlob Ob1(str_lst);
	auto Ob2 = &Ob1;
	ConstStrBlobPtr Ob3(Ob2,0);
	ConstStrBlobPtr Ob4(Ob2, 1);
	//Test 1:
	std::cout <<"Ob3: " <<Ob3.curr << " is the location we read in!\n";
	for (auto it=Ob3.wptr.lock()->begin()+Ob3.curr;it!= Ob3.wptr.lock()->end();it++)
	{
		
		std::cout << *it<<std::endl;//correct!!!!
		
	}
	//Test 2:
	std::cout << "Ob4: " << Ob4.curr << " is the location we read in!\n";
	for (auto it = Ob4.wptr.lock()->begin() + Ob4.curr; it != Ob4.wptr.lock()->end(); it++)
	{

		std::cout << *it << std::endl;//correct!!!!

	}
}