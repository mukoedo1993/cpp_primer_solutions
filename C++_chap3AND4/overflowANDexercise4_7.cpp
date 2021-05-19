#define _CRT_SECURE_NO_WARNINGS
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
using std::string; using std::numeric_limits;
int main()
{
	int a = numeric_limits<int>::max();
	int b = a + 1;
	short c = numeric_limits<short>::max();
	short d = c + 1;
	double e = numeric_limits<double>::max();
	float f = e + 1;//f now is inf.
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl;
	return 0;

}