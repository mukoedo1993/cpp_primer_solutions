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

void elimDups(vector<string>& words)
{
	//sort words alphabetically so we can find the duplicates
	sort(words.begin(), words.end());
	//unique reorders the input range so that eachword appears once
	//in the front portion of the range returns a iterator one past the unique range
	auto end_unique = unique(words.begin(), words.end());
	//erase uses a vector operation to remove the nonunique elements
	words.erase(end_unique, words.end());
}


int main()
{
	vector<string> words1 = { "haha","haha","gougou","gougou" };
	elimDups(words1);
	std::cout << words1.size() << "\n" << words1[0] << endl << words1[1];
}