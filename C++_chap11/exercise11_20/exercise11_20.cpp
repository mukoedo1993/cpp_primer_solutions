#include<iostream>
#include<map>
#include<utility>
#include<fstream>
#include<iterator>
using std::map;
using std::string;
int main()
{
	std::ifstream input("ex11_20i.txt");
	if (!input.is_open())exit(-1);
	std::ofstream output("ex11_20o.txt");
	std::istream_iterator<string> in_str(input),eof;
	map<string, size_t>word_count;//empty map from string to size_t
	string word;
	while (in_str!=eof)
	{
		auto it=word_count.insert(make_pair(*in_str, 1));
		if (!it.second)
		{
			for (auto &it1 : word_count)//pass by reference here. Otherwise, read-only!!!!!
			{
				if (it1.first == *in_str)
				{
					it1.second++;
					std::cout << "Call! ";
				}

			}
		}
		in_str++;
	}

	for (auto it2:word_count)
	{
		output << "The word " << it2.first << " appears" << it2.second <<( (it2.second > 1) ? " times.\n":" time.\n");
	}
}