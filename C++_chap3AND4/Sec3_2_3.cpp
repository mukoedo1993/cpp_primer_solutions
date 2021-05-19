#include<iostream>
#include<string>
#include<vector>
#include "Header1.h"
using std::string;
using std::cout;
using std::endl;
int main()
{
	a1 objct1;
	cout << objct1.a << endl;
	string str("Some things!");
	for (auto c : str)//for every char in str
	{
		cout << c << endl; //printed the follow character 
	}
	std::vector<int> arry1 = { 1,4,6,9,20 };
	for (auto c1 : arry1)
	{
		cout << c1 << endl;
	}
}