#include "ex13_44_47.h"
#include "ex13_44_47.cpp"
#include<iostream>
#include<memory>
#include<string>
#include<vector>
using std::vector;
#include <algorithm>
#include <iostream>
int main()
{
	using std::move;
	char k[1] = "";
	char k2[4] = "dai";
	String Ob1(k), Ob2(k2);

	//exercise 13_47:
	std::cout << "exercise 13_47:\n\n";
	String Ob3(Ob2), Ob4(k2);
	Ob3 = Ob4;
	vector<String>v_Str;
	std::cout << "Push_back start:\n";
	v_Str.push_back(k);
	std::cout << "STOP\n";
	v_Str.push_back(Ob4);
	std::cout << "STOP\n";
	v_Str.clear();
	v_Str.push_back(Ob3);
	std::cout << "STOP\n";
    v_Str.push_back(Ob2);
	std::cout << "STOP\n";
	v_Str.push_back(Ob1);
	String str1;
}


