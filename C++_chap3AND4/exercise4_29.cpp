/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
#include<limits>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string;
int main()
{
	int x[10]; int* p = x;
	cout << sizeof(x) / sizeof(*x) << endl;
	cout << sizeof(p) / sizeof(*p) << endl;
	return 0;
}