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
#include<cstdlib>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using std::initializer_list;
//calculate val, which is 1*2*3...*val
int factorial(int val)
{
	if (val > 1)
		return (factorial(val - 1) * val);
	return 1;
}
int main()
{
	cout << factorial(5);
}