#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using std::string;

int main()
{
	string result;
	string ascender("df");
	string descender("pg");
	std::ifstream input("ex9_49i.txt");
	std::ofstream output("ex9_49o.txt");
	string str;
	while (getline(input, str))
	{
		std::istringstream Ob1(str);
		while (Ob1 >> str)
		{
			
			if (str.find_first_of(ascender) == string::npos
				&& str.find_first_of(descender) == string::npos)
			{
				if (result.size() < str.size())
					result = str;
			}
			else;//null statement
				
		}
	}
	output << "Target: find the largest word without d,f,p or g:\n";
	output << "The longest word that fits both requirements is: " << result;
}