#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<list>
using std::list;

int main()
{
	std::ifstream input("ex9_19i.txt");
	std::ofstream output("ex9_19o.txt");
	std::string str, str1;
	std::list<std::string>deqs;
	while (getline(input, str))
	{
		std::istringstream Ob1(str);
		while (Ob1 >> str1)
			deqs.push_back(str1);
	}
	for (auto it = deqs.begin(); it != deqs.end(); it++)
	{
		output << *it << std::endl;
	}
}