#include<iostream>
#include<map>
using std::map;
using std::string;
int main()
{
	map<string,int>word_count;
	word_count["Deutschland"] = 12;
	word_count["Frankreich"] = 18;
	word_count["dungeon"] = 13;
	map<string, int>::const_iterator map_it = word_count.cbegin();
	while (map_it != word_count.cend())
	{
		std::cout << map_it->first << " occurs " <<
			map_it->second << " times" << std::endl;
		++map_it;
	}
}