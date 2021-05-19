#include "ex13_44_47.h"
#include "ex13_44_47.cpp"
#include<iostream>
#include<memory>
#include<string>
#include<vector>
using std::vector;
#include <algorithm>


std::ostream& operator<<(std::ostream &os, const String&Str)
{
	std::for_each(Str.c_str(),Str.c_str()+Str.length(),[&](char c)->void{os<<c;});
	
	return os;
}

int main()
{
	using std::move;
	char k[1] = "";
	char k2[4] = "dai";
	String Ob1(k), Ob2(k2);
	std::cout<<Ob1<<std::endl;//\n
	std::cout<<Ob2<<std::endl;//dai\n
	

}
