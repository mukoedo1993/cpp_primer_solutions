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

std::ostream& print(const vector<string>& words,std::ostream&os)
{
	for (auto it = words.begin(); it < words.end(); it++)
	{
		os  <<*it << "; ";
	}
	os << endl;
	return os;
}

void elimDups(vector<string>& words,std::ostream&os)
{
	
	sort(words.begin(), words.end());
	os << "The sorted words are:\n";
	print(words, os);

	auto end_unique = unique(words.begin(), words.end());
	os << "After put all repeated words at the end:\n";
	print(words, os);

	words.erase(end_unique, words.end());
	os << "Then,delete all repeated words:\n";
	print(words, os);
}

int main()
{
	std::ifstream input("ex10_9i.txt"); std::ofstream output("ex10_9o.txt");

	if (!input.is_open())return -1;

	string str; vector<string>ex10_9v;
	while (getline(input, str))
	{
		std::istringstream Ob1(str); string str2;
		while (Ob1 >> str2)
		{
			ex10_9v.push_back(str2);
		}
	}
	elimDups(ex10_9v, output);
	input.close();
	output.close();
}