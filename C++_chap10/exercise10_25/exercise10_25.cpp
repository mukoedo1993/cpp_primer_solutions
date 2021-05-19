#include<vector>
#include<iostream>
#include<string>
#include<numeric>//accumulate
#include<algorithm>
#include<fstream>
#include<sstream>
#include<list>
#include"elims_printPAC_ver1_1.h"
#include<functional>
using std::vector;
using std::list;
using std::cout;
using std::string; using std::endl;
using std::placeholders::_1;



bool large_then_5(const string& a)
{
	return a.size() >= 5;
}

bool check_size(const int i, const string& s2)
{
	if (i < s2.size())return true;
	else return false;
}

void biggies(vector<string>& words, vector<string>::size_type sz)
{
	elimDups(words);//put words in alphabetical order and remove duplicates
	//reset by length, maintaining alphabetical order among words of the same length
	stable_sort(words.begin(), words.end(), []
	(const string& a1, const string& a2) {return a1.size() < a2.size(); });

	//auto wc = partition(words.begin(), words.end(), [sz](const string& a)
		//{return a.size() < sz; });

	auto count = count_if(words.begin(), words.end(), bind(check_size, sz, _1));


	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer "
		<< endl;
	for_each(words.begin(), words.end(), [=](const string& s) 
		{if(s.size()>sz)
		cout << s << " "; 
		});
	cout << endl;
	cout << endl;
}

int main()
{
	std::ifstream input("ex10_25i.txt");

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
	cout << "The result for exercise 10_25:\n";
	vector<string>::size_type ex10_25i = 8;
	biggies(words, ex10_25i);
	cout << endl;

}