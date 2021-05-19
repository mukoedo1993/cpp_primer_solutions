#pragma once
#ifndef SEC7_5_H
#define SEC7_5_H
#include<iostream>

class ConstRef {
	
public:
	ConstRef(int ii);

	class X 
	{
	public:
		X(int val) :j(val), i(j) {}
	private:
		int i;
		int j;
	};

	class Tt1 {
	public:
		//undefined: i is initialized before j
		
		Tt1(int);
		void printTt1()
		{
			std::cout << qq << std::endl;
		}
	private:
		int qq;
		int pp;
		int kk;
	};
	
private:
	int i;
	const int ci;
	int& ri;
};
ConstRef::Tt1::Tt1(int ii) :qq(ii), pp(ii), kk(ii)
{

}
//1:Members that are const or references must be initialized.
//2:Similarly, members that are of a class type that does not define a 
//default constructor also must be initialized.
//3: Not surprisingly, each member may be named only once in the constructor 
//initializers.


ConstRef::ConstRef(int ii):ci(ii),ri(ii),i(ii)//Initializers.
{
}
//ConstRef::ConstRef(int ii) 
//{
	//ci = ii;//error: expression must be a modifiable lvalue.
//	ri = ii;
//	i = ii;
//}


#endif