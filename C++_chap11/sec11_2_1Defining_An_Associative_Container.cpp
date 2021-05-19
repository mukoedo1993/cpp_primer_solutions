#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<string>
using std::map;
using std::string;
using std::set; using std::vector;
using std::multiset;
int main()
{
	map<string, size_t>word_count;//empty
	set<string>exclude = {"the","but","and","or","an","a"
	                       ,"The","But","And","Or","An","A"
	};
	//three elements(list initializer)
	//authors map last name to first
	map<string, string>authors = { {"Yc","M"},{"Enoshima","Junko"},{"ZC","W"} };
	//{key,value}

	//Define a vector with 20 elements, holding two copies of each number from 0 to 9
	vector<int>ivec;
	for (vector<int>::size_type i = 0;i!=10;++i)
	{
		ivec.push_back(i);
		ivec.push_back(i);
	}
	set<int>iset(ivec.begin(), ivec.end());
	multiset<int>multi_iset(ivec.begin(), ivec.end());
	std::cout << "The size for vector is:" << ivec.size() << std::endl;//20
	std::cout << "The size for set is:" << iset.size()<<std::endl;//10
	std::cout << "The size for multiset is:" << multi_iset.size() << std::endl;//20
	/*
	*Even though we initialized iset from the entire ivec container, iset has only ten 
	*elements; one for each distinct element in ivec. On the other hand, multi_set has 20 
	*elements. the same as the number of elements in ivec.
	*/


}