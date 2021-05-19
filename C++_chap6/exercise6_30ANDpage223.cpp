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
bool str_subrange(const string& str1, const string& str2)
{
	//same sizes: return normal equality test
	if (str1.size() == str2.size())
		return str1 == str2;//ok: returns bool
	auto size = (str1.size() < str2.size())
		? str1.size() : str2.size();
	//look at each element up to the size of the smaller string
	for (decltype(size)i = 0; i != size; ++i)
	{
		if (str1[i] != str2[i])
			return;//eeror#1: no return value;compiler should detect this error
	}
	//error#2: control might flow off the end of the function without a return
	//the compiler might not detect this error
}
int main()
{

}