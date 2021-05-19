#include<iostream>
#include"Strong_sales_data.h"

class NoDefault {
public: 
	NoDefault(const std::string&);
	//additional members follow, but no other constructors.
};
struct A {
	NoDefault my_mem;
};
//A a;//error: cannot synthesize a constructor for A
struct B {
	//B() {}//error: no initializer for b_member
	NoDefault b_member;
};
int main()
{
	Sales_data obj();//ok: but defines a function, not an object
	Sales_data Primer_5th_ed();
	//if (obj.isbn() == Primer_5th_ed.isbn());//error: obj is a function.

	Sales_data obj;//correct way s.t. obj is a default-initialized object
}