#include<set>
#include<iostream>
#include<map>
#include<iterator>
#include<utility>
using std::set; using std::multimap;
using std::map; using std::string;
using std::pair;
int main()
{
	//If we just want to find whether an element exists, it's best to use find.
	set<int>iset = { 0,1,2,3,4,5,6,7,8,9 };
	set<int>::iterator it1 = iset.find(1);//returns an iterator that refers to the element with key==1
	std::cout << *it1 << std::endl;

	set<int>::iterator it2 = iset.find(11);//returns the iterator ==iset.end()
	std::cout << std::boolalpha;
	std::cout << (it2 == iset.end()) << std::endl;

	std::cout << iset.count(1) << std::endl;//result:1
	std::cout << iset.count(11) << std::endl;//result:0

	map<string, int>word_count;
	if (word_count.find("foobar") == word_count.end())
		std::cout << "foolbar is not in the map" << std::endl;

	multimap<string, string>authors;
	authors.insert(make_pair(string("Tom"), string("Sam")));
	authors.insert(make_pair(string("Tom"), string("Sam1")));
	authors.insert(make_pair(string("Tom"), string("Sam2")));
	authors.insert(make_pair(string("Tom"), string("Sam3")));
	authors.insert(make_pair(string("Zich"), string("Kam")));
	authors.insert(make_pair(string("Zich"), string("Kam1")));
	authors.insert(make_pair(string("Zc"), string("Kam2")));
	authors.insert(make_pair(string("Zk"), string("Kam3")));
	string search_Item("Tom");
	auto entries = authors.count(search_Item);//first entry 
	std::cout << "entries' type is: " << typeid(entries).name() << std::endl << std::endl << std::endl;//type: unsigned int
	auto iter = authors.find(search_Item);//It returns to the (first) element with key k, or off-the-end
	//iterator if k is not in the container

	//loop through the number of entries there are for this author
	while (entries)
	{
		std::cout << iter->second << std::endl;//print each title
		++iter;//advanced to the next title
		--entries;//keep track of how many we've printed
	}

	//definitions of authors and search_item as above
	//beg and end denote the range of elements for this author
	string search_Item1("Zich");
	for (auto beg = authors.lower_bound(search_Item1)
		, end = authors.upper_bound(search_Item1);
		beg != end; ++beg)
	{
		std::cout << beg->second << std::endl;//print each title
		//Result: Kam/nKam1
	}

	//The equal range function: 
	//definitions of authors and search_item as above
	//pos holds iterators that denote the range of elements for this key

	for (pair<multimap<string, string>::const_iterator, multimap<string, string>::const_iterator>
		pos = authors.equal_range(search_Item1);
		pos.first != pos.second; ++pos.first)
	{
		std::cout << pos.first->second << std::endl;//returns Kam/nKam1
		auto it_mkft = pos.first;
		it_mkft++;
		if (it_mkft == pos.second)
			std::cout << "pos.second->second equals: " << pos.second->second;//returns Kam3/n
	}

}