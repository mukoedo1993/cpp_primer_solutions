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
	unsigned long ul1 = 3, ul2 = 7;
	unsigned long ul_1, ul_2, ul_3, ul_4;
	ul_1 = ul1 & ul2;
	ul_2 = ul1 | ul2;
	ul_3 = ul1 && ul2;
	ul_4 = ul1 || ul2;
	cout << ul_1 << endl;
	cout << ul_2 << endl;
	cout << ul_3 << endl;
	cout << ul_4 << endl;
	return 0;
}