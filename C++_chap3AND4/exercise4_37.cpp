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
	//Part a:
	string ps_1 = "sdhsdhsdhj";
	const string* ps = &ps_1;
	
	int i; double d;  char* pc=&ps_1[3]; void* pv; void* pv1;
	pv = static_cast<void*>(const_cast<string*>(ps));
	// Part b:
	i = reinterpret_cast<int>(pc);
	// part C:
	pv1 = static_cast<void*>(&d);
	//part D:
	pc= static_cast<char*>(pv);
}