#include<map>
#include<list>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iterator>
using std::string;
using std::map; using std::list;
int main()
{
	map<string, list<unsigned int>>word_cnt;
	std::ifstream input("ex11_9i.txt");
	if (!input.is_open())exit(-1);
	string str; unsigned int cnt = 1;
	while (getline(input,str))
	{
		std::istringstream Ob1(str);
		while (Ob1 >> str)
		{
			if (find(word_cnt[str].cbegin(), word_cnt[str].cend(), cnt) == word_cnt[str].cend())
				word_cnt[str].push_back(cnt);
			//else;//null statement
		}
		cnt++;
	}
	std::ofstream output("ex11_9o.txt");
	std::ostream_iterator<int>out_it(output, " ");
	for (const auto& w : word_cnt)
	{
		output << "The word: " << w.first << " appears on ";
		copy(w.second.begin(), w.second.end(), out_it);
		output << "line respectively.\n\n";
	}
	output.close(); input.close();
}