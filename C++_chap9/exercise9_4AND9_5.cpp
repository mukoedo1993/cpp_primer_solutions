#include<iostream>
#include<list>
#include<deque>
#include<vector>


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

std::vector<int>::iterator find1(int a, std::vector<int>& ivec)
{

	for (auto it = ivec.begin(); it < ivec.end(); it++)
	{
		if (a == *it)
			return it;
	}
	std::cout << "error! Not find! The first element is:" << std::endl;
	return ivec.begin();
}
int main()
{
	//exercise9_4:
	vector<int>ivec = { 1,2,8,9 };
	int a = 2; int b = 10;
	std::cout << std::boolalpha;
	std::cout << find(a, ivec) << std::endl;
	std::cout << find(b, ivec) << std::endl;
        //exercise 9_5:
	std::cout << *find1(a, ivec) << std::endl;
	std::cout << *find1(b, ivec) << std::endl;
}
