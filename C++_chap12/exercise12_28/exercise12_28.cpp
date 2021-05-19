#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<sstream>
#include<memory>
using std::shared_ptr;
using std::vector; using std::map;
using std::set;
using std::ifstream;
#include<string>
using std::string;


std::ostream& print(std::ostream& os, map<string, set<unsigned>>sptr)
{


	for (auto it : sptr)
	{
		os << it.first << " appears in: ";
		for (auto it1 : it.second)
			os << it1 << " ";
	}

	return os;
}

int main()
{
	std::ifstream input("ex12_28i.txt");
	vector<string>txt = { "" };//0 line
	map<string, set<unsigned>>line_NO;

	string str;
	while (getline(input, str))
	{
		string str2;
		txt.push_back(str);
		std::istringstream Ob1(str);
		while (Ob1 >> str2)
			line_NO[str2].insert(txt.size() - 1);
	}
	while (true)
	{
		std::cout << "Please print an element to find or q to quit: ";
		if (!(std::cin >> str) || str == "q")break;
		set<unsigned> mapped = line_NO[str];
		map<string, set<unsigned>>map1;
		map1[str] = mapped;
		print(std::cout, map1) << std::endl;
	}
	
}