#include<vector>
#include<iostream>
#include<string>
#include<numeric>//accumulate
#include<algorithm>
#include<fstream>
#include<sstream>
#include<list>
using std::vector;
using std::list;
using std::cout;
using std::string; using std::endl;

//http://www.cplusplus.com/reference/algorithm/partition/

bool large_then_5(const string&a)
{
	return a.size() >= 5;
}

//The return value of partition function:

int main()
{
	std::ifstream input("ex10_13i.txt"); std::ofstream output("ex10_13o.txt");

	if (!input.is_open())return -1;
	
	string str; vector<string>words;
	while (getline(input, str))
	{
		std::istringstream Ob1(str); string str2;
		while (Ob1 >> str2)
		{
			words.push_back(str2);
		}
	}
	input.close();
	output << "The result for exercise 10_13:\n";
	auto start_smaller = partition(words.begin(), words.end(), large_then_5);
	for (auto it = words.begin(); it < start_smaller; it++)
		output << *it << "; ";
	output << endl;
	 output.close();
}