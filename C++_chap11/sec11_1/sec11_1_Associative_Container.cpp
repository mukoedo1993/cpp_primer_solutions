#include<map>
#include<string>
#include<iostream>
#include<fstream>
#include<iterator>
#include<set>
using std::map;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::set;
int main()
{

	std::ifstream input("sec11_1i.txt");
	if (!input.is_open())return -1;
	std::ofstream output("sec11_1o.txt");
	std::istream_iterator<string>in_it(input),eof;
	//count the No. of times each word occurs in the input


	//PART 1:
	output << "part 1:\n";
	map<string, size_t>word_count;//empty map from string to size_t
	auto word_count1 = word_count;//prepare for the part 2.
	string word;
	while (in_it != eof)
	{
		word = *in_it;
		word_count[word]++;
		in_it++;
	}
	for (const auto& w : word_count)
	{
		//print the results
		output << w.first << " occurs " << w.second <<( (w.second > 1) ? " times." : " time.")<<endl ;
		
	}

	//PART 2:
	input.close();
	input.open("sec11_1i.txt");
	set<string>exclude = { "Los","Angeles","India" };
	
	std::istream_iterator<string> in_it1(input);
	while (in_it1 != eof)
	{
		if (exclude.find(*in_it1) == exclude.end())
			word_count1[*in_it1]++;
		in_it1++;
	}
	output << "\n\npart 2:\n";
	//Using a set:
	
	for (const auto& w : word_count1)
	{
		//print the results
		output << w.first << " occurs " << w.second << ((w.second > 1) ? " times." : " time.") << endl;

	}

	output << "Note: Notice that we excluede:Los,Angeles,India\n";

	 output.close();
}