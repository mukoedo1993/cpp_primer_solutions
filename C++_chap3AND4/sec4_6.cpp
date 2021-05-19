#define _CRT_SECURE_NO_WARNINGS
/*The define above is very important.
Without it,strcat and strcpy will crash.
*/
#include<iostream>
#include<vector>
#include<string>
using std::cin; using std::cout;
using std::endl; using std::vector;
using std::begin; using std::end;
using std::string;
int main()
{
	string s1 = "a string", * p = &s1;
	auto n = s1.size(), n1 = p->size(), n2 = (*p).size();
	if (n == n1 && n1 == n2)
		cout << "n are all same!" << endl;
	//error: *p.size()//p is a pointer and has no member size

}