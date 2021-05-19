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
int odd[] = { 1,3,5,7,9 };
int even[] = { 2,4,6,8,10 };
decltype(odd)* arrPtr(int i)
{
	return (i % 2) ? &odd : &even;
}
int main()
{
	for (int i = 0; i < 5; i++)
	{
		cout << (*arrPtr(i))[i]<<endl;
	}
	//returns a pointer to ana array of five int elements

}