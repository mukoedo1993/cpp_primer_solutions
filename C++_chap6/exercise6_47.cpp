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
#include<cassert>
//#define NDEBUG
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string; using std::initializer_list;
int& vint_out(vector<int>& vint)
{
	static int i = 0;
	int a = vint.size();
	if (i < a-2) {
		
		return vint[i++]; 
}
	else
	{
		return a;
	}
	
	
}
int main()
{
	vector<int>vint1 = { 2,12,13,24,86 };
	for(int i=0;i<5;i++)
	cout<<vint_out(vint1)<<endl;
}