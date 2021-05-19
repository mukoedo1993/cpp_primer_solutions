#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string;
int main()
{
	//disaster: extra semicolon: loop body is this null statement
	/*
	while (iter != svec.end());
	iter++;
	*/

}