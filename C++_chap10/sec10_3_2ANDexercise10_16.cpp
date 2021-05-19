#include<vector>
#include<iostream>
#include<string>
#include<numeric>//accumulate
#include<algorithm>
#include<fstream>
#include<sstream>
#include<list>
#include"elims_printPAC_ver1_1.h"
using std::vector;
using std::list;
using std::cout;
using std::string; using std::endl;


void biggies(vector<string>& words, vector<string>::size_type sz)
{
	elimDups(words);//put words in alphabetical order and remove duplicates
	//reset by length, maintaining alphabetical order among words of the same length
	stable_sort(words.begin(), words.end(),[] 
	(const string&a1,const string & a2) {return a1.size() < a2.size();});
	
	auto wc = find_if(words.begin(), words.end(), [sz](const string& a)
		{return a.size() >= sz; });
	
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << " of length "<<sz<<" or longer "
		<<endl;
	for_each(wc, words.end(), [](const string& s) {cout << s << " "; });
	cout << endl;
	cout << endl;
}



/*1: We can pass any kind of callable object to an algorithm. An object or expression 
*is callable if we can apply the call operator to it. That is, if e is a callable if
*we can apply the call operator to it.
*/



int main()
{
	

	//preparation:
	
	std::ifstream input("sec10_3_2i.txt"); std::ofstream output("sec10_3_2o.txt");
	
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

	vector<string>  words1  = words;

	//lambda expression:

	auto f= []()->int {return 42; };
	auto f1 = [] {return 42; };//f and f1 are equivalent
	cout << f() << "; " << f1() << endl;

	//another isShorter function
	auto isShorterLambda = [](const string& a1, const string& a2) {return a1.size() < a2.size(); };
	stable_sort(words.begin(), words.end(),
		[](const string& a1, const string& a2) {return a1.size() < a2.size(); });
	output << "part 1: isShorterLambda\n";
	print(words, output);

	//part 2: Using the Capture list:
	int sz = 3;
	auto isLargerLambda=[sz](const string& a) {return a.size() > sz; };

	//error: sz not captured
	//auto isLargerLambda = [](const string& a) {return a.size() > sz; };

	//e.g.1: calling find_if:
	auto wc = find_if(words.begin(), words.end(), isLargerLambda);
	output << "part 2: the first element whose size is larger than " <<sz<<": " << *wc << endl;

	auto count =  words.end()-wc;
	output << count << " " << make_plural(count, "word", "s") << " larger than " << sz << "" << endl;

	//e.g.2: for_each algorithm
    //This algorithm takes a begin and a end, and a callable object and calls that object in the input page:
	cout << "for each algorithm:\n";
	for_each(wc, words.end(), [](const string& s) 
		{cout << s << " "; });

	cout << endl;




	//exercise 10_16:
	cout << "biggies:\n ";
	biggies(words1, sz);
	cout << "test for exericse 10_16:\n"; int k = 4;
	vector<string> words114 = { "nima","sile","touliang","lul","sdjfhf","ad","fdhfh" };
	size_t size1 = 3;
	auto biggies_DIY = [size1](vector<string>& words)
	{
		elimDups(words);//put words in alphabetical order and remove duplicates
		//reset by length, maintaining alphabetical order among words of the same length
		stable_sort(words.begin(), words.end(), []
		(const string& a1, const string& a2) {return a1.size() < a2.size(); });

		auto wc = find_if(words.begin(), words.end(), [size1](const string& a)
			{return a.size() >= size1; });

		auto count = words.end() - wc;
		cout << count << " " << make_plural(count, "word", "s") << " of length " << size1 << " or longer "
			<< endl;
		for_each(wc, words.end(), [](const string& s) {cout << s << " "; });
		cout << endl;
		cout << endl;
	};
	biggies_DIY(words114);
}


