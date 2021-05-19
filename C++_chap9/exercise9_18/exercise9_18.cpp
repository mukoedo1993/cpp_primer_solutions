#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<fstream>
#include<sstream>
#include<deque>
using std::vector; using std::deque;
using std::deque;

int main()
{
	std::ifstream input("ex9_18i.txt");
	std::ofstream output("ex9_18o.txt");
	std::string str,str1;
	std::deque<std::string>deqs;
	while (getline(input, str))
	{
		std::istringstream Ob1(str);
		while(Ob1>>str1)
		deqs.push_back(str1);
	}
	for (auto it = deqs.begin(); it != deqs.end(); it++)
	{
		output << *it << std::endl;
	}
}
