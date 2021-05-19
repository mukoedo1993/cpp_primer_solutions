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

struct TextQuery
{
	vector<string>txt = {""};//0 line
	map<string, set<unsigned>>line_NO;
	shared_ptr<map<string, set<unsigned>>> sptr;
	TextQuery(std::istream& is)
	{
		string str;
		while (getline(is, str))
		{
			string str2;
			txt.push_back(str);
			std::istringstream Ob1(str);
			while (Ob1 >> str2)
				line_NO[str2].insert(txt.size() - 1);
		}
	}
	map<string, set<unsigned>> query(const string &s)
	{
		map<string, set<unsigned>>map1;
		set<unsigned>mkft1 = line_NO[s];
		map1[s] = mkft1;
		return map1;
	}
};

struct QueryResult {
	QueryResult(TextQuery& in)
	{
		sptr_rslt = in.sptr;

	}
	shared_ptr<map<string, set<unsigned>>>sptr_rslt;

};

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
void runQueries(std::istream& infile)
{
	//infile is an ifstream that is the file we want to query
	TextQuery tq(infile);//store the file and build the query map
	while (true) {
		std::cout << "enter word to look for, or q to quit: ";
		string s;
		//stop if we hit end-of-file on the input or if a 'q'is entered.
		if (!(std::cin >> s) || s == "q")break;
			//run the query and print the results.
			print(std::cout, tq.query(s)) << std::endl;
	}
}

int main()
{
	ifstream input("ex12_27i.txt");
	if(!input.is_open())exit(-1);
	runQueries(input);

}