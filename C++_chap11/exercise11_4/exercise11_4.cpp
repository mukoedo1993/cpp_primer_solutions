#include<map>
#include<string>
#include<iostream>
#include<fstream>
#include<iterator>
#include<set>
#include<algorithm>
#include<numeric>

using std::map;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::set;
int main()
{

	std::ifstream input("exercise11_4i.txt");
	if (!input.is_open())return -1;
	std::ofstream output("exercise11_4o.txt");
	std::istream_iterator<string>in_it(input), eof;
	//count the No. of times each word occurs in the input


	//PART 1:
	output << "part 1:\n";
	map<string, size_t>word_count;//empty map from string to size_t
	
	string word;
	while (in_it != eof)
	{
		string word1;
		word = *in_it;
		word.erase(remove_if(word.begin(),word.end(),ispunct),word.end());

		for (auto& cr : word)
		{
			cr=tolower(cr);
		}

		word_count[word]++;
		word.clear();
		in_it++;
	}

	output << "Exercise11_4:\n";
	for (const auto& w : word_count)
	{
		//print the results
		output << w.first << " occurs " << w.second << ((w.second > 1) ? " times." : " time.") << endl;

	}

	

}
