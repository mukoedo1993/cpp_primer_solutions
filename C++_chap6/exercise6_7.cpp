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
int exercise6_7()
{
	static int k=0;// It is only used at the first time. 
	//Then, at second, third, fourth... time, k=1,2,3,...,9.
	
	return k++;
}
int main()
{
	for (int i = 0; i < 10; i++)
		std::cout << exercise6_7() << std::endl;
}