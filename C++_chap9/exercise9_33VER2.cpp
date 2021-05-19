#include<iostream>
#include<vector>
#include<list>
#include<forward_list>
using std::list;
using std::forward_list;
using std::vector;
int main()
{
	

	vector<int>v = { 1,1,4,5,6,1 };
	auto begin = v.begin();
	while (begin != v.end()) {
		//do some processing
		++begin;//advance 
		//begin =//exercise9_33:
			v.insert(begin, 42);//Because begin will become invalid after the first time this line runs.
		++begin;
		//Vectors' iterators after the one inserted will all become invalid.
	}
	
	//Error:
	//Exception thrown: read access violation.
	//_Mycont was nullptr.
}