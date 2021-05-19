#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using std::string;
using std::vector;
int main()
{
	vector<string>vstr;
	vector<int>istr; int sum = 0;
	std::ifstream input("ex9_50i.txt");
	if (!input.is_open())return -1;
	std::ofstream output("ex9_50o.txt");
	string str,str1;
	while (getline(input, str))
	{
		std::istringstream Ob1(str);
		while (Ob1 >> str1)
		{
			vstr.push_back(str1);
		}

	}
	for (auto it = vstr.begin(); it != vstr.end(); it++)
	{
		istr.push_back(stod(*it));
		
	}
	for (auto it = istr.begin(); it != istr.end(); it++)
	{
		sum += *it;

	}
	output << "The sum is: " << sum << std::endl;
}