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
	/*
	An iterator that points to a vector of strings:
	...
	 if(iterator->empty())...
	 ...
	 if(vector.empty())...
	*/
	vector<string>text = {"Ha","Nmsl","Revenge","","TTk"};
	if (!text.empty())cout << "Ni Ma Si Le!";
	for (auto it = text.begin();!(it->empty());++it)
	{   
		
		cout << *it << endl;
		if (it == text.end() - 1)break;
	}
}