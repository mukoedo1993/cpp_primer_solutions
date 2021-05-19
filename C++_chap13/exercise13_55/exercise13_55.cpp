#include"StrBlob_ex13_55.h"
//exercise 13_55:
int main()
{
	std::initializer_list<string>lst1 = {"dojo","N","Starbucks","bottle","reliable"};
	StrBlob Ob1(lst1); string str("los");
	Ob1.push_back("ko");//make a move
	Ob1.push_back(str);//make a copy
	Ob1.push_back(string("KO"));//make a move
}