/*As one example,a ssume that we want to print the vector after we call. However, we'll also assume
* that we want to see  the words ordered by their size, and then alphabetically within each size. To
* reorder the vector by length, we'll use a second, overloaded version of sort. This version of sort takes
*a thrid argument that is a predicate.
*/

//predicate:
/*
*A predicate is an expression that can be called and returns a value that can be used as a condition.
*1: The predicates used by library algorithms are either unary predicates(meaning they have a single 
parameter) or binary predicates (meaning that they have two parameters).
*2:The algorithms that take predicates call the given predicate on the elements in the input range.
*3:element type--convert to-->parameter type of the predicate: must possible
*
*/
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

//part1:http://www.cplusplus.com/reference/algorithm/sort/
//part2: http://www.cplusplus.com/reference/algorithm/stable_sort/

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



//comparison function to be used to sort by word length
bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}
//sort on word length, shortest to longest
//sort(first, last,comp)

/*compo
*Binary function that accepts two elements in the range as arguments, and returns a value convertible to bool. 
The value returned indicates whether the element passed as first argument is considered to go
before the second in the specific strict weak ordering it defines.
*The function shall not modify any of its arguments.
*This can either be a function pointer or a function object.
*/

int main()
{
	

	std::ifstream input("sec10_3_1i.txt"); std::ofstream output("sec10_3_1o.txt");

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

	vector<string>words1 = words;//keep original data

	sort(words.begin(), words.end(), isShorter);


	output << "For the sort that takes a binary predicates:\n";
	for (const auto& it:words)
	{
		output << it << "; ";
	}
	output << std::endl << std::endl;
	//part 2:stable_sort:
	//A stable_sort remain the original order among equal elements.

	output<< "For the stable_sort that takes a binary predicates:\n";
	elimDups(words1);//put words in alphabetical order and remove by length
	stable_sort(words1.begin(), words1.end(), isShorter);
	for (const auto& s : words1)//no need to copy the strings
	{
		output << s << "; ";
	}
	output<< endl;
}