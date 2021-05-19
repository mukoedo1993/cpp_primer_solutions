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
int sum_up(initializer_list<int> ilists)
{
	int sum = 0;
	for (auto beg = ilists.begin(); beg != ilists.end(); beg++)
		sum += *beg;
	return sum;
}
int main()
{
	initializer_list<int> int_list = { 2,10,12,34,89,-50 };
	cout << sum_up(int_list);
}