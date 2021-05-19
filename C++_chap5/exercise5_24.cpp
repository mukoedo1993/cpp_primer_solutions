#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"Sales_item.h"

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using std::cerr;
int main()
{
	int i1 = 10, i2 = 0,i3;
	switch (i2)
	{
	case 0: cerr << "Error..."; return -1;
	default: cout << i1 + i2 << endl;
	}
}