#include<vector>
#include<iostream>
#include<string>
#include<numeric>//accumulate
#include<algorithm>
#include<fstream>
#include<sstream>
#include<list>
#include"elims_printPAC.h"
using std::vector;
using std::list;
using std::cout;
using std::string; using std::endl;

//comparison function to be used to sort by word length
bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

int main()
{
	std::ifstream input("ex10_11i.txt"); std::ofstream output("ex10_11o.txt");

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

	//vector<string>words1 = words;//keep original data
	output << "For exercise 10_11:\nThe process: \n";
	elimDups(words, output);
	output << endl;
	stable_sort(words.begin(), words.end(), isShorter);
	output << "for exercise 10_11, our result is:\n";
	for (const auto& s : words)
	{
		output << s << "; ";
	}
	output << endl;
	input.close(); output.close();
}