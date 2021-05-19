#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include"exercise9_4.h"

using std::vector;
bool find(int a, std::vector<int>&ivec)
{

	for (auto it = ivec.begin(); it < ivec.end(); it++)
	{
		if (a == *it)
			return true;
	}
	return false;
}
int main()
{
	//exercise9_4:
	vector<int>ivec = { 1,2,8,9 };
	int a = 2; int b = 10;
	std::cout << std::boolalpha;
	std::cout << find(a, ivec) << std::endl;
	std::cout << find(b, ivec) << std::endl;
}