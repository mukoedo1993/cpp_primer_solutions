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
	vector<int>v = { 1,3,5,6,74,3,45,6 };
	auto pbeg = v.begin();
	//print elements up to the 1st negative value
	while (pbeg != v.end() && *pbeg >= 0)
		cout << *pbeg++ << endl;//[print the current value and advance pbeg
	for (auto it = v.begin(); it != v.end() && !isspace(*it); ++it)
	{
		*it = toupper(*it);//capitalize the current character
	}
	/*
      the behavior of the following loop is undefined
	  while(beg!=s.end()&&!isspace(*beg))
	  *beg=toupper(*beg++);//error: this assignment is undefined
	*/
}