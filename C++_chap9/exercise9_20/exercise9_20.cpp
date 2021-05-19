#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<list>
using std::list;

int main()
{
	std::ifstream input("ex9_20i.txt");
	std::ofstream output_evn("ex9_20o_even.txt");
	list<int>even; list<int>odd;
	std::ofstream output_odd("ex9_20o_odd.txt");
	std::string str; int str1;
	std::list<int>deqs;
	while (getline(input, str))
	{
		std::istringstream Ob1(str);
		while (Ob1 >> str1)
			deqs.push_back(str1);
	}
	for (auto it = deqs.begin(); it != deqs.end(); it++)
	{
		if (*it % 2 == 0)
		{
			even.push_back(*it);
			output_evn << *it << std::endl;
		}
		else
		{ 
			odd.push_back(*it);
			output_odd << *it << std::endl;
		}
	}
}