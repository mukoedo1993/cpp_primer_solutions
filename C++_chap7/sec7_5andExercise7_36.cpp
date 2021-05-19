#include<iostream>
#include<vector>
#include"Sec7_5.h"
//

//exercise 7_36:
struct X_1 {
	X_1(int i, int j) :rem(j), base(i) { rem = rem % base; }
	int rem, base;
};
/*
*
*
*
*
*
*/


int main()
{//test: exercise: 7.36:
	X_1 Ob1(4, 13);
	std::cout << Ob1.rem << "! " << Ob1.base << std::endl;
	std::string foo = "Hello World!";//define and initialize
	std::string bar;//default initialized to the empty string
	bar = "Hello World!";//assign a new value to bar

	std::vector<ConstRef::Tt1>kk = { ConstRef::Tt1(12) };
	//I modify the codes below by myself.

	for (int cn = 0; cn < 10; cn++)
	{
		kk.push_back(ConstRef::Tt1(cn));
		kk[cn].printTt1();
	}
}
