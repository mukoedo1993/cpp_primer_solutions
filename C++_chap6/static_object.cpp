#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include<limits>
#include"Sales_item.h"
#include"abs_vl.h"
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using std::cerr;

	size_t count_calls()
	{
		static size_t ctr = 0;// value will persist across calls
		return ++ctr;
	}
	int main()
	{
		for (size_t i = 0; i != 10; ++i)
			cout << count_calls() << endl;
     }