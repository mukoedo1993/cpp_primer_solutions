#include<memory>
#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<initializer_list>
#include"Blob.h"

int main()
{
	StrBlob b1;
	{
		StrBlob b2 = { "a","an","the" };
		b1 = b2;
		b2.push_back("about");
	}
	//Redeclare and define b2
	StrBlob b2 = { "sd" };
	std::cout << b2.size()<< std::endl;//1.But, notice that it shows the b2 in the block was destroyed,
	//as soon as it compiles smoothly.
	std::cout << b1.size() << std::endl;//4. 
}