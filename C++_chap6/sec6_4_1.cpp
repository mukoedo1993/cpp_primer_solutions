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
//void print(const string&)
//{
	//return(string.empty());
//}
void foodBar(int ival)
{
	bool read = false;//new scope: hides the outer declaration of read
	//string s = read();

}
void print(double t)
{
	cout <<t<<endl;
}
void print(int t)
{
	auto t1 = static_cast<int>(t);
	cout << t1;
}
int main()
{
	double v1 = 3.14;
	void print(int);//new scope, hides the outer declration
	print(v1);//the result is 3.
}