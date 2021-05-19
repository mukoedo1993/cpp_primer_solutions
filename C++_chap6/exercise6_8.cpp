#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
#include"chapter6.h"
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string;
int main()
{
	t objct1;
	cout << objct1.f() << endl;
	objct1.f2();
	cout<<objct1.calc(19, 7)<<endl;
	cout<<objct1.square(8.67)<<endl;
}
