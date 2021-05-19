#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
#include<initializer_list>//  new operations!
#include <system_error>   // std::error_code, std::generic_category
// std::error_condition

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using std::initializer_list;
/*
	Function with no return value.
	*/
void swap (int& v1, int& v2)
{
	if (v1 == v2)
		return;// The use of return is analogous to the use of a break
	          //statement.
	int tmp = v2;
	v2 = v1;
	v1 = tmp;
	//no explicit return necessary
}

int main()
{
	int v1 = 13, v2 = 28;
	swap(v1, v2);
	cout << v1 << "! " << v2 << endl;
}