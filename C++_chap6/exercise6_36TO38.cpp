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
string(&exercise6_36())[10]
{
	string i1[] = {"i1","i2","i3","i4","i5","i6","i7","i8","i9","i10"};
for(int i2=0;i2<10;i2++)
cout << i1[i2]<<endl;
return i1;
}
//trailing return:
auto exercise6_37_1()->string(&) [10]
{
	string i1[] = {"i1","i2","i3","i4","i5","i6","i7","i8","i9","i10"};
for (int i2 = 0; i2 < 10; i2++)
cout << i1[i2] << endl;
return i1;
}
//decltype:
string odd[10] = {};
decltype (odd)(&exercise6_37_2())
{
	string i1[] = {"i1","i2","i3","i4","i5","i6","i7","i8","i9","i10"};
for (int i2 = 0; i2 < 10; i2++)
cout << i1[i2] << endl;
return i1;
}
//type alias:
using tp_ls = string[10];
tp_ls(&exercise6_37_3())
{
	string i1[] = { "i1","i2","i3","i4","i5","i6","i7","i8","i9","i10" };
	for (int i2 = 0; i2 < 10; i2++)
		cout << i1[i2] << endl;
	return i1;
}
//exercise 6.38:
int odd114[] = { 1,3,5,7,9 };
int even114[] = { 2,4,6,8,10 };
//We use decltype to slove the problem here:
auto arrPtr_1(int i)->int(&)[5]
{
	return ((i % 2) ? odd114 : even114);
}
int main()
{
	exercise6_36();
	exercise6_37_1();
	exercise6_37_2();
	exercise6_37_3();
	cout<<arrPtr_1(3)[2];
}